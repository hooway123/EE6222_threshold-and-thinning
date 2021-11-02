#ifndef AAA
#define AAA
#include <opencv2/opencv.hpp>
#include <iostream>

int calc_otsu(cv::Mat input_image);
int my_threshold(cv::Mat &input_image, cv::Mat &output_image, int threshold);
int two_steps_thinning(cv::Mat input_image, cv::Mat & output_image);
cv::Mat getHistograph(const cv::Mat grayImage);

#endif
