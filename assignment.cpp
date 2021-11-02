#include <opencv2/opencv.hpp>
#include <iostream>
#include "assignment.h"
   //std::cout<<"sima"<<std::endl;

int main(int argc, char *argv[])
{
    cv::Mat image = cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
    int otsu = calc_otsu(image);

    cv::Mat binary_image(image.rows, image.cols, CV_8UC1, cv::Scalar(0));
    cv::Mat sketelon_image(image.rows, image.cols, CV_8UC1, cv::Scalar(0));

    std::cout<<"sima" << otsu <<std::endl;
    my_threshold(image, binary_image, otsu);

    two_steps_thinning(binary_image, sketelon_image);

    //cv::Mat hist = getHistograph(image);
    //cv::imshow("sss", hist);


    //cv::imshow("aaa", binary_image);
    //cv::imshow("bbb", sketelon_image);
    //cv::waitKey(0);
    
    //cv::imwrite("binary_image" + std::string(argv[1]) + ".bmp", binary_image);
    //cv::imwrite("sketelon_image" + std::string(argv[1]) + ".bmp", sketelon_image);
    
    std::cout<<"hello world" << otsu <<std::endl;
    return 0;
}