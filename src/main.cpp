#include "hazeremoval.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char** args)
{
    const char* img_path = args[1];

    std::string file_fullname = std::filesystem::path(img_path).filename().string();
    size_t dotPosition = file_fullname.find_last_of('.');
    std::string filename = file_fullname.substr(0, dotPosition);
    std::cout << "Image filename: " << file_fullname << std::endl;

    cv::Mat in_img = cv::imread(img_path);
    cv::Mat out_img(in_img.rows, in_img.cols, CV_8UC3);
    unsigned char* indata = in_img.data;
    unsigned char* outdata = out_img.data;

    CHazeRemoval hr;
    std::cout << hr.InitProc(in_img.cols, in_img.rows, in_img.channels()) << std::endl;
    std::cout << hr.Process(indata, outdata, in_img.cols, in_img.rows, in_img.channels()) << std::endl;

    // // Save results
    std::filesystem::path output_path = std::filesystem::path("outputs") / std::string(filename + ".png");
    std::cout << "Save result to: " << std::string(output_path) << std::endl;
    cv::imwrite(output_path, out_img);

    cv::imshow("out_img", out_img);
    cv::waitKey(0);
    
    return 0;
}