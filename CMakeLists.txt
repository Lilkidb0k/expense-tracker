cmake_minimum_required(VERSION 3.20)
project(NetworkFramework)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/Include)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(NetworkFramework ${PROJECT_SOURCE_DIR}/main.cpp ${SOURCES})

if (WIN32)
    target_link_libraries(NetworkFramework ws2_32)
endif()
