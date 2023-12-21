#include <librealsense2/rs.hpp> 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "how_to.hpp"
#include "trackbar.hpp"

using namespace std;

cv::Mat image;

void sensor_callback(rs2::frame sensor_frame){
    image = frame_to_mat(sensor_frame);
}

int main(int argc, char * argv[]){
    // 初始化裝置（選擇裝置）
    rs2::device dev = how_to::set_a_realsense_device(0);
    // 初始化感測器(選擇深度，色彩，陀螺儀)
    rs2::sensor sensor = how_to::set_a_sensor_from_a_device(dev,1);
    // 初始化設定檔（選擇解析度與格式）
    rs2::stream_profile profile = how_to::set_a_streaming_profile(sensor, 22);
    
    // 套用設定檔
    sensor.open(profile);
    // 開始串流（以Callback方式傳進一個rs2::frame)
    // 意思是當相機每串流進一禎的影響，就執行一次sensor_callback這個function
    sensor.start(sensor_callback);
    cv::namedWindow("RealSense", cv::WINDOW_AUTOSIZE);

    //參數滑條初始化作業
    cv::namedWindow("Option", cv::WINDOW_AUTOSIZE);
    option_param param;
    init_Param(&param);
    init_Trackbar(sensor, &param);

    while(true){
        if(!image.empty()){
            cv::imshow("RealSense", image);
        }

        cv::waitKey(10);
    }
    cout << "hello" << endl;
    return 0;
}
