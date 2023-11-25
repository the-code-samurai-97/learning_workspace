#include <cmath>
#include <opencv2/opencv.hpp>

int main() {
  const float deltaA = 0.07f;
  const float deltaB = 0.02f;

  const int columns = 400;
  const int rows = 400;

  float A = 0, B = 0, i, j;
  std::vector<float> z(columns * rows, 0);
  std::vector<char> b(columns * rows, ' ');

  cv::Mat outputImage(rows, columns, CV_8UC3,
                      cv::Scalar(0, 0, 0));  // Black background

  while (true) {
    std::fill(b.begin(), b.end(), ' ');
    std::fill(z.begin(), z.end(), 0);

    for (j = 0; 6.28 > j; j += 0.07f) {
      for (i = 0; 6.28 > i; i += 0.02f) {
        const float sini = sinf(i);
        const float cosj = cosf(j);
        const float sinA = sinf(A);
        const float sinj = sinf(j);
        const float cosA = cosf(A);
        const float cosj2 = cosj + 2;
        const float mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5);
        const float cosi = cosf(i);
        const float cosB = cosf(B);
        const float sinB = sinf(B);

        const int x =
            (columns / 2) + (3 * columns / 8) * mess *
                                (cosi * cosj2 * cosB -
                                 (sini * cosj2 * cosA - sinj * sinA) * sinB);
        const int y =
            (6 * rows / 11) + ((3 * rows / 4)) * mess *
                                  (cosi * cosj2 * sinB +
                                   (sini * cosj2 * cosA - sinj * sinA) * cosB);
        const int o = x + columns * y;
        const int N =
            8 * ((sinj * sinA - sini * cosj * cosA) * cosB -
                 sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);

        if (rows > y && y > 0 && columns > x && x > 0 && mess > z[o]) {
          z[o] = mess;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
      }
    }

    // Display the OpenCV image with the ASCII art
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < columns; x++) {
        int o = x + columns * y;
        char character = b[o];
        cv::putText(outputImage, std::string(1, character), cv::Point(x, y),
                    cv::FONT_HERSHEY_SIMPLEX, 0.1, cv::Scalar(255, 255, 255),
                    0.1, cv::LINE_AA);
      }
    }

    // Display the OpenCV image with the ASCII art
    cv::imshow("ASCII Art", outputImage);
    outputImage.setTo(cv::Scalar::all(0));
    A += deltaA;
    B += deltaB;

    // Break the loop if 'q' key is pressed
    if (cv::waitKey(100) == 'q') {
      break;
    }
     // usleep(300);

  }

  return 0;
}
