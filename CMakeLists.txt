cmake_minimum_required(VERSION 3.20)
project(MPlayer)

set(CMAKE_CXX_STANDARD 11)

# GoogleTest
add_subdirectory(3rdparty/googletest)
include_directories(3rdparty/googletest/googletest/include)

add_executable(MPlayer main.cpp)

# GoogleTest samples
add_executable(test_google_test test/test_google_test.cpp)
target_link_libraries(test_google_test gtest)