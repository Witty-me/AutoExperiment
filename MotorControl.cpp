#include "MotorControl.h"

Serial *MotorControl::motor = nullptr;

void MotorControl::init(const string& dest_)
{
    if(motor != nullptr)
    {
        motor->close();
        delete motor;
    }
    motor = new Serial(dest_, 115200, serial::Timeout::simpleTimeout(1000));
}
void MotorControl::rotate_counterclockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 1, 1};
    SEND_MSG(message);
}
void MotorControl::rotate_clockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 1, 0};
    SEND_MSG(message);
}
void MotorControl::translation_left()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 1, 0, 0, 0, 0, 4};
    SEND_MSG(message);
}
void MotorControl::translation_right()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 1, 0, 0, 0, 0, 0};
    SEND_MSG(message);
}
void MotorControl::keep_static()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 0, 0};
    SEND_MSG(message);
}

