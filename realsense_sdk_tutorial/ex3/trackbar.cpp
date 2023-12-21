#include "trackbar.hpp"

//初始化相機數值
void init_Param(option_param* param){
    param->backlight_compensation = 0;
    param->brightness = 50;
    param->contrast = 50;
    param->exposure = 166;
    param->gain = 64;
    param->gamma = 300;

    param->hue = 0;
    param->saturation = 68;
    param->sharpness = 50;
    param->white_blance = 4600;
    param->auto_exposure = 1;
    param->auto_white_blance = 1;
}

//Callback function 們
void on_Backlight_Compensation_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_BACKLIGHT_COMPENSATION, index);
}
void on_Brightness_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_BRIGHTNESS, index);
}
void on_Contrast_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_CONTRAST, index);
}
void on_Exposure_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_EXPOSURE, index);
}
void on_Gain_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_GAIN, index);
}
void on_Gamma_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_GAMMA, index);
}

//-----------------------------------------------

void on_Hue_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_HUE, index);
}
void on_Saturation_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_SATURATION, index);
}
void on_Sharpness_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_SHARPNESS, index);
}
void on_White_Blance_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_WHITE_BALANCE, index);
}
void on_Auto_Exposure_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_ENABLE_AUTO_EXPOSURE, index);
}
void on_Auto_White_Blance_Trackbar(int index, void *object){
    rs2::sensor& sensor = *(rs2::sensor*) object;
    sensor.set_option(RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE, index);
}

//初始化滑條和Callback function
void init_Trackbar(rs2::sensor& sensor, option_param* param){
    cv::createTrackbar("背光增益", "Option", &param->backlight_compensation, 1000, on_Backlight_Compensation_Trackbar, (void*) &sensor);
    cv::createTrackbar("明度", "Option", &param->brightness, 100, on_Brightness_Trackbar, (void*) &sensor);
    cv::createTrackbar("對比", "Option", &param->contrast, 100, on_Contrast_Trackbar, (void*) &sensor);
    cv::createTrackbar("暴光", "Option", &param->exposure, 1000, on_Exposure_Trackbar, (void*) &sensor);
    cv::createTrackbar("增益", "Option", &param->gain , 200, on_Gain_Trackbar, (void*) &sensor);
    cv::createTrackbar("gamma", "Option", &param->gamma, 500, on_Gamma_Trackbar, (void*) &sensor);

    cv::createTrackbar("色調", "Option", &param->hue, 180, on_Hue_Trackbar, (void*) &sensor);
    cv::createTrackbar("飽和度", "Option", &param->saturation, 100, on_Saturation_Trackbar, (void*) &sensor);
    cv::createTrackbar("銳利度", "Option", &param->sharpness, 100, on_Sharpness_Trackbar, (void*) &sensor);
    cv::createTrackbar("白平衡", "Option", &param->white_blance, 10000, on_White_Blance_Trackbar, (void*) &sensor);
    cv::createTrackbar("自動曝光", "Option", &param->auto_exposure, 1, on_Auto_Exposure_Trackbar, (void*) &sensor);
    cv::createTrackbar("自動白平衡", "Option", &param->auto_white_blance, 1, on_Auto_White_Blance_Trackbar, (void*) &sensor);

    on_Backlight_Compensation_Trackbar(param->backlight_compensation, (void*) &sensor);
    on_Brightness_Trackbar(param->brightness, (void*) &sensor);
    on_Exposure_Trackbar(param->contrast, (void*) &sensor);
    on_Contrast_Trackbar(param->exposure, (void*) &sensor);
    on_Gain_Trackbar(param->gain, (void*) &sensor);
    on_Gamma_Trackbar(param->gamma, (void*) &sensor);

    on_Hue_Trackbar(param->hue, (void*) &sensor);
    on_Saturation_Trackbar(param->saturation, (void*) &sensor);
    on_Sharpness_Trackbar(param->sharpness, (void*) &sensor);
    on_White_Blance_Trackbar(param->white_blance, (void*) &sensor);
    on_Auto_Exposure_Trackbar(param->auto_exposure, (void*) &sensor);
    on_Auto_White_Blance_Trackbar(param->auto_white_blance, (void*) &sensor);
}

