#include <iostream>
#include <string>
#include <thread>
#include "MotorControl.h"
#include "VideoAnalysis.h"

/*
    Usage:
    argv[1]: the address of the router, e.g. 192.168.1.1
    argv[2]: the position in centimetre that you want the car to move to, e.g. 450
*/
int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Usage: <AE_router> <ip> <position>\n");
        return 1;
    }
    MotorControl::init(argv[1]);
    
    char buf[100] = {'h', 't', 't', 'p', ':', '/', '/'};
    strcat(buf, argv[1]);
    strcat(buf, ":8080/?action=stream?dummy=param.mjpg");
    printf("%s\n", buf);
    VideoAnalysis::init(buf);
    //here is an example
    //VideoAnalysis::init("http://192.168.1.1:8080/?action=stream?dummy=param.mjpg");

    MotorControl::update_target_pos(atoi(argv[2]));

    while (1)
    {
        VideoAnalysis::refresh_and_control();
        if(VideoAnalysis::is_finished())
            break;
        if (waitKey(30) >= 0)
            break;
    }
    MotorControl::keep_static();
    return 0;
}
