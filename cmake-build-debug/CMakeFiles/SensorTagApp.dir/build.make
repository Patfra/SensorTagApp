# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/patryk/Dokumenty/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/patryk/Dokumenty/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patryk/Dokumenty/SensorTagApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patryk/Dokumenty/SensorTagApp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SensorTagApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SensorTagApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SensorTagApp.dir/flags.make

CMakeFiles/SensorTagApp.dir/main.cpp.o: CMakeFiles/SensorTagApp.dir/flags.make
CMakeFiles/SensorTagApp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/patryk/Dokumenty/SensorTagApp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SensorTagApp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SensorTagApp.dir/main.cpp.o -c /home/patryk/Dokumenty/SensorTagApp/main.cpp

CMakeFiles/SensorTagApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorTagApp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/patryk/Dokumenty/SensorTagApp/main.cpp > CMakeFiles/SensorTagApp.dir/main.cpp.i

CMakeFiles/SensorTagApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorTagApp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/patryk/Dokumenty/SensorTagApp/main.cpp -o CMakeFiles/SensorTagApp.dir/main.cpp.s

CMakeFiles/SensorTagApp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SensorTagApp.dir/main.cpp.o.requires

CMakeFiles/SensorTagApp.dir/main.cpp.o.provides: CMakeFiles/SensorTagApp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SensorTagApp.dir/build.make CMakeFiles/SensorTagApp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SensorTagApp.dir/main.cpp.o.provides

CMakeFiles/SensorTagApp.dir/main.cpp.o.provides.build: CMakeFiles/SensorTagApp.dir/main.cpp.o


# Object files for target SensorTagApp
SensorTagApp_OBJECTS = \
"CMakeFiles/SensorTagApp.dir/main.cpp.o"

# External object files for target SensorTagApp
SensorTagApp_EXTERNAL_OBJECTS =

SensorTagApp: CMakeFiles/SensorTagApp.dir/main.cpp.o
SensorTagApp: CMakeFiles/SensorTagApp.dir/build.make
SensorTagApp: CMakeFiles/SensorTagApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/patryk/Dokumenty/SensorTagApp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SensorTagApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SensorTagApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SensorTagApp.dir/build: SensorTagApp

.PHONY : CMakeFiles/SensorTagApp.dir/build

CMakeFiles/SensorTagApp.dir/requires: CMakeFiles/SensorTagApp.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SensorTagApp.dir/requires

CMakeFiles/SensorTagApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SensorTagApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SensorTagApp.dir/clean

CMakeFiles/SensorTagApp.dir/depend:
	cd /home/patryk/Dokumenty/SensorTagApp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patryk/Dokumenty/SensorTagApp /home/patryk/Dokumenty/SensorTagApp /home/patryk/Dokumenty/SensorTagApp/cmake-build-debug /home/patryk/Dokumenty/SensorTagApp/cmake-build-debug /home/patryk/Dokumenty/SensorTagApp/cmake-build-debug/CMakeFiles/SensorTagApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SensorTagApp.dir/depend

