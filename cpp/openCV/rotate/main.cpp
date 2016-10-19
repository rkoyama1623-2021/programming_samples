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
  /* load image */
  char* image_name = argv[1];
  Mat image;
  image = imread( image_name, 1 );
  Size src_sz = image.size();
  if( argc != 2 || !image.data ) {
    printf( " No image data \n " );
    return -1;
  }

  /* process */
  // mat
  double angle = 30;
  int x0 = image.cols/2, y0 = image.rows/2;
  Point center = Point( x0, y0 );
  Mat rot_mat = getRotationMatrix2D(center, 30.0, 1); // center, angle, scale
  std::cout << rot_mat << std::endl;

  // copy image to dst_image
  Mat dst_image=image.clone(); // copy
  Size dst_sz(src_sz.width, src_sz.height);

  // rotate image
  warpAffine(image, dst_image, rot_mat, dst_sz);

  // show
  namedWindow( image_name, CV_WINDOW_AUTOSIZE );
  imshow( image_name, image );
  namedWindow( image_name, CV_WINDOW_AUTOSIZE );
  imshow( "rotated", dst_image );

  // exit
  waitKey(0);
  return 0;
}
