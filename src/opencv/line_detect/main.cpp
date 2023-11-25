#include "src/opencv/line_detect/LineFitting.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

// params
float RHO_ = 1.0;
float THETA_ = 0.1;
int THRESHOLD_ = 50;
float srn_ = 0;
float stn_ = 0;
float min_theta_ = 0.0;
float max_theta = 3.5 * CV_PI / 180.0;

cv::Mat Hough_line(const cv::Mat &input_image) {
  cv::Mat input_color;
  cv::cvtColor(input_image, input_color, cv::COLOR_BGR2GRAY);
  //   input_image.convertTo(input_color, cv::COLOR_BGR2GRAY);
  std::cout << " color " << input_color.type() << std::endl;
  //   return input_color;
  cv::Mat output = input_image.clone();
  // Standard Hough Line Transform
  std::vector<cv::Vec2f> lines; // will hold the results of the detection
  cv::HoughLines(input_color, lines, RHO_, THETA_, THRESHOLD_, srn_, stn_,
                 min_theta_,
                 max_theta); // runs the actual detection
  // Draw the lines
  std::cout << " Line size " << lines.size() << std::endl;
  // Sort 'lines' based on the 'x' component
  // std::sort(lines.begin(), lines.end(),
  //           [](const cv::Vec2f &a, const cv::Vec2f &b) {
  //             return a[0] < b[0]; // Compare by 'x' component
  //           });
  static cv::Point previous_pt1(0, 1000);
  static cv::Point previous_pt2(0, -1000);
  for (size_t i = 0; i < lines.size(); i++) {
    float rho = lines[i][0], theta = lines[i][1];
    cv::Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a * rho, y0 = b * rho;
    pt1.x = cvRound(x0 + 1000 * (-b));
    pt1.y = cvRound(y0 + 1000 * (a));
    pt2.x = cvRound(x0 - 1000 * (-b));
    pt2.y = cvRound(y0 - 1000 * (a));
    std::cout << "pt1.x " << pt1.x << "pt1.y " << pt1.y << "\n";
    std::cout << "pt2.x " << pt2.x << "pt2.y " << pt2.y << "\n";
    std::cout << "\n";

    cv::line(output, pt1, pt2, cv::Scalar(255, 0, 255), 1);

    // cv::Point first_point(pt1.x - (pt1.x - previous_pt1.x) / 2.0, pt1.y);
    // cv::Point second_point(pt1.x - (pt1.x - previous_pt2.x) / 2.0, pt2.y);
    // std::cout << "first_point.x " << first_point.x << "first_point.y "
    //           << first_point.y << "\n";
    // std::cout << "second_point.x " << second_point.x << "second_point.y "
    //           << second_point.y << "\n";
    // std::cout << "\n";

    // cv::line(output, first_point, second_point, cv::Scalar(255, 0, 0), 1);
    // previous_pt1 = pt1;
    // previous_pt2 = pt2;
  }
  lines.clear();

  return output;
}
cv::Mat Hough_own_impl(const cv::Mat &input_image) {
  cv::Mat output = input_image.clone();
  cv::Mat input_image2;

  LineFitting line_fitting{input_image.cols, input_image.rows, RHO_,     THETA_,
                           THRESHOLD_,       min_theta_,       max_theta};

  std::vector<cv::Vec2f> lines = line_fitting.FitLine(input_image);

  for (const auto &line : lines) {
    double rho = line[0];
    double theta = line[1];
    cv::Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a * rho, y0 = b * rho;
    pt1.x = cvRound(x0 + 1000 * (-b));
    pt1.y = cvRound(y0 + 1000 * (a));
    pt2.x = cvRound(x0 - 1000 * (-b));
    pt2.y = cvRound(y0 - 1000 * (a));
    cv::line(output, pt1, pt2, cv::Scalar(255, 0, 255), 1);
  }
  return output;
}

int main(int argc, char **argv) {
  // Load the input image

  cv::Mat inputImage = cv::imread("src/line_detect/network_output.png");
  cv::Mat cdst = inputImage.clone();

  cv::cvtColor(inputImage, cdst, cv::COLOR_BGR2GRAY);

  if (inputImage.empty()) {
    std::cerr << "Error: Could not open or find the input image" << std::endl;
    return -1;
  }
  // Display the input image
  cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Input Image", inputImage);

  cv::Mat output_image_Hough = Hough_line(inputImage);

  cv::Mat outputImage_own_impl = Hough_own_impl(cdst);

  cv::namedWindow("output_image_Hough Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("output_image_Hough Image", output_image_Hough);

  cv::namedWindow("outputImage_own_impl Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("outputImage_own_impl Image", outputImage_own_impl);

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}