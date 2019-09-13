cmake_minimum_required (VERSION 2.8)

# FreeSpeakerRecognition
project(FreeSR-Example)


SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)


# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/eigen3/) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/) 

# FreeSR Library
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)
link_libraries(freesr)

# Example
add_executable(freesr-example example/freesr-example.cc)

