cmake_minimum_required(VERSION 3.2)
project(DroneSystem)

set(CMAKE_CXX_STANDARD 17)


#Create the executable
add_executable(DroneSystem main.cpp)

target_include_directories(DroneSystem PUBLIC ${INCLUDE_PATHS})


#Create the executable
add_executable(DroneSystem main.cpp)




