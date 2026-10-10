#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("data/q2.jpg");
    
    if(img.empty())
    {
        std::cout << "image load failed" << std::endl;
        return -1;
    }
    cv::Mat binary(img.rows, img.cols, CV_8UC1);
    int threshold = 128;
    for(int y = 0; y < img.rows; y++)
    {
        for(int x = 0; x < img.cols; x++)
        {
            uchar pixel = img.at<uchar>(y,x);
            if (pixel > threshold)
            {
                binary.at<uchar>(y,x) = 255;
            }
            else 
            {
                binary.at<uchar>(y,x) = 0;
            }
        }
    }
    if(!cv::imwrite("data/q3.jpg",binary))
    {
        std::cout << "image save failed" << std::endl;
    }
    std::cout << "Thresholding completed" <<std::endl;
    return 0;
}