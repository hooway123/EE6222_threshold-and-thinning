#include <opencv2/opencv.hpp>
#include <iostream>
#include "assignment.h"

//std::cout<<"ttt"<<std::endl;

// Using the global threshold to binary the input image
int my_threshold(cv::Mat &input_image, cv::Mat &output_image, int threshold)
{
    for (int i = 0; i < output_image.rows; i++) {
       for (int j = 0; j < output_image.cols; j++) {
           if (input_image.at<uchar>(i,j) > threshold) { 
               output_image.at<uchar>(i,j) = 255;
           }
           else {
               output_image.at<uchar>(i,j) = 0;
           }
       } 
    }

    return 0;
}