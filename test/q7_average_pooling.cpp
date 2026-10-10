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

    cv::Mat result(img.rows, img.cols, CV_8UC3);

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                int sum = 0;
                int count = 0;

                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        int ny = y + dy;
                        int nx = x + dx;

                        if (ny >= 0 && ny < img.rows &&
                            nx >= 0 && nx < img.cols)
                        {
                            sum += img.at<cv::Vec3b>(ny, nx)[c];
                            count++;
                        }
                    }
                }

                result.at<cv::Vec3b>(y, x)[c] =
                    static_cast<uchar>(sum / count);
            }
        }
    }

    if (!cv::imwrite("data/q7.jpg", result))
    {
        std::cout << "image save failed" << std::endl;
        return -1;
    }

    std::cout << "Average pooling completed" << std::endl;

    return 0;
}