// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;

int main( int argc, char** argv )
{
  // load image
  char* image_name = argv[1];
  Mat image;
  image = imread( image_name, 1 );
  if( argc != 2 || !image.data ) {
    printf( " No image data \n " );
    return -1;
  }

  // process
  namedWindow( image_name, CV_WINDOW_AUTOSIZE );
  imshow( image_name, image );

  // exit
  waitKey(0);
  return 0;
}
