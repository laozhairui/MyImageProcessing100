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
    
    cv::Mat result(img.rows, img.cols, CV_8UC3);

    for(int y = 0; y < img.rows; y++)
    {
        for(int x =0; x < img.cols; x++)
        {
            cv::Vec3b pixel = img.at<cv::Vec3b>(y,x);

            for(int c=0; c<3; c++)
            {
                result.at<cv::Vec3b>(y,x)[c] = (pixel[c]/64)*64;
            }
        }

    }
    if(!cv::imwrite("data/q5.jpg",result))
    {
        std::cout << "save image failed" << std::endl;
        return -1;
    }
    std::cout << "Quantization completed" << std::endl;
    
    return 0;
}