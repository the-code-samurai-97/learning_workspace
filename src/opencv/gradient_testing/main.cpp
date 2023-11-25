#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
  // Read the input image
  cv::Mat inputImage = cv::imread("src/opencv/gradient_testing/new_paint_inter_linear.png");

  // Check if the image is loaded successfully
  if (inputImage.empty()) {
    std::cerr << "Error: Unable to read the image." << std::endl;
    return -1;
  }

  // Convert the image to grayscale
  cv::Mat grayscaleImage;
  cv::cvtColor(inputImage, grayscaleImage, cv::COLOR_BGR2GRAY);


//  void cv::Sobel	(	InputArray 	src,
//                 OutputArray 	dst,
//                 int 	ddepth,
//                 int 	dx,
//                 int 	dy,
//                 int 	ksize = 3,
//                 double 	scale = 1,
//                 double 	delta = 0,
//                 int 	borderType = BORDER_DEFAULT
//                 )
  // Apply Sobel filter
  cv::Mat sobelX, sobelY;
  cv::Sobel(grayscaleImage, sobelX, CV_16S, 1, 0, 5);
  cv::Sobel(grayscaleImage, sobelY, CV_16S, 0, 1, 3);

  // Convert back to 8-bit unsigned integers
  cv::Mat sobelXAbs, sobelYAbs;
  cv::convertScaleAbs(sobelX, sobelXAbs);
  cv::convertScaleAbs(sobelY, sobelYAbs);

  // Combine the X and Y gradients
  cv::Mat sobelImage;
  cv::addWeighted(sobelXAbs, 0.5, sobelYAbs, 0.5, 0, sobelImage);

  // Display the original and Sobel filtered images
  cv::namedWindow("Original Image", cv::WINDOW_NORMAL);
  cv::imshow("Original Image", inputImage);

  cv::namedWindow("Sobel Filtered Image", cv::WINDOW_NORMAL);
  cv::imshow("Sobel Filtered Image", sobelImage);

  cv::waitKey(0);

  return 0;
}
