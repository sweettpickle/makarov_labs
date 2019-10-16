cmake_minimum_required(VERSION 3.15)
project(laba1 C)

set(CMAKE_C_STANDARD 99)

#set(OpenGlLinkers -lglut -lGLU -lGL)
#include_directories(GL)
# target_link_libraries(OpenGL GL/Glaux.lib GL/GLU32.LIB GL/glui32.lib GL/glut32.lib GL/OPENGL32.LIB)

find_package(OpenGL REQUIRED)


#find_package(GLEW REQUIRED)
#
#include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})
# include_directories(OpenGL)
# add_link_options(-framework OpenGL )
#find_library(GL_LIB GL
#        PATH
#        /)

#link_libraries(${GL_LIB})

add_executable(laba1 main.c)

#ADD_DEFINITIONS(
#        -lGL
#        -lGLU
#        -lGLEW
#        -lglfw
#)

#target_link_libraries(laba1 ${OpenGlLinkers})

#target_link_libraries(GL GLU GLEW glfw)

#target_link_libraries(laba1 ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

