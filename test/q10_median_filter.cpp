
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    cv::Mat img = cv::imread("data/input.jpg");

    if (img.empty())
    {
        std::cout << "Image load failed" << std::endl;
        return -1;
    }

    cv::Mat result(img.rows, img.cols, CV_8UC3);

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                std::vector<uchar> values;

                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        int ny = y + dy;
                        int nx = x + dx;

                        if (ny >= 0 && ny < img.rows &&
                            nx >= 0 && nx < img.cols)
                        {
                            values.push_back(
                                img.at<cv::Vec3b>(ny, nx)[c]);
                        }
                    }
                }

                std::sort(values.begin(), values.end());

                result.at<cv::Vec3b>(y, x)[c] =
                    values[values.size() / 2];
            }
        }
    }

    if (!cv::imwrite("data/q10.jpg", result))
    {
        std::cout << "Image save failed" << std::endl;
        return -1;
    }

    std::cout << "Median filter completed" << std::endl;

    return 0;
}
