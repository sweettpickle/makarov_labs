cmake_minimum_required(VERSION 3.15)
project(lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2 main.c library.h create_window.c)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(lab2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
