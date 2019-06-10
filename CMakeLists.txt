cmake_minimum_required(VERSION 2.8)
project( AutoExperiment )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
find_package(Threads)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(AutoExperiment MotorControl.cpp VideoAnalysis.cpp AutoExperiment.cpp)
add_executable(AE_router MotorControl.cpp VideoAnalysis.cpp AE_router.cpp)

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
target_link_libraries (AutoExperiment  mosquitto)

target_link_libraries( AE_router ${OpenCV_LIBS})
target_link_libraries( AE_router seriallib)
target_link_libraries( AE_router ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (AE_router  mosquitto)