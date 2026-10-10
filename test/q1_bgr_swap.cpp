#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("data/input.jpg");

    if (img.empty())
    {
        std::cout << "image load failed" << std::endl;
        return -1;
    }

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            cv::Vec3b& pixel = img.at<cv::Vec3b>(y, x);

            uchar temp = pixel[0];
            pixel[0] = pixel[2];
            pixel[2] = temp;
        }
    }

    cv::imwrite("data/q1_bgr_swap.jpg", img);

    std::cout << "BGR swap completed" << std::endl;

    return 0;
}
