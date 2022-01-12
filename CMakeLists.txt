cmake_minimum_required(VERSION 3.20.4)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory (Adder)
add_subdirectory (external/glfw)
target_link_libraries (${PROJECT_NAME} adder)
