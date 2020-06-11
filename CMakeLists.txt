cmake_minimum_required (VERSION 2.8)

# FreeSpeakerRecognition
project(FreeSR-Example)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 3rd party
include_directories(3rdparty/eigen3/)
include_directories(3rdparty/libtorch1.4/include/)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libtorch1.4/lib/)
link_libraries(c10 torch)

# FreeSR Library
include_directories(include/) 
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)
link_libraries(freesr)

# Example
add_executable(freesr-xvector-example example/freesr-xvector-example.cc)
add_executable(freesr-xvector-gender-example example/freesr-xvector-gender-example.cc)
add_executable(freesr-ubm-example example/freesr-ubm-example.cc)
add_executable(freesr-ubm-gender-example example/freesr-ubm-gender-example.cc)
add_executable(freesr-ivector-example example/freesr-ivector-example.cc)
