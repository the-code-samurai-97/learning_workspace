/**
  This code is modified based on Opencv 4.x modules/imgproc/src/hough.cpp

  @author Sibi N R <sibi@ventitechnologies.com>
  @date october 02 2023

//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000, Intel Corporation, all rights reserved.
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Copyright (C) 2014, Itseez, Inc, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without
modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright
notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote
products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is"
and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are
disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any
direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/
#pragma once
#include <algorithm>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <vector>
class LineFitting {
 public:
  LineFitting(int width, int height, float rho, float theta_step, int threshold,
              float theta_min, float theta_max)
      : image_width_{width},
        image_height_{height},
        rho_step_{rho},
        theta_step_{theta_step},
        threshold_{threshold},
        minimum_theta_{theta_min},
        maximum_theta_{theta_max} {
    maximum_rho_ = image_width_ + image_height_;
    mininmum_rho_ = -maximum_rho_;

    number_of_angles_ = ComputeNumberOfAngles();
    number_of_rhos_ = ComputeNumberOfRhos();

    accumulated_values_ =
        cv::Mat::zeros((number_of_angles_), (number_of_rhos_), CV_32SC1);

    table_sin_angle_.reserve(number_of_angles_);
    table_cos_angle_.reserve(number_of_angles_);
    createTrignometryTable();
  }

  std::vector<cv::Vec2f> FitLine(const cv::Mat &input_image);

 private:
  int ComputeNumberOfAngles() const;
  int ComputeNumberOfRhos() const;
  void createTrignometryTable();
  void FillAccumulator(const cv::Mat &input_image);
  void FindLocalMaximuma();

 private:
  // input parameters
  // pixels, image cols
  int image_width_{0};
  // pixels, image rows
  int image_height_{0};
  float rho_step_{0};    // radians
  float theta_step_{0};  // radians
  // number of votes for the hough
  int threshold_{0};
  // radians lower bound theta angle of the line
  float minimum_theta_{0};
  // radians upper bound theta angle of the line
  float maximum_theta_{0};

  // Hough parameters
  int maximum_rho_{0};
  int mininmum_rho_{0};
  int number_of_angles_{0};
  int number_of_rhos_{0};
  cv::Mat accumulated_values_{};
  std::vector<int> acummulator_;
  std::vector<int> sort_buf_;

  std::vector<float> table_sin_angle_;
  std::vector<float> table_cos_angle_;

  // outputs
  std::vector<float> fitted_lines_;
};

/**
 * 1 first check the type
 * 2 calculate number of angles and rho
 * 3 fill the accumulator
 * 4 find local maximas
 */
