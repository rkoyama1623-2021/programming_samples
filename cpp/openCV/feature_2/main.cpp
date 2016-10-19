// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <stdio.h>
#include <iostream>
#include <cv.h>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp" // findhomography

using namespace cv;

void readme();

/** @function main */
int main( int argc, char** argv )
{
  if( argc != 3 )
    { return -1; }

  Mat img_1_color = imread( argv[1], 1 );
  Mat img_2_color = imread( argv[2], 1 );
  Mat img_1 = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
  Mat img_2 = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE );

  if( !img_1.data || !img_2.data )
    { return -1; }

  //-- Step 1: Detect the keypoints using SURF Detector
  int minHessian = 400;

  SurfFeatureDetector detector( minHessian );

  std::vector<KeyPoint> keypoints_1, keypoints_2;

  detector.detect( img_1, keypoints_1 );
  detector.detect( img_2, keypoints_2 );

  //-- Step 2: Calculate descriptors (feature vectors)
  SurfDescriptorExtractor extractor;
  Mat descriptors_1, descriptors_2;
  extractor.compute( img_1, keypoints_1, descriptors_1 );
  extractor.compute( img_2, keypoints_2, descriptors_2 );

  //-- Step 3: Matching descriptor vectors with a brute force matcher
  BFMatcher matcher(NORM_L2);
  std::vector< DMatch > matches;
  matcher.match( descriptors_1, descriptors_2, matches );

  //-- Step 4: homograpy matrix
  vector<cv::Point2f> match_point1, match_point2;
  for (size_t i = 0; i < matches.size(); ++i) {
    match_point1.push_back(keypoints_1[matches[i].queryIdx].pt);
    match_point2.push_back(keypoints_2[matches[i].trainIdx].pt);
  }
  Mat masks;
  Mat H = findHomography(match_point1, match_point2, masks, RANSAC, 3);
  std::cout << H << std::endl;

  //-- step 5: extract matched points
  vector<cv::DMatch> inlinerMatch;
  std::vector<KeyPoint> good_query_keypoint;
  for ( size_t i = 0; i < masks.rows; ++i ) {
    if (masks.at<uchar>(i,0)  == 1) {
      inlinerMatch.push_back(matches[i]);
    }
  }

  //-- step 6: draw good keypoints
  /// threshold
  int thresh = 150;
  Mat threshold_output; 
  { //show matched points
    Scalar color = Scalar( 0, 255, 0 );
    for ( size_t i =0; i < inlinerMatch.size(); ++i ) {
      circle(img_1_color, keypoints_1[inlinerMatch[i].queryIdx].pt , 3, color);
      circle(img_2_color, keypoints_2[inlinerMatch[i].trainIdx].pt , 3, color);
    }
  }

  //-- Draw matches
  Mat img_matches;
  drawMatches( img_1, keypoints_1, img_2, keypoints_2, matches, img_matches );


  //-- Show detected matches
  imshow("Matches", img_matches );
  imshow("img_1_color", img_1_color );
  imshow("img_2_color", img_2_color );

  waitKey(0);

  return 0;
}

/** @function readme */
void readme()
{ std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl; }
