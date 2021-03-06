# os
if (WIN32)
    set(os win)
elseif (APPLE)
    set(os mac)
else ()
    message(FATAL_ERROR "not support current platform")
endif ()

message(STATUS "this machine arch is ${arch}")
message(STATUS "this machine platform is ${os}")

# arch
if (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
    set(arch arm64)
elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
    set(arch x64)
else ()
    message(FATAL_ERROR "not support current arch")
endif ()

# path
#set(ffmpeg_dir ${CMAKE_CURRENT_SOURCE_DIR}/lib/${os}/${arch})
set(ffmpeg_dir G:/Study/AV/ffmpeg/ffmpeg)
set(third_party_dir G:/Study/AV/MPlayer/3rdparty/spdlog)