#include <iostream>
#include <string>
#include "serial/serial.h"
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/imgcodecs.hpp>

#define MSG_LEN 10

using namespace cv;
using namespace serial;

Serial *motor;
const int mid_x = 1280 / 2;
const int mid_y = 720 / 2;
uint32_t control_turn = 0;

void rotate_counterclockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 1, 1};
    motor->write(message, MSG_LEN);
}
void rotate_clockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 1, 0};
    motor->write(message, MSG_LEN);
}
void translation_left()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 1, 0, 0, 0, 0, 4};
    motor->write(message, MSG_LEN);
}
void translation_right()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 1, 0, 0, 0, 0, 0};
    motor->write(message, MSG_LEN);
}
void keep_static()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 0, 0};
    motor->write(message, MSG_LEN);
}
void control(const Rect2d &LF, const Rect2d &LB, const Rect2d &RF, const Rect2d &RB)
{
    double F_x_pos = (LF.x + LF.width/2 + RF.x + RF.width/2) / 2;
    double B_x_pos = (LB.x + LB.width/2 + RB.x + RB.width/2) / 2;
    control_turn++;
    if(control_turn % 20 > 5)
    {
        keep_static();
        return;
    }
        double x_pos = (F_x_pos + B_x_pos) / 2;
        if(x_pos > mid_x * 1.05)
        {
            translation_left();
        }
        else if(x_pos < mid_x * 0.95)
        {
            translation_right();
        }

    else
    {
    if(F_x_pos > B_x_pos * 1.05)
    {
        rotate_counterclockwise();
    }
    else if(B_x_pos > F_x_pos * 1.05)
    {
        rotate_clockwise();
    }
        else
        {
            keep_static();
        }
        
    }
    

}

int main(int argc, char** argv )
{
    motor = new Serial("/dev/ttyUSB0", 115200, serial::Timeout::simpleTimeout(1000));

    VideoCapture cam;
    cam.open("http://192.168.1.1:8080/?action=stream?dummy=param.mjpg");
    if(!cam.isOpened()) {
        std::cerr << "Open camera failed!" << std::endl;
        return 1;
    }
    
    Mat frame;
    namedWindow("Camera");
    
    Ptr<Tracker> trackerLF = TrackerKCF::create();
    Ptr<Tracker> trackerLB = TrackerKCF::create();
    Ptr<Tracker> trackerRF = TrackerKCF::create();
    Ptr<Tracker> trackerRB = TrackerKCF::create();   
    cam >> frame;

    Rect2d roiLF = selectROI("Camera", frame);
    if(roiLF.width ==0 || roiLF.height ==0)
        return 2;
    Rect2d roiLB = selectROI("Camera", frame);
    if(roiLB.width ==0 || roiLB.height ==0)
        return 2;
    Rect2d roiRF = selectROI("Camera", frame);
    if(roiRF.width ==0 || roiRF.height ==0)
        return 2;
    Rect2d roiRB = selectROI("Camera", frame);
    if(roiRB.width ==0 || roiRB.height ==0)
        return 2;
    
    trackerLF->init(frame, roiLF);
    trackerLB->init(frame, roiLB);
    trackerRF->init(frame, roiRF);
    trackerRB->init(frame, roiRB);

    int turn = 0; //For QR code detector
	Mat inputImage = imread("timg.jpg");
	Mat bbox, rectifiedImage;
	QRCodeDetector qrd = QRCodeDetector();
	//std::cout << qrd.detectAndDecode(inputImage, bbox, rectifiedImage) << std::endl;

    while(1) {
        cam >> frame;

		if(turn++ >= 5) {
			QRCodeDetector qrd = QRCodeDetector();
			std::string qr_data = qrd.detectAndDecode(frame, bbox, rectifiedImage);
			//imshow("qr", inputImage);
			if(qr_data.length() > 0) {
				std::cout << "Decoded data: " << qr_data <<std::endl;
			}
			else {
				std::cout << "QR code not detected" <<std::endl;
			}
			turn = 0;
		}

        trackerLF->update(frame, roiLF);
        trackerLB->update(frame, roiLB);
        trackerRF->update(frame, roiRF);
        trackerRB->update(frame, roiRB);        
        rectangle(frame, roiLF, Scalar(255, 0, 0), 2, 1);
        rectangle(frame, roiLB, Scalar(0, 255, 0), 2, 1);
        rectangle(frame, roiRF, Scalar(0, 0, 255), 2, 1);
        rectangle(frame, roiRB, Scalar(0, 255, 255), 2, 1); 
        //std::cout<<"DEBUG: roiLF.x="<<roiLF.x<<" y="<<roiLF.y<<std::endl;
        //std::cout<<"DEBUG: roiLB.x="<<roiLB.x<<" y="<<roiLB.y<<std::endl;

        control(roiLF, roiLB, roiRF, roiRB);

        imshow("Camera", frame);
        if(waitKey(30) >= 0) break;
    }
    keep_static();
    return 0;
}
