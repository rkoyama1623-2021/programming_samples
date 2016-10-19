// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

#define DEBUG
#ifdef DEBUG
#define DEBUG_STDERR(x) (std::cerr << (x) << std::endl)
#define DEBUG_STDOUT(x) (std::cout << (x) << std::endl)
#define DEBUGP true
#else
#define DEBUG_STDERR(x)
#define DEBUG_STDOUT(x)
#define DEBUGP false
#endif

using namespace cv;

int main( int argc, char** argv )
{
  /* load image */
  char* image_name = argv[1];
  Mat image, image_dst;
  image = imread( image_name, 1 );
  if( argc != 2 || !image.data ) {
    printf( " No image data \n " );
    return -1;
  }
  /* process */
  // convdert image_dst to gray
  cvtColor( image, image_dst, COLOR_BGR2GRAY );
  blur( image_dst, image_dst, Size(3,3) );

  /// threshold
  int thresh = 150;
  Mat threshold_output;
  threshold( image_dst, threshold_output, thresh, 255, THRESH_BINARY );

  /// find contours
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) ); //threshold_output is changed
  { // for debug
    if (DEBUGP) {
      RNG rng(12345);
      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
      for (int i=0; i < contours.size(); i++) {
        for (int j=0; j < contours[i].size(); j++) {
          circle(image, contours[i][j], 1, color);
        }
      }
    }
  }

  /// Approximate contours to polygons + get bounding rects and circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  {
    vector<vector<Point> > contours_poly( contours.size() ); // vector for approximated polygon
    vector<Rect> boundRect( contours.size() ); // vector for rectangle
    vector<Point2f>center( contours.size() ); // vector for circle
    vector<float>radius( contours.size() ); // vector for radius
    for( size_t i = 0; i < contours.size(); i++ ) {
      approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true ); // get polygon
      boundRect[i] = boundingRect( Mat(contours_poly[i]) ); // get rect angle
      minEnclosingCircle( contours_poly[i], center[i], radius[i] ); // get circle
    }
    for( size_t i = 0; i< contours.size(); i++ ) {
      RNG rng(12345);
      //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
      Scalar color = Scalar( 0, 255, 0 ); // B,G,R
      drawContours( drawing,
                    contours_poly,
                    (int)i, // index of contour
                    color,
                    1, // width
                    8, // line method
                    vector<Vec4i>(),
                    1, // maxlevel
                    Point() ); // draw polygon
      // rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 ); // draw rectangle
      // circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 ); // draw circle
    }
  }

  // show
  imshow("src", image);
  imshow("image_dst", image_dst);
  imshow("threshold_output", threshold_output);
  imshow( "Contours", drawing );

  // exit
  waitKey(0);
  return 0;
}
