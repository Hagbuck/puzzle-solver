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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kurai/WorkSpace/Clicker/puzzle-solver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kurai/WorkSpace/Clicker/puzzle-solver

# Include any dependencies generated for this target.
include CMakeFiles/lectureImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lectureImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lectureImage.dir/flags.make

CMakeFiles/lectureImage.dir/main.cpp.o: CMakeFiles/lectureImage.dir/flags.make
CMakeFiles/lectureImage.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurai/WorkSpace/Clicker/puzzle-solver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lectureImage.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lectureImage.dir/main.cpp.o -c /home/kurai/WorkSpace/Clicker/puzzle-solver/main.cpp

CMakeFiles/lectureImage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lectureImage.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurai/WorkSpace/Clicker/puzzle-solver/main.cpp > CMakeFiles/lectureImage.dir/main.cpp.i

CMakeFiles/lectureImage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lectureImage.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurai/WorkSpace/Clicker/puzzle-solver/main.cpp -o CMakeFiles/lectureImage.dir/main.cpp.s

CMakeFiles/lectureImage.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lectureImage.dir/main.cpp.o.requires

CMakeFiles/lectureImage.dir/main.cpp.o.provides: CMakeFiles/lectureImage.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lectureImage.dir/build.make CMakeFiles/lectureImage.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lectureImage.dir/main.cpp.o.provides

CMakeFiles/lectureImage.dir/main.cpp.o.provides.build: CMakeFiles/lectureImage.dir/main.cpp.o


CMakeFiles/lectureImage.dir/inputReader.cpp.o: CMakeFiles/lectureImage.dir/flags.make
CMakeFiles/lectureImage.dir/inputReader.cpp.o: inputReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurai/WorkSpace/Clicker/puzzle-solver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lectureImage.dir/inputReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lectureImage.dir/inputReader.cpp.o -c /home/kurai/WorkSpace/Clicker/puzzle-solver/inputReader.cpp

CMakeFiles/lectureImage.dir/inputReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lectureImage.dir/inputReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurai/WorkSpace/Clicker/puzzle-solver/inputReader.cpp > CMakeFiles/lectureImage.dir/inputReader.cpp.i

CMakeFiles/lectureImage.dir/inputReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lectureImage.dir/inputReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurai/WorkSpace/Clicker/puzzle-solver/inputReader.cpp -o CMakeFiles/lectureImage.dir/inputReader.cpp.s

CMakeFiles/lectureImage.dir/inputReader.cpp.o.requires:

.PHONY : CMakeFiles/lectureImage.dir/inputReader.cpp.o.requires

CMakeFiles/lectureImage.dir/inputReader.cpp.o.provides: CMakeFiles/lectureImage.dir/inputReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/lectureImage.dir/build.make CMakeFiles/lectureImage.dir/inputReader.cpp.o.provides.build
.PHONY : CMakeFiles/lectureImage.dir/inputReader.cpp.o.provides

CMakeFiles/lectureImage.dir/inputReader.cpp.o.provides.build: CMakeFiles/lectureImage.dir/inputReader.cpp.o


# Object files for target lectureImage
lectureImage_OBJECTS = \
"CMakeFiles/lectureImage.dir/main.cpp.o" \
"CMakeFiles/lectureImage.dir/inputReader.cpp.o"

# External object files for target lectureImage
lectureImage_EXTERNAL_OBJECTS =

bin/lectureImage: CMakeFiles/lectureImage.dir/main.cpp.o
bin/lectureImage: CMakeFiles/lectureImage.dir/inputReader.cpp.o
bin/lectureImage: CMakeFiles/lectureImage.dir/build.make
bin/lectureImage: /usr/local/lib/libopencv_dnn.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_highgui.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_ml.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_objdetect.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_shape.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_stitching.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_superres.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_videostab.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_calib3d.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_features2d.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_flann.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_photo.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_video.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_videoio.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_imgcodecs.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_imgproc.so.3.4.7
bin/lectureImage: /usr/local/lib/libopencv_core.so.3.4.7
bin/lectureImage: CMakeFiles/lectureImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kurai/WorkSpace/Clicker/puzzle-solver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/lectureImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lectureImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lectureImage.dir/build: bin/lectureImage

.PHONY : CMakeFiles/lectureImage.dir/build

CMakeFiles/lectureImage.dir/requires: CMakeFiles/lectureImage.dir/main.cpp.o.requires
CMakeFiles/lectureImage.dir/requires: CMakeFiles/lectureImage.dir/inputReader.cpp.o.requires

.PHONY : CMakeFiles/lectureImage.dir/requires

CMakeFiles/lectureImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lectureImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lectureImage.dir/clean

CMakeFiles/lectureImage.dir/depend:
	cd /home/kurai/WorkSpace/Clicker/puzzle-solver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kurai/WorkSpace/Clicker/puzzle-solver /home/kurai/WorkSpace/Clicker/puzzle-solver /home/kurai/WorkSpace/Clicker/puzzle-solver /home/kurai/WorkSpace/Clicker/puzzle-solver /home/kurai/WorkSpace/Clicker/puzzle-solver/CMakeFiles/lectureImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lectureImage.dir/depend

