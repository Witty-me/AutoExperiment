#include "VideoAnalysis.h"

VideoCapture VideoAnalysis::cam = VideoCapture();
Mat VideoAnalysis::frame;
Ptr<Tracker> VideoAnalysis::trackerLF = TrackerKCF::create();
Ptr<Tracker> VideoAnalysis::trackerLB = TrackerKCF::create();
Ptr<Tracker> VideoAnalysis::trackerRF = TrackerKCF::create();
Ptr<Tracker> VideoAnalysis::trackerRB = TrackerKCF::create();
Rect2d VideoAnalysis::roiLF;
Rect2d VideoAnalysis::roiLB;
Rect2d VideoAnalysis::roiRF;
Rect2d VideoAnalysis::roiRB;
uint32_t VideoAnalysis::control_turn = 0;
QRCodeDetector VideoAnalysis::qrd = QRCodeDetector();
bool VideoAnalysis::finished = false;

bool VideoAnalysis::init(const string &src_)
{
    cam.open(src_);
    if (!cam.isOpened())
    {
        std::cerr << "Open camera failed!" << std::endl;
        return false;
    }

    namedWindow("Camera");
    cam >> frame;
    //The rectangle selection order:
    //bottom right -> top right -> bottom left -> top left
    roiLF = selectROI("Camera", frame);
    roiLB = selectROI("Camera", frame);
    roiRF = selectROI("Camera", frame);
    roiRB = selectROI("Camera", frame);
    if (roiLF.width == 0 || roiLF.height == 0)
        return false;
    if (roiLB.width == 0 || roiLB.height == 0)
        return false;
    if (roiRF.width == 0 || roiRF.height == 0)
        return false;
    if (roiRB.width == 0 || roiRB.height == 0)
        return false;

    trackerLF->init(frame, roiLF);
    trackerLB->init(frame, roiLB);
    trackerRF->init(frame, roiRF);
    trackerRB->init(frame, roiRB);

    return true;
}
void VideoAnalysis::refresh()
{
    cam >> frame;
    trackerLF->update(frame, roiLF);
    trackerLB->update(frame, roiLB);
    trackerRF->update(frame, roiRF);
    trackerRB->update(frame, roiRB);
    rectangle(frame, roiLF, Scalar(255, 0, 0), 2, 1);
    rectangle(frame, roiLB, Scalar(0, 255, 0), 2, 1);
    rectangle(frame, roiRF, Scalar(0, 0, 255), 2, 1);
    rectangle(frame, roiRB, Scalar(0, 255, 255), 2, 1);
    imshow("Camera", frame);
}
void VideoAnalysis::control()
{
    control_turn++;
    //in three quarters of the time, give no commands
    if (control_turn % 20 > 4)
    {
        MotorControl::keep_static();
        return;
    }

    double F_x_pos = (roiLF.x + roiLF.width / 2 + roiRF.x + roiRF.width / 2) / 2;
    double B_x_pos = (roiLB.x + roiLB.width / 2 + roiRB.x + roiRB.width / 2) / 2;
    double x_pos = (F_x_pos + B_x_pos) / 2;
    std::cerr << "DEBUG: s_pos = " << x_pos << std::endl;
    if (x_pos > mid_x * 1.05)
    {
        MotorControl::translation_right();
    }
    else if (x_pos < mid_x * 0.95)
    {
        MotorControl::translation_left();
    }
    else
    {
        if (F_x_pos > B_x_pos * 1.05)
        {
            MotorControl::rotate_clockwise();
        }
        else if (B_x_pos > F_x_pos * 1.05)
        {
            MotorControl::rotate_counterclockwise();
        }
        else
        {
            //read the QR code and update current position
            string QR = decodeQR();
            if(QR.length() > 0)
            {
                std::istringstream is(QR);
                unsigned currPos;
                is >> currPos;
                //std::cerr << "DEBUG: pos = " << currPos << std::endl;
                MotorControl::update_curr_pos(currPos);
            }

            if(MotorControl::get_curr_pos() > MotorControl::get_target_pos())
            {
                MotorControl::move_backward();
            }
            else if(MotorControl::get_curr_pos() < MotorControl::get_target_pos())
            {
                MotorControl::move_forward();
            }
            else
            {
                MotorControl::keep_static();
                set_finished();   
            }
        }
    }
}
void VideoAnalysis::refresh_and_control()
{
    refresh();
    control();
}

string VideoAnalysis::decodeQR()
{
    return qrd.detectAndDecode(frame);
}

void VideoAnalysis::set_finished()
{
    finished = true;
}

bool VideoAnalysis::is_finished()
{
    return finished;
}