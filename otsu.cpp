#include <opencv2/opencv.hpp>
#include <iostream>
#include "assignment.h"

//int calc_otsu(cv::Mat input_image);

int calc_otsu(cv::Mat input_image)
{
    int histogram[255] = {0};
    int N = input_image.rows * input_image.cols;
    double max_sigmaB2 = 0.0;
    int kstar = 0;

    for (int i = 0; i < input_image.rows; i++) {
       for (int j = 0; j < input_image.cols; j++) {
           histogram[input_image.at<uchar>(i,j)]++;
       } 
    }

    for (int k = 0; k < 255; k++) {
        int w = 0, u = 0;
        for (int i = 0; i < k; i++) {
            w += histogram[i];
            u += i * histogram[i];
        }

        if (w == 0) continue;

        double u0 = u * 1.0 / w;
        double w0 = w * 1.0 / N;

        w = 0;
        u = 0;
        for (int i = k + 1; i < 255; i++) {
			w += histogram[i];  
			u += i * histogram[i]; 
		}

		if (w == 0) break;

		double u1 = u * 1.0 / w; 
		double w1 = w * 1.0 / N;

        double sigmaB2 = w0 * w1 * (u1 - u0) * (u1 - u0);
        
        if (sigmaB2 > max_sigmaB2) {
            max_sigmaB2 = sigmaB2;
            kstar = k;
        }
    }

    return kstar;
}
