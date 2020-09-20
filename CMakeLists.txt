cmake_minimum_required(VERSION 3.5)

project(sockChat)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

add_executable(sockServer "${source_dir}/server.cpp")
add_executable(sockClient "${source_dir}/client.cpp")