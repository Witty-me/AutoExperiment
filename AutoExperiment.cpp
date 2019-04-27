#include <iostream>
#include <string>
#include <thread>
#include "MotorControl.h"
#include "VideoAnalysis.h"

void scanner()
{
    char command[50];
    while(1)
    {
        memset(command, 0, sizeof(command));
        std::cin.getline(command, sizeof(command));
        switch (command[0])
        {
            case 'm':
            {
                std::istringstream buffer(command + 2);
                unsigned target;
                buffer >> target;
                MotorControl::update_target_pos(target);
                break;
            }
            default:
            {    
                break;
            }
        }
    }
}


int main(int argc, char **argv)
{
    MotorControl::init("/dev/ttyUSB1");
    VideoAnalysis::init("http://192.168.1.1:8080/?action=stream?dummy=param.mjpg");
    
    std::thread scanner_thread(scanner);
    scanner_thread.detach();

    while (1)
    {
        VideoAnalysis::refresh_and_control();
        //std::cout << "Detected QR code: " << VideoAnalysis::decodeQR() << std::endl;
        if (waitKey(30) >= 0)
            break;
    }
    MotorControl::keep_static();
    return 0;
}
