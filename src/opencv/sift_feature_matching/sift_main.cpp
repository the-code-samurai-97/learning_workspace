#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
int main() {
  // Read input images
  cv::Mat original_1,original_2;
  cv::Mat image1 = cv::imread("/home/sibi/learning_workspace/src/opencv/sift_feature_matching/base_1_cp_rm.png", cv::IMREAD_GRAYSCALE);
  cv::Mat image2 = cv::imread("/home/sibi/learning_workspace/src/opencv/sift_feature_matching/base_2_cp_rm.png", cv::IMREAD_GRAYSCALE);
  original_1 = image1.clone();
  original_2 = image2.clone();
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
  std::cout << "src_pts matrix:\n" << src_pts << std::endl;
  // Extract rotation and translation from the homography matrix
  std::vector<cv::Mat> rotations, translations, normals;
  std::vector<cv::Mat> rotations_matrix;
//  cv::Mat warp_mat = cv::getAffineTransform( src_pts.data(), dst_pts.data() );
//  std::cout << "src_pts matrix:\n" << warp_mat << std::endl;;
  cv::decomposeHomographyMat(H, cv::Mat::eye(3, 3, CV_64F), rotations, translations, normals);
//  cv::Mat output_array;
//  cv::filterHomographyDecompByVisibleRefpoints(rotations,normals,src_pts,dst_pts,output_array );
//  std::cout<<"output array "<<output_array<<"\n";
//  // Convert the rotation vectors to rotation matrices
  for (size_t i = 0; i < rotations.size(); ++i) {
    cv::Mat rotation_matrix;
    cv::Rodrigues(rotations[i], rotation_matrix);
    rotations_matrix.push_back(rotation_matrix);
  }
//
//  // Print the results
  for (size_t i = 0; i < rotations_matrix.size(); ++i) {
    std::cout << "Rotation Matrix " << i + 1 << ":\n" << rotations_matrix[i] << std::endl;
    std::cout << "Translation Vector " << i + 1 << ":\n" << translations[i] << std::endl;
    std::cout << "Normal Vector " << i + 1 << ":\n" << normals[i] << std::endl;
    std::cout << "---------------------\n";
  }
//
//
//  double focal = 1.0;
//  cv::Point2d pp(0.0, 0.0);
//  cv::Mat E, mask;
//  cv::Mat R,t;
//  E = cv::findEssentialMat(src_pts,dst_pts , focal, pp, cv::RANSAC, 0.999, 1.0, mask);
//  cv::recoverPose(E, src_pts,dst_pts, R, t, focal, pp, mask);
//
//  std::cout << "Essential  matrix:\n" << E << std::endl;
//  // Print the results
//  std::cout << "Rotation matrix:\n" << R << std::endl;
//  std::cout << "Translation vector:\n" << t << std::endl;

  // Display the result
  cv::imshow("img_keypoints1 ", img_keypoints1);
  cv::imshow("img_keypoints2", img_keypoints2);
  cv::imshow("SIFT Matches", img_matches);

//  cv::Mat H = cv::findHomography(src_pts, dst_pts, cv::RANSAC);

  // Extract rotation and translation from the homography matrix
//  cv::Mat R2, t2;
//  cv::decomposeHomographyMat(H, cv::Mat(), R2, t2, cv::Mat());

  // Apply transformation to the image
  cv::Mat transformedImage;
  cv::warpPerspective(original_1, transformedImage, H, original_1.size());
//  cv::warpAffine( original_1, transformedImage, warp_mat, original_1.size() );
  // Display the original and transformed images
  cv::imshow("Original original_2", original_2);
  cv::imshow("Transformed Image", transformedImage);

  cv::waitKey(0);

  return 0;
}
