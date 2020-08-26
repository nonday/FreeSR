cmake_minimum_required (VERSION 2.8)

# FreeSpeakerRecognition
project(FreeSR-Example)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# FreeSR Library
include_directories(include/) 
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)
link_libraries(freesr)

# Example
add_executable(freesr-example example/freesr-example.cc)
add_executable(freesr-gender-example example/freesr-gender-example.cc)
