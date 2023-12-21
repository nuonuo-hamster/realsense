#include <librealsense2/rs.hpp> 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

struct option_param{
    //0.~5.
    int backlight_compensation;
    int brightness;
    int contrast;
    int exposure;
    int gain;
    int gamma;
    //6.~11.
    int hue;
    int saturation;
    int sharpness;
    int white_blance;
    int auto_exposure;
    int auto_white_blance;
};

void init_Param(option_param* param);
void init_Trackbar(rs2::sensor& sensor, option_param* param);


//void on_Exp_Trackbar(int index, void *object);