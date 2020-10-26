cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(sockChat)

#[[
if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /Wall")
endif()
]]

set(source_dir "${PROJECT_SOURCE_DIR}/src/")

add_executable(sockServer "${source_dir}/server.cpp")
add_executable(sockClient "${source_dir}/client.cpp")