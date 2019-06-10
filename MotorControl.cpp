#include "MotorControl.h"


unsigned MotorControl::currentPos = 0;
atomic<unsigned> MotorControl::targetPos(0);
#ifdef SERIAL_CONTROL
Serial *MotorControl::motor = nullptr;
void MotorControl::send_msg(uint8_t *msg_)
{
    motor->write(msg_, MSG_LEN);
} 

void MotorControl::init(const string& dest_)
{
    if(motor != nullptr)
    {
        motor->close();
        delete motor;
    }
    motor = new Serial(dest_, 115200, serial::Timeout::simpleTimeout(1000));
}
#else
struct mosquitto *MotorControl::mosq = nullptr;
string MotorControl::dest;
void MotorControl::init(const string& dest_)
{
    mosquitto_lib_init();
    mosq = mosquitto_new(NULL, true, NULL);
    if(mosq == NULL)
    {
        std::cerr << "Create mosquitto client failed" << std::endl;
    }
    dest = dest_;
    if(mosquitto_connect(mosq, dest.c_str(), port, 60) != MOSQ_ERR_SUCCESS)
    {
        std::cerr << "Connect to mosquitto failed" << std::endl;
    }
}
void MotorControl::send_msg(uint8_t *msg_)
{
    // MQTTClient_message pubmsg = MQTTClient_message_initializer;
    // pubmsg.payload = msg_;
    // pubmsg.payloadlen = MSG_LEN;
    // pubmsg.qos = 1;
    // pubmsg.retained = 0;
    // MQTTClient_publishMessage(MotorControl::motor, "MC", &pubmsg, NULL);
    //std::cerr << "DEBUG: send msg" << std::endl;
    if(mosquitto_publish(mosq, NULL, "ldscar/uart1/send", MSG_LEN, msg_, 0, 0) != MOSQ_ERR_SUCCESS)
    {
        std::cerr << "Unable to send control message" << std::endl;
    }
}
#endif

void MotorControl::rotate_counterclockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 20, 1};
    MotorControl::send_msg(message);
}
void MotorControl::rotate_clockwise()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 20, 0};
    MotorControl::send_msg(message);
}
void MotorControl::translation_left()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 20, 0, 0, 0, 0, 4};
    MotorControl::send_msg(message);
}
void MotorControl::translation_right()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 20, 0, 0, 0, 0, 0};
    MotorControl::send_msg(message);
}
void MotorControl::move_forward()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 60, 0, 0, 0};
    MotorControl::send_msg(message);
}
void MotorControl::move_backward()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 60, 0, 0, 2};
    MotorControl::send_msg(message);
}
void MotorControl::keep_static()
{
    uint8_t message[MSG_LEN] = {0xff, 0xfe, 1, 0, 0, 0, 0, 0, 0, 0};
    MotorControl::send_msg(message);
}
void MotorControl::update_curr_pos(unsigned new_pos_)
{
    currentPos = new_pos_;
}
unsigned MotorControl::get_curr_pos()
{
    return currentPos;
}
void MotorControl::update_target_pos(unsigned new_pos_)
{
    //targetPos should only be multiples of 10
    targetPos.store((new_pos_ / 10) * 10);
}
unsigned MotorControl::get_target_pos()
{
    return targetPos.load();
}
