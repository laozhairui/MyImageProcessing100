#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("data/input.jpg");
    
    if(img.empty())
    {
        std::cout << "image load failed" << std::endl;
        return -1;
    }

    cv::Mat gray(img.rows, img.cols, CV_8UC1);
    for(int y = 0; y < img.rows; y++)
    {
        for(int x = 0; x < img.cols; x++)
        {
            cv::Vec3b pixel = img.at<cv::Vec3b>(y,x);
            int B = pixel[0];
            int G = pixel[1];
            int R = pixel[2];
            
            int value = static_cast<int>(
                0.299 * R + 0.587 * G + 0.114 * B + 0.5
            );
            gray.at<uchar>(y,x) = static_cast<uchar>(value);
        
        }
    }
    cv::imwrite("data/q2.jpg",gray);
    std::cout << "Grayscale conversion completed" << std::endl;
    return  0;

}
