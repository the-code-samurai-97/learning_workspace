
#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
  ImageProcessor(const cv::Mat& inputImage) : inputImage_(inputImage), outputImage_(inputImage) {
    cv::namedWindow("Sobel Filter Example");
  }

  void createTrackbars() {
    cv::createTrackbar("Kernel Size", "Sobel Filter Example", &sobelKernelSize_, maxKernelSize, &ImageProcessor::onTrackbarChange, this);
    cv::createTrackbar("Scale Factor", "Sobel Filter Example", &scale_, maxScale, &ImageProcessor::onTrackbarChange, this);
    cv::createTrackbar("Delta", "Sobel Filter Example", &delta_, maxDelta, &ImageProcessor::onTrackbarChange, this);
    applySobelFilter();
  }

  void run() {
    while (true) {
      char key = cv::waitKey(10);
      if (key == 27) // Break the loop if the Esc key is pressed
        break;
    }
  }

private:
  static void onTrackbarChange(int, void* userdata) {
    ImageProcessor* processor = static_cast<ImageProcessor*>(userdata);
    processor->applySobelFilter();
  }

  void applySobelFilter() {
    cv::Sobel(inputImage_, sobelX_, CV_32F, 1, 0, 2*sobelKernelSize_+1, scale_, delta_);
    cv::Sobel(inputImage_, sobelY_, CV_32F, 0, 1, 2*sobelKernelSize_+1, scale_, delta_);

    cv::magnitude(sobelX_, sobelY_, gradientMagnitude_);
    cv::convertScaleAbs(gradientMagnitude_, gradientMagnitude_);

    cv::imshow("Sobel Filter Example", gradientMagnitude_);
  }

  const cv::Mat& inputImage_;
  cv::Mat outputImage_;
  cv::Mat sobelX_, sobelY_;
  cv::Mat gradientMagnitude_;
  int sobelKernelSize_ = 1;
  int scale_ = 1;
  int delta_ = 0;
  static constexpr int maxKernelSize = 7;
  static constexpr int maxScale = 10;
  static constexpr int maxDelta = 50;
};

int main() {
  // Load an input image
  cv::Mat inputImage = cv::imread("src/opencv/image_processor/new_paint_inter_linear.png");
  if (inputImage.empty()) {
    std::cerr << "Error: Could not load the image." << std::endl;
    return -1;
  }

  // Create an instance of the ImageProcessor class
  ImageProcessor imageProcessor(inputImage);

  // Create trackbars and run the GUI loop
  imageProcessor.createTrackbars();
  imageProcessor.run();

  return 0;
}
