cmake_minimum_required(VERSION 3.20)
project(MPlayer)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/vendor.cmake)

# 添加三方库头文件的依赖
list(APPEND MPLAYER_INCLUDES ${ffmpeg_dir}/include)
list(APPEND MPLAYER_INCLUDES ${third_party_dir}/include)

# SDK 的源文件
file(GLOB_RECURSE MPLAYER_SRC src/*.*)

# 编译SDK的静态库
add_library(MPlayer STATIC ${MPLAYER_SRC})

# 包含头文件内容
target_include_directories(MPlayer PUBLIC ${MPLAYER_INCLUDES})
#include_directories(${MPLAYER_INCLUDES})

#target_link_libraries(MPlayer gtest)

link_ffmpeg_directory()
#add_executable(MTEST ${MPLAYER_SRC})
link_ffmpeg_library(MPlayer)
#link_ffmpeg_library(MTEST)
link_spdlog_library(MPlayer)

# GoogleTest
add_subdirectory(./3rdparty/googletest)
# GoogleTest头文件
set(MPlayer_TEST_INCLUDES 3rdparty/googletest/googletest 3rdparty/googletest/googletest/include
        3rdparty/googletest/googlemock/include)
# 测试源文件
file(GLOB_RECURSE MPlayer_TEST_FILES
        test/*.*
        test/src/googletest/*.*
        test/src/ffmpeg_test/*.*
        test/src/spdlog/*.*
        )
# SDK头文件添加到测试的头文件里面
list(APPEND MPlayer_TEST_INCLUDES ${MPLAYER_INCLUDES})

add_executable(MPlayerUnitTest ${MPlayer_TEST_FILES})
target_include_directories(MPlayerUnitTest PUBLIC ${MPlayer_TEST_INCLUDES})
target_link_libraries(MPlayerUnitTest MPlayer gtest)
# -fno-access-control是gcc编译器选项，可以直接开启访问私有属性，主要多用于单元测试
set_target_properties(MPlayerUnitTest PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -fno-access-control")