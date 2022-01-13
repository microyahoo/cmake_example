cmake_minimum_required(VERSION 3.20.4)

project (OLAS VERSION 1.0)

option(USER_ADDER "A simple library for adding 2 floats" ON)

# https://github.com/google/glog
find_package (glog 0.6.0 REQUIRED)

# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file (OLASConfig.h.in OLASConfig.h)

add_executable (${PROJECT_NAME} main.cpp)

target_include_directories (${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

if (USER_ADDER)
    add_subdirectory (Adder)
    list(APPEND EXTRA_LINKS "adder")
    list(APPEND EXTRA_INCLUDE_DIRS "Adder")
    list(APPEND EXTRA_LIB_DIRS "Adder")
endif()


find_package (Git QUIET)
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



target_include_directories (${PROJECT_NAME} PUBLIC 
    # "Adder"
    ${EXTRA_INCLUDE_DIRS}
    "external/glfw/include"
)

# target_link_directories(${PROJECT_NAME} PRIVATE
#     "Adder"
#     ${EXTRA_LIB_DIRS}
#     "external/glfw/src"
# )

target_link_libraries (${PROJECT_NAME} PUBLIC 
    # "adder"
    ${EXTRA_LINKS}
    "glfw"
    glog::glog
)

# target_link_libraries (${PROJECT_NAME} glog::glog)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h"  DESTINATION include)
