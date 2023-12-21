#include <librealsense2/rs.hpp> 
#include <iostream>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>

using namespace std;



cv::Mat frame_to_mat(const rs2::frame& f)
{
    using namespace cv;
    using namespace rs2;

    auto vf = f.as<video_frame>();
    const int w = vf.get_width();
    const int h = vf.get_height();

    if (f.get_profile().format() == RS2_FORMAT_BGR8)
    {
        return Mat(Size(w, h), CV_8UC3, (void*)f.get_data(), Mat::AUTO_STEP);
    }
    else if (f.get_profile().format() == RS2_FORMAT_RGB8)
    {
        auto r_rgb = Mat(Size(w, h), CV_8UC3, (void*)f.get_data(), Mat::AUTO_STEP);
        Mat r_bgr;
        cvtColor(r_rgb, r_bgr, COLOR_RGB2BGR);
        return r_bgr;
    }
    else if (f.get_profile().format() == RS2_FORMAT_Z16)
    {
        return Mat(Size(w, h), CV_16UC1, (void*)f.get_data(), Mat::AUTO_STEP);
    }
    else if (f.get_profile().format() == RS2_FORMAT_Y8)
    {
        return Mat(Size(w, h), CV_8UC1, (void*)f.get_data(), Mat::AUTO_STEP);
    }
    else if (f.get_profile().format() == RS2_FORMAT_DISPARITY32)
    {
        return Mat(Size(w, h), CV_32FC1, (void*)f.get_data(), Mat::AUTO_STEP);
    }

    throw std::runtime_error("Frame format is not supported yet!");
}

int main(int argc, char * argv[]){
    cout << "hello" << endl;
    rs2::pipeline pipeline;
    rs2::config config;
    rs2::align align_to(RS2_STREAM_COLOR);
    // Declare depth colorizer for pretty visualization of depth data
    //rs2_config_enable_stream(config , )
    pipeline.start();
    while(true){
        cout << "hello" << endl;
        rs2::frameset frame = pipeline.wait_for_frames(); // Wait for next set of frames from the camera
        rs2::frameset aligned_set = align_to.process(frame);
        cv::Mat color_image = frame_to_mat(aligned_set.get_color_frame());
        
        //rs2::frame color_frame = frame.get_color_frame(); // Find the color data

        cv::namedWindow("RealSense", cv::WINDOW_AUTOSIZE);
        cv::imshow("RealSense", color_image);
        cv::waitKey(1);
        cout << "hello" << endl;
    }

    cout << "hello" << endl;
    return 0;
}
