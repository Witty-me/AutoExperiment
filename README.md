# AutoExperiment
一套自动实验装置，利用小车上的视觉信息，实现对直线的跟踪和对标识距离的二维码的识别，进而自动定位运动。

## Required
OpenCV(https://github.com/opencv/opencv) + OpenCV's extra modules (https://github.com/opencv/opencv_contrib)  
cmake, gcc, etc.

## Usage
mkdir build  
cd build  
cmake ..  
make  
sudo ./AutoExperiment  

## Notification
VideoAnalysis中的上下左右与视频信息并不一定相同，请务必注意  
此工程正在开发中，欢迎提出任何意见
