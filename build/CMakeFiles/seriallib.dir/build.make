# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/witty-me/AutoExperiment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/witty-me/AutoExperiment/build

# Include any dependencies generated for this target.
include CMakeFiles/seriallib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/seriallib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seriallib.dir/flags.make

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o: ../serial/list_ports_linux.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o -c /home/witty-me/AutoExperiment/serial/list_ports_linux.cc

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/list_ports_linux.cc > CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.i

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/list_ports_linux.cc -o CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.s

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.requires

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.provides: CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.provides

CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o


CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o: ../serial/list_ports_osx.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o -c /home/witty-me/AutoExperiment/serial/list_ports_osx.cc

CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/list_ports_osx.cc > CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.i

CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/list_ports_osx.cc -o CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.s

CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.requires

CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.provides: CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.provides

CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o


CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o: ../serial/list_ports_win.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o -c /home/witty-me/AutoExperiment/serial/list_ports_win.cc

CMakeFiles/seriallib.dir/serial/list_ports_win.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/list_ports_win.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/list_ports_win.cc > CMakeFiles/seriallib.dir/serial/list_ports_win.cc.i

CMakeFiles/seriallib.dir/serial/list_ports_win.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/list_ports_win.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/list_ports_win.cc -o CMakeFiles/seriallib.dir/serial/list_ports_win.cc.s

CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.requires

CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.provides: CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.provides

CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o


CMakeFiles/seriallib.dir/serial/serial.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/serial.cc.o: ../serial/serial.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/seriallib.dir/serial/serial.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/serial.cc.o -c /home/witty-me/AutoExperiment/serial/serial.cc

CMakeFiles/seriallib.dir/serial/serial.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/serial.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/serial.cc > CMakeFiles/seriallib.dir/serial/serial.cc.i

CMakeFiles/seriallib.dir/serial/serial.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/serial.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/serial.cc -o CMakeFiles/seriallib.dir/serial/serial.cc.s

CMakeFiles/seriallib.dir/serial/serial.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/serial.cc.o.requires

CMakeFiles/seriallib.dir/serial/serial.cc.o.provides: CMakeFiles/seriallib.dir/serial/serial.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/serial.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/serial.cc.o.provides

CMakeFiles/seriallib.dir/serial/serial.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/serial.cc.o


CMakeFiles/seriallib.dir/serial/unix.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/unix.cc.o: ../serial/unix.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/seriallib.dir/serial/unix.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/unix.cc.o -c /home/witty-me/AutoExperiment/serial/unix.cc

CMakeFiles/seriallib.dir/serial/unix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/unix.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/unix.cc > CMakeFiles/seriallib.dir/serial/unix.cc.i

CMakeFiles/seriallib.dir/serial/unix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/unix.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/unix.cc -o CMakeFiles/seriallib.dir/serial/unix.cc.s

CMakeFiles/seriallib.dir/serial/unix.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/unix.cc.o.requires

CMakeFiles/seriallib.dir/serial/unix.cc.o.provides: CMakeFiles/seriallib.dir/serial/unix.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/unix.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/unix.cc.o.provides

CMakeFiles/seriallib.dir/serial/unix.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/unix.cc.o


CMakeFiles/seriallib.dir/serial/win.cc.o: CMakeFiles/seriallib.dir/flags.make
CMakeFiles/seriallib.dir/serial/win.cc.o: ../serial/win.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/seriallib.dir/serial/win.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seriallib.dir/serial/win.cc.o -c /home/witty-me/AutoExperiment/serial/win.cc

CMakeFiles/seriallib.dir/serial/win.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seriallib.dir/serial/win.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/witty-me/AutoExperiment/serial/win.cc > CMakeFiles/seriallib.dir/serial/win.cc.i

CMakeFiles/seriallib.dir/serial/win.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seriallib.dir/serial/win.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/witty-me/AutoExperiment/serial/win.cc -o CMakeFiles/seriallib.dir/serial/win.cc.s

CMakeFiles/seriallib.dir/serial/win.cc.o.requires:

.PHONY : CMakeFiles/seriallib.dir/serial/win.cc.o.requires

CMakeFiles/seriallib.dir/serial/win.cc.o.provides: CMakeFiles/seriallib.dir/serial/win.cc.o.requires
	$(MAKE) -f CMakeFiles/seriallib.dir/build.make CMakeFiles/seriallib.dir/serial/win.cc.o.provides.build
.PHONY : CMakeFiles/seriallib.dir/serial/win.cc.o.provides

CMakeFiles/seriallib.dir/serial/win.cc.o.provides.build: CMakeFiles/seriallib.dir/serial/win.cc.o


# Object files for target seriallib
seriallib_OBJECTS = \
"CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o" \
"CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o" \
"CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o" \
"CMakeFiles/seriallib.dir/serial/serial.cc.o" \
"CMakeFiles/seriallib.dir/serial/unix.cc.o" \
"CMakeFiles/seriallib.dir/serial/win.cc.o"

# External object files for target seriallib
seriallib_EXTERNAL_OBJECTS =

libseriallib.a: CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/serial/serial.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/serial/unix.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/serial/win.cc.o
libseriallib.a: CMakeFiles/seriallib.dir/build.make
libseriallib.a: CMakeFiles/seriallib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/witty-me/AutoExperiment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libseriallib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/seriallib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seriallib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seriallib.dir/build: libseriallib.a

.PHONY : CMakeFiles/seriallib.dir/build

CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/list_ports_linux.cc.o.requires
CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/list_ports_osx.cc.o.requires
CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/list_ports_win.cc.o.requires
CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/serial.cc.o.requires
CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/unix.cc.o.requires
CMakeFiles/seriallib.dir/requires: CMakeFiles/seriallib.dir/serial/win.cc.o.requires

.PHONY : CMakeFiles/seriallib.dir/requires

CMakeFiles/seriallib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/seriallib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/seriallib.dir/clean

CMakeFiles/seriallib.dir/depend:
	cd /home/witty-me/AutoExperiment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/witty-me/AutoExperiment /home/witty-me/AutoExperiment /home/witty-me/AutoExperiment/build /home/witty-me/AutoExperiment/build /home/witty-me/AutoExperiment/build/CMakeFiles/seriallib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seriallib.dir/depend

