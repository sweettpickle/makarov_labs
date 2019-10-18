cmake_minimum_required(VERSION 3.15)
project(laba1 C)

set(CMAKE_C_STANDARD 11)

add_executable(laba1
        main.c library.h)


#for windows or linux
#include <GL/glew.h>
#include <GL/glut.h>

#for all:
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(laba1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


#for mac:
#-lm -framework OpenGL -framework Glut
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
