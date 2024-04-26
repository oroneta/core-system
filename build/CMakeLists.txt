cmake_minimum_required(VERSION 3.2)
project(DroneSystem)

set(CMAKE_CXX_STANDARD 17)
set(INCLUDE_PATHS ../src/h)

#Create the executable
add_executable(DroneSystem main_RouteServer.cpp)

target_include_directories(DroneSystem PUBLIC ${INCLUDE_PATHS})




