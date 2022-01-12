cmake_minimum_required(VERSION 3.20.4)

project(OLAS VERSION 1.0)

configure_file(OLASConfig.h.in OLASConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory (Adder)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

add_subdirectory (external/glfw)

# target_include_directories()
target_include_directories(${PROJECT_NAME} PUBLIC 
    "Adder"
    "external/glfw/include"
)

# target_link_directories(${PROJECT_NAME} PRIVATE
#     "Adder"
#     "external/glfw/src"
# )

target_link_libraries (${PROJECT_NAME} PUBLIC 
    "adder"
    "glfw"
)
