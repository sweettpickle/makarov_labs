# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/92/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/92/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daria/Desktop/clionprojects/mak_labs/laba1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laba1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba1.dir/flags.make

CMakeFiles/laba1.dir/line_here.c.o: CMakeFiles/laba1.dir/flags.make
CMakeFiles/laba1.dir/line_here.c.o: ../line_here.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/laba1.dir/line_here.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/laba1.dir/line_here.c.o   -c /home/daria/Desktop/clionprojects/mak_labs/laba1/line_here.c

CMakeFiles/laba1.dir/line_here.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/laba1.dir/line_here.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daria/Desktop/clionprojects/mak_labs/laba1/line_here.c > CMakeFiles/laba1.dir/line_here.c.i

CMakeFiles/laba1.dir/line_here.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/laba1.dir/line_here.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daria/Desktop/clionprojects/mak_labs/laba1/line_here.c -o CMakeFiles/laba1.dir/line_here.c.s

CMakeFiles/laba1.dir/create_window.c.o: CMakeFiles/laba1.dir/flags.make
CMakeFiles/laba1.dir/create_window.c.o: ../create_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/laba1.dir/create_window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/laba1.dir/create_window.c.o   -c /home/daria/Desktop/clionprojects/mak_labs/laba1/create_window.c

CMakeFiles/laba1.dir/create_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/laba1.dir/create_window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daria/Desktop/clionprojects/mak_labs/laba1/create_window.c > CMakeFiles/laba1.dir/create_window.c.i

CMakeFiles/laba1.dir/create_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/laba1.dir/create_window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daria/Desktop/clionprojects/mak_labs/laba1/create_window.c -o CMakeFiles/laba1.dir/create_window.c.s

# Object files for target laba1
laba1_OBJECTS = \
"CMakeFiles/laba1.dir/line_here.c.o" \
"CMakeFiles/laba1.dir/create_window.c.o"

# External object files for target laba1
laba1_EXTERNAL_OBJECTS =

laba1: CMakeFiles/laba1.dir/line_here.c.o
laba1: CMakeFiles/laba1.dir/create_window.c.o
laba1: CMakeFiles/laba1.dir/build.make
laba1: /usr/lib/x86_64-linux-gnu/libOpenGL.so
laba1: /usr/lib/x86_64-linux-gnu/libGLX.so
laba1: /usr/lib/x86_64-linux-gnu/libGLU.so
laba1: /usr/lib/x86_64-linux-gnu/libglut.so
laba1: CMakeFiles/laba1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable laba1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laba1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba1.dir/build: laba1

.PHONY : CMakeFiles/laba1.dir/build

CMakeFiles/laba1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laba1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laba1.dir/clean

CMakeFiles/laba1.dir/depend:
	cd /home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daria/Desktop/clionprojects/mak_labs/laba1 /home/daria/Desktop/clionprojects/mak_labs/laba1 /home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug /home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug /home/daria/Desktop/clionprojects/mak_labs/laba1/cmake-build-debug/CMakeFiles/laba1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba1.dir/depend

