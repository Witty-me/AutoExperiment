cmake_minimum_required(VERSION 2.8)
project( AutoExperiment )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
find_package(Threads)
#find_package(FORTE_COM_PAHOMQTT)
#include_directories( ${FORTE_COM_PAHOMQTT_INCLUDE_DIR} )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(AutoExperiment MotorControl.cpp VideoAnalysis.cpp AutoExperiment.cpp)

add_library(seriallib STATIC
    "serial/list_ports_linux.cc"
	"serial/list_ports_osx.cc"
	"serial/list_ports_win.cc"
	"serial/serial.cc"
	"serial/unix.cc"
	"serial/win.cc")

target_link_libraries( AutoExperiment ${OpenCV_LIBS})
target_link_libraries( AutoExperiment seriallib)
target_link_libraries( AutoExperiment ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries( AutoExperiment ${FORTE_COM_PAHOMQTT_LIB})
target_link_libraries (AutoExperiment  mosquitto)
