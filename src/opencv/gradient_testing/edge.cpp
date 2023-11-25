//
// Created by sibi on 12/26/23.
//

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int edgeThresh = 1;
int edgeThreshScharr = 1;
int edgeSobelThresholdX = 1;
int edgeSobelThresholdY = 1;
int edgeLaplacian = 1;
cv::Mat image, gray, blurImage, edge1, edge2,edge3, cedge;
const char* window_name1 = "Edge map : Canny default (Sobel gradient)";
const char* window_name2 = "Edge map : Canny with custom gradient (Scharr)";
const char* window_name3 = "Edge map : Sobel";
const char* window_name4 = "Edge map : Laplacian";

cv::Mat SobelFiltering(const cv::Mat& grayscaleImage,int threshold_x,int threshold_y)
{
  cv::Mat sobelX, sobelY;
  cv::Sobel(grayscaleImage, sobelX, CV_16S, 1, 0, 2*threshold_x + 1);
  cv::Sobel(grayscaleImage, sobelY, CV_16S, 0, 1, 2*threshold_y + 1);

  // Convert back to 8-bit unsigned integers
  cv::Mat sobelXAbs, sobelYAbs;
  cv::convertScaleAbs(sobelX, sobelXAbs);
  cv::convertScaleAbs(sobelY, sobelYAbs);

  // Combine the X and Y gradients
  cv::Mat sobelImage;
  cv::addWeighted(sobelXAbs, 0.5, sobelYAbs, 0.5, 0, sobelImage);
  return sobelImage;
}

// define a trackbar callback
static void onTrackbar(int, void*)
{
  // Run the edge detector on grayscale
  cv::Canny(image, edge1, edgeThresh, edgeThresh * 3, 3);
  cedge = cv::Scalar::all(0);
  image.copyTo(cedge, edge1);
  cv::imshow(window_name1, cedge);

  cv::Mat dx, dy,result;
  cv::Scharr(image, dx, CV_16S, 1, 0);
  cv::Scharr(image, dy, CV_16S, 0, 1);
  cv::addWeighted(dx, 0.5, dy, 0.5, 0, result);

//  cv::Canny(dx, dy, edge2, edgeThreshScharr, edgeThreshScharr * 3);
//
//  cedge = cv::Scalar::all(0);
//  image.copyTo(cedge, edge2);
  cv::imshow(window_name2, result);


  edge3 = SobelFiltering(image,edgeSobelThresholdX,edgeSobelThresholdY);
  cedge = cv::Scalar::all(0);
  image.copyTo(cedge, edge3);
  cv::imshow(window_name3, edge3);

  cv::Mat result_laplacian;
  cv::Laplacian(image,result_laplacian,CV_16S,2*edgeLaplacian + 1);
  cv::imshow(window_name4, result_laplacian);

}

int main(int argc, const char** argv)
{
  image = cv::imread("src/opencv/gradient_testing/new_paint_inter_nearest_.png", cv::IMREAD_COLOR);
  if (image.empty())
  {
    std::cout<<"Cannot read image file:\n";
    return -1;
  }
  cedge.create(image.size(), image.type());
  cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

  cv::namedWindow("Original Image", cv::WINDOW_NORMAL);
  cv::imshow("Original Image", image);

  // Create a window
  cv::namedWindow(window_name1, 1);
  cv::namedWindow(window_name2, 1);
  cv::namedWindow(window_name3,1);
//  cv::namedWindow(window_name4,1);
  // create a toolbar
  cv::createTrackbar("Canny threshold default", window_name1, &edgeThresh, 10, onTrackbar);
  cv::createTrackbar("threshold Scharr", window_name2, &edgeThreshScharr, 10, onTrackbar);
  cv::createTrackbar("threshold Sobel X ", window_name3, &edgeSobelThresholdX, 10, onTrackbar);
  cv::createTrackbar("threshold Sobel Y ", window_name3, &edgeSobelThresholdY, 10, onTrackbar);
  cv::createTrackbar("threshold Laplacian ", window_name4, &edgeLaplacian, 10, onTrackbar);
  // Show the image
  onTrackbar(0, 0);
  // Wait for a key stroke; the same function arranges events processing
  cv::waitKey(0);
  return 0;
}
