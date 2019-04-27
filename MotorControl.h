#pragma once
#include <string>
#include <atomic>
#include <iostream>
#define MSG_LEN 10
// #define SERIAL_CONTROL

#ifdef SERIAL_CONTROL 
//directly control via local serial port
#include "serial/serial.h"

using namespace serial;

#else 
//control via network
#include "mosquitto.h"

#endif

using std::string;
using std::atomic;


class MotorControl
{
  private:
#ifdef SERIAL_CONTROL
    //the serial port connecting the car
    static Serial *motor;
#else
    static struct mosquitto *mosq;
    static string dest;
    static const int port = 1883;
#endif
    static unsigned currentPos;
    static atomic<unsigned> targetPos;
  public:
    //before used, must be initialized
    static void init(const string &dest_);
    static void send_msg(uint8_t *msg_);
    static void rotate_counterclockwise();
    static void rotate_clockwise();
    static void translation_left();
    static void translation_right();
    static void move_forward();
    static void move_backward();
    static void keep_static();
    static void update_curr_pos(unsigned new_pos_);
    static unsigned get_curr_pos();

    //thread safe
    static void update_target_pos(unsigned new_pos_);
    //thread safe
    static unsigned get_target_pos();
};