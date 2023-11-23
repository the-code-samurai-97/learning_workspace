//
// Created by sibi on 11/23/23.
//

#include <iostream>

#include <opencv2/opencv.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

void pcdToImage(const std::string& input_file, const std::string& output_file) {
  // Load the PCD file
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(input_file, *cloud) == -1) {
    std::cerr << "Failed to load PCD file." << std::endl;
    return;
  }

  int min_x = INT_MAX;
  int max_x = INT_MIN;
  int min_y = INT_MAX;
  int max_y = INT_MIN;

  for (const auto& pt : *cloud) {
    min_x = std::min(min_x, static_cast<int>(pt.x));
    min_y = std::min(min_y, static_cast<int>(pt.y));
    max_x = std::max(max_x, static_cast<int>(pt.x));
    max_y = std::max(max_y, static_cast<int>(pt.y));
  }
  std::cout << "  MIN x " << min_x << " y " << min_y << " MAX x " << max_x << " y " << max_y << std::endl;
  // Extract XYZ coordinates from the point cloud
  const float resolution = 0.1;
  const int width = (10 + max_x - min_x) / resolution;
  const int height = (10 + max_y - min_y) / resolution;
  cv::Mat image(width, height, CV_8UC3, cv::Scalar(255, 255, 255));
  //   for (size_t y = 0; y < cloud->height; ++y) {
  //     for (size_t x = 0; x < cloud->width; ++x) {
  //       int x_px = static_cast<int>((pt.x - min_x) / static_cast<double>(max_x - min_x));
  //       int y_px = static_cast<int>((pt.y - min_y) / static_cast<double>(max_y - min_y));
  //       cv::Vec3b& intensity = image.at<cv::Vec3b>(y_px, x_px);
  //       intensity[0] = static_cast<uint8_t>(255);
  //       intensity[1] = static_cast<uint8_t>(255);
  //       intensity[2] = static_cast<uint8_t>(255);
  //     }
  //   }
  std::cout << "image size: cols" << image.cols << " Rows " << image.rows << "\n";
  for (const auto& pt : *cloud) {
    double x_px = (pt.x - min_x) / resolution;
    double y_px = (pt.y - min_y) / resolution;
    std::cout << " x" << x_px << " " << y_px << "\n";
    cv::Vec3b& intensity = image.at<cv::Vec3b>(static_cast<int>(x_px), static_cast<int>(y_px));
    intensity[0] = static_cast<uint8_t>(pt.intensity);
    intensity[1] = static_cast<uint8_t>(0);
    intensity[2] = static_cast<uint8_t>(0);
  }
  //   // Save the image as a PNG file
  cv::imwrite(output_file, image);
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: ./pcd_to_image input.pcd output.png" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Call the function to convert PCD to image
  pcdToImage(input_file, output_file);

  return 0;
}