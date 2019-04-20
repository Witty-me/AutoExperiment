cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayVideo DisplayVideo.cpp )

add_library(seriallib STATIC
    "serial/list_ports_linux.cc"
	"serial/list_ports_osx.cc"
	"serial/list_ports_win.cc"
	"serial/serial.cc"
	"serial/unix.cc"
	"serial/win.cc")

target_link_libraries( DisplayVideo ${OpenCV_LIBS})
target_link_libraries( DisplayVideo seriallib)
