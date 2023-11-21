#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

void rotatePoint(double& x, double& y, double angle) {
  double newX = x * cos(angle) - y * sin(angle);
  double newY = x * sin(angle) + y * cos(angle);
  x = newX;
  y = newY;
}

int main() {
  const int width = 500;
  const int height = 500;

  cv::Mat image(height, width, CV_8UC1, cv::Scalar(0)); // Black background

  float A = 0, B = 0;
  float i, j;
  int k;
  float z[250000];
  char b[250000];

  for (;;) {
    std::memset(b, ' ', 250000); // White characters
    std::memset(z, 0, 1000000);

    for (j = 0; j < 6.28; j += 0.005) {  // Slower rotation
      for (i = 0; i < 6.28; i += 0.01) {
        float c = std::sin(i);
        float d = std::cos(j);
        float e = std::sin(A);
        float f = std::sin(j);
        float g = std::cos(A);
        float h = d + 2;
        float D = 1 / (c * h * e + f * g + 5);
        float l = std::cos(i);
        float m = std::cos(B);
        float n = std::sin(B);
        float t = c * h * g - f * e;
        int x = width / 2 + width / 2 * D * (l * h * m - t * n);
        int y = height / 2 + height / 2 * D * (l * h * n + t * m);
        int o = x + width * y;
        int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

        if (width * height > o && o >= 0 && D > z[o]) {
          z[o] = D;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
      }
    }

    for (k = 0; k < width * height; k++) {
      int intensity = (b[k] == ' ') ? 0 : 255; // White characters on black background
      image.at<uchar>(k / width, k % width) = intensity;

      A += 0.0000002;  // Slower rotation
      B += 0.0000005; // Slower rotation
    }

    cv::imshow("Rotating 3D Donut", image);
    if (cv::waitKey(30) == 27) {
      break;
    }
  }

  return 0;
}
