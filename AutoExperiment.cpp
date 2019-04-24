#include <iostream>
#include <string>
#include "MotorControl.h"
#include "VideoAnalysis.h"


int main(int argc, char **argv)
{
    MotorControl::init("/dev/ttyUSB0");
    VideoAnalysis::init("http://192.168.1.1:8080/?action=stream?dummy=param.mjpg");
    
    while (1)
    {
        VideoAnalysis::refresh_and_control();
        std::cout << "Detected QR code: " << VideoAnalysis::decodeQR() << std::endl;
        if (waitKey(30) >= 0)
            break;
    }
    MotorControl::keep_static();
    return 0;
}
