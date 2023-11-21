#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
int main() {
  // Read input images
  cv::Mat image1 = cv::imread("/home/sibi/learning_workspace/src/opencv/sift_feature_matching/base_1_cp_rm.png", cv::IMREAD_GRAYSCALE);
  cv::Mat image2 = cv::imread("/home/sibi/learning_workspace/src/opencv/sift_feature_matching/base_2_cp_rm.png", cv::IMREAD_GRAYSCALE);

  // Check if images are loaded successfully
  if (image1.empty() || image2.empty()) {
    std::cerr << "Error loading images." << std::endl;
    return -1;
  }
  // Define the structuring element (kernel)
  cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));

  // Perform morphological opening
//  cv::morphologyEx(image1, image1, cv::MORPH_OPEN, kernel);
//  cv::morphologyEx(image2, image2, cv::MORPH_OPEN, kernel);
  for (int i{0};i < 5;++i)
  {
    cv::dilate(image1, image1, kernel);
    cv::dilate(image2, image2, kernel);
  }
    cv::morphologyEx(image1, image1, cv::MORPH_OPEN, kernel);
    cv::morphologyEx(image2, image2, cv::MORPH_OPEN, kernel);
  // Create SIFT detector
  cv::Ptr<cv::Feature2D> sift = cv::SIFT::create();

  // Detect keypoints and compute descriptors
  std::vector<cv::KeyPoint> keypoints1, keypoints2;
  cv::Mat descriptors1, descriptors2;

  sift->detectAndCompute(image1, cv::noArray(), keypoints1, descriptors1);
  sift->detectAndCompute(image2, cv::noArray(), keypoints2, descriptors2);

  // Draw keypoints on separate images
  cv::Mat img_keypoints1, img_keypoints2;
  cv::drawKeypoints(image1, keypoints1, img_keypoints1);
  cv::drawKeypoints(image2, keypoints2, img_keypoints2);

  // Match descriptors using a brute-force matcher
  cv::BFMatcher matcher;
  std::vector<cv::DMatch> matches;
  matcher.match(descriptors1, descriptors2, matches);

  // Draw matches on a new image
  cv::Mat img_matches;
  cv::drawMatches(image1, keypoints1, image2, keypoints2, matches, img_matches);


  // Find homography matrix using RANSAC
          std::vector<cv::Point2f> src_pts, dst_pts;

  for (size_t i = 0; i < matches.size(); i++) {
    src_pts.push_back(keypoints1[matches[i].queryIdx].pt);
    dst_pts.push_back(keypoints2[matches[i].trainIdx].pt);
  }

  cv::Mat H = cv::findHomography( src_pts,dst_pts, cv::RANSAC);
  std::cout << "Homography matrix:\n" << H  << std::endl;
  // Extract rotation and translation from the homography matrix
  cv::Mat R, t;

//  cv::decomposeHomographyMat(H, cameraMatrix, R, t, cv::noArray());

  double focal = 1.0;
  cv::Point2d pp(0.0, 0.0);
  cv::Mat E, mask;

  E = cv::findEssentialMat(src_pts,dst_pts , focal, pp, cv::RANSAC, 0.999, 1.0, mask);
  cv::recoverPose(E, src_pts,dst_pts, R, t, focal, pp, mask);

  // Print the results
  std::cout << "Rotation matrix:\n" << R << std::endl;
  std::cout << "Translation vector:\n" << t << std::endl;

  // Display the result
  cv::imshow("img_keypoints1 ", img_keypoints1);
  cv::imshow("img_keypoints2", img_keypoints2);
  cv::imshow("SIFT Matches", img_matches);
  cv::waitKey(0);

  return 0;
}
