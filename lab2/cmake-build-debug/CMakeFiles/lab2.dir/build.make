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
CMAKE_SOURCE_DIR = /home/daria/Desktop/clionprojects/mak_labs/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2.dir/flags.make

CMakeFiles/lab2.dir/main.c.o: CMakeFiles/lab2.dir/flags.make
CMakeFiles/lab2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2.dir/main.c.o   -c /home/daria/Desktop/clionprojects/mak_labs/lab2/main.c

CMakeFiles/lab2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daria/Desktop/clionprojects/mak_labs/lab2/main.c > CMakeFiles/lab2.dir/main.c.i

CMakeFiles/lab2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daria/Desktop/clionprojects/mak_labs/lab2/main.c -o CMakeFiles/lab2.dir/main.c.s

CMakeFiles/lab2.dir/create_window.c.o: CMakeFiles/lab2.dir/flags.make
CMakeFiles/lab2.dir/create_window.c.o: ../create_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab2.dir/create_window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2.dir/create_window.c.o   -c /home/daria/Desktop/clionprojects/mak_labs/lab2/create_window.c

CMakeFiles/lab2.dir/create_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/create_window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daria/Desktop/clionprojects/mak_labs/lab2/create_window.c > CMakeFiles/lab2.dir/create_window.c.i

CMakeFiles/lab2.dir/create_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/create_window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daria/Desktop/clionprojects/mak_labs/lab2/create_window.c -o CMakeFiles/lab2.dir/create_window.c.s

# Object files for target lab2
lab2_OBJECTS = \
"CMakeFiles/lab2.dir/main.c.o" \
"CMakeFiles/lab2.dir/create_window.c.o"

# External object files for target lab2
lab2_EXTERNAL_OBJECTS =

lab2: CMakeFiles/lab2.dir/main.c.o
lab2: CMakeFiles/lab2.dir/create_window.c.o
lab2: CMakeFiles/lab2.dir/build.make
lab2: /usr/lib/x86_64-linux-gnu/libOpenGL.so
lab2: /usr/lib/x86_64-linux-gnu/libGLX.so
lab2: /usr/lib/x86_64-linux-gnu/libGLU.so
lab2: /usr/lib/x86_64-linux-gnu/libglut.so
lab2: CMakeFiles/lab2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2.dir/build: lab2

.PHONY : CMakeFiles/lab2.dir/build

CMakeFiles/lab2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2.dir/clean

CMakeFiles/lab2.dir/depend:
	cd /home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daria/Desktop/clionprojects/mak_labs/lab2 /home/daria/Desktop/clionprojects/mak_labs/lab2 /home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug /home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug /home/daria/Desktop/clionprojects/mak_labs/lab2/cmake-build-debug/CMakeFiles/lab2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2.dir/depend

