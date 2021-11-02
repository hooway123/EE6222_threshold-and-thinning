#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

#include "assignment.h"

#define P1 (image.at<uchar>(i, j) == 0)
#define P2 (image.at<uchar>(i, j - 1) == 0)
#define P3 (image.at<uchar>(i + 1, j - 1) == 0)
#define P4 (image.at<uchar>(i + 1, j) == 0)
#define P5 (image.at<uchar>(i + 1, j + 1) == 0)
#define P6 (image.at<uchar>(i, j + 1) == 0)
#define P7 (image.at<uchar>(i - 1, j + 1) == 0)
#define P8 (image.at<uchar>(i - 1, j) == 0)
#define P9 (image.at<uchar>(i - 1, j - 1) == 0)

bool condition1(cv::Mat image, int i, int j)
{
    int N = P2 + P3 + P4 + P5 + P6 + P7 + P8 + P9;

    return N >= 2 && N <= 6;
}

bool condition2(cv::Mat image, int i, int j)
{
    int S = (!P2 && P3) + (!P3 && P4) + (!P4 && P5) + (!P5 && P6) + (!P6 && P7) +(!P7 && P8) + (!P8 && P9) + (!P9 && P2);

    return S == 1;
}

int two_steps_thinning(cv::Mat input_image, cv::Mat & output_image)
{
    int times = 0;
    bool removal;
    cv::Mat image(input_image.rows, input_image.cols, CV_8UC1);
    cv::Mat new_image(input_image.rows, input_image.cols, CV_8UC1);

    input_image.copyTo(image);

    while(1)
    {
        //step1
        removal = false;
        for (int i = 1; i < image.rows - 1; i++) {
            for (int j = 1; j < image.cols - 1; j++) {
                new_image.at<uchar>(i, j) = 255;

                if P1 {
                    if (!(condition1(image, i, j) 
                    && condition2(image, i, j)
                    && (!P2 || !P4 || !P6)
                    && (!P4 || !P6 || !P8) )) {
                        new_image.at<uchar>(i, j) = 0;
                    }
                    else {
                        removal = true;
                    }
                }
            }
        }
        if(!removal) break;
        new_image.copyTo(image);

        //step2
        removal = false;
        for (int i = 1; i < image.rows - 1; i++) {
            for (int j = 1; j < image.cols - 1; j++) {
                new_image.at<uchar>(i, j) == 255;

                if P1 {
                    if (!(condition1(image, i, j) 
                    && condition2(image, i, j)
                    && (!P2 || !P4 || !P8)
                    && (!P2 || !P6 || !P8))) {
                        new_image.at<uchar>(i, j) = 0;
                    }
                    else {
                        removal = true;
                    }
                }
            }
        }
        if(!removal) break;
        
        new_image.copyTo(image);
            
        cv::imshow("poiii", new_image);
        cv::waitKey(0);
    } 

    new_image.copyTo(output_image);

    return 0;
}

/*
       //times++;
        //std::ostringstream oss;
        //oss << "sketelon_image" << times << ".bmp";
        //cv::imwrite(oss.str(), new_image);
*/