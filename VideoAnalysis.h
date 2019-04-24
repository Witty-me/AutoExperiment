#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include "MotorControl.h"

using namespace cv;
using std::string;

class VideoAnalysis
{
  private:
    //video capture of the camera
    static VideoCapture cam;

    //frame of VideoCapture
    static Mat frame;

    //trackers used to track the bold lines
    static Ptr<Tracker> trackerLF;
    static Ptr<Tracker> trackerLB;
    static Ptr<Tracker> trackerRF;
    static Ptr<Tracker> trackerRB;

    //rectangles indicating the trackers
    static Rect2d roiLF;
    static Rect2d roiLB;
    static Rect2d roiRF;
    static Rect2d roiRB;

    //QR code detector
    static QRCodeDetector qrd;
    //variable indicating whether it's time to control the car
    static uint32_t control_turn;

    //the medium of each frame, need to be changed when resolution changes
    constexpr static const double mid_x = 1280 / 2;
    constexpr static const double mid_y = 720 / 2;

  public:
    //need to be called before used
    static bool init(const string &src_);

    //capture a new frame and update trackers
    static void refresh();

    //give commands based on the current capture frame
    static void control();

    //the combination of refresh and control
    static void refresh_and_control();

    //return the string of detected QR code, string empty if no code detected
    static string decodeQR();
};