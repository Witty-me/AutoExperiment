#pragma once
#include <string>
#define MSG_LEN 10
#define SERIAL_CONTROL

#ifdef SERIAL_CONTROL //directly control via local serial port
#include "serial/serial.h"
#define SEND_MSG(x) motor->write((x), MSG_LEN)

#else //control via network

#endif

using std::string;
using namespace serial;

class MotorControl
{
  private:
#ifdef SERIAL_CONTROL
    //the serial port connecting the car
    static Serial *motor;
#endif
  public:
    //before used, must be initialized
    static void init(const string &dest_);
    static void rotate_counterclockwise();
    static void rotate_clockwise();
    static void translation_left();
    static void translation_right();
    static void keep_static();
};