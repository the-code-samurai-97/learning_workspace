#include "src/opencv/line_detect/LineFitting.hpp"

#include <cstddef>
#include <iostream>
#include <opencv2/core/matx.hpp>

int LineFitting::ComputeNumberOfAngles() const {
  int number_of_angles = ((maximum_theta_ - minimum_theta_) / theta_step_) + 1;

  if (number_of_angles > 1 &&
      std::fabs(M_PI - static_cast<float>(number_of_angles - 1) * theta_step_) <
          theta_step_ / 2.0F) {
    --number_of_angles;
  }
  return number_of_angles;
}

int LineFitting::ComputeNumberOfRhos() const {
  int number_of_rhos = static_cast<int>(roundf(
      static_cast<float>((maximum_rho_ - mininmum_rho_) + 1.0F) / rho_step_));
  return number_of_rhos;
}

void LineFitting::createTrignometryTable() {
  float angle{minimum_theta_};
  const float irho = 1.0F / rho_step_;

  for (int n = 0; n < number_of_angles_; angle += theta_step_, ++n) {
    table_sin_angle_[n] = sinf(angle) * irho;
    table_cos_angle_[n] = cosf(angle) * irho;
  }
}
void LineFitting::FillAccumulator(const cv::Mat &input_image) {
  std::vector<cv::Point> non_zero_coordinates;
  non_zero_coordinates.reserve(cv::countNonZero(input_image));
  cv::findNonZero(input_image, non_zero_coordinates);

  for (const auto &non_zero_point : non_zero_coordinates) {
    const auto col = static_cast<int>(non_zero_point.x);
    const auto row = static_cast<int>(non_zero_point.y);

    for (int n = 0; n < number_of_angles_; ++n) {
      const int r = static_cast<int>(
          roundf(col * table_cos_angle_[n] + row * table_sin_angle_[n]));  // +
      // static_cast<int>((number_of_rhos_ - 1) * 0.5F);
      const int index = (n + 1) * (number_of_rhos_ + 2) + r + 1;
      acummulator_[index] += 1;
    }
  }
}
void LineFitting::FindLocalMaximuma() {
  for (int num_of_rho = 0; num_of_rho < number_of_rhos_; ++num_of_rho) {
    for (int num_of_angle = 0; num_of_angle < number_of_angles_;
         ++num_of_angle) {
      const int base =
          (num_of_angle + 1) * (number_of_rhos_ + 2) + num_of_rho + 1;

      if (acummulator_[base] > threshold_ &&
          acummulator_[base] > acummulator_[base - 1] &&
          acummulator_[base] >= acummulator_[base + 1] &&
          acummulator_[base] > acummulator_[base - number_of_rhos_ - 2] &&
          acummulator_[base] >= acummulator_[base + number_of_rhos_ + 2]) {
        sort_buf_.emplace_back(base);
      }
    }
  }
}
std::vector<cv::Vec2f> LineFitting::FitLine(const cv::Mat &input_image) {
  acummulator_.reserve((number_of_angles_ + 2) * (number_of_rhos_ + 2));
  sort_buf_.reserve(number_of_rhos_ * number_of_angles_);
  std::vector<cv::Vec2f> lines;
  acummulator_.clear();
  sort_buf_.clear();

  if (input_image.type() != CV_8U) {
    return lines;
  }

  FillAccumulator(input_image);
  FindLocalMaximuma();

  std::cout << "lines fitiing size " << sort_buf_.size() << "\n";

  const float scale = 1.0F / static_cast<float>(number_of_rhos_ + 2.0F);

  lines.reserve(sort_buf_.size());

  for (const auto &line_index : sort_buf_) {
    const int n = static_cast<int>((line_index * scale)) - 1;
    const int r = line_index - (n + 1) * (number_of_rhos_ + 2) - 1;
    const double rho = (r - (number_of_rhos_ - 1) * 0.5f) * rho_step_;
    const double angle = minimum_theta_ + n * theta_step_;
    lines.emplace_back(cv::Vec2f{rho, angle});
  }
  return lines;
}
