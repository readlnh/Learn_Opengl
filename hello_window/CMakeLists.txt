cmake_minimum_required (VERSION 2.8)
cmake_policy(VERSION 2.8)

project (hello_world)


link_directories(${CMAKE_SOURCE_DIR}/lib)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11")


find_package(OpenGL)
find_package(glfw3 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${OPENGL_INCLUDE_DIR})

add_library(GLAD SHARED "src/glad.c")
TARGET_LINK_LIBRARIES(GLAD dl)

set(LIBS ${LIBS} GLAD ${OPENGL_gl_LIBRARY} glfw)



add_executable(hello_world hello_window.cpp)

target_link_libraries(hello_world ${LIBS})



       

