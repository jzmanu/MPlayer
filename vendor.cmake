# 链接ffmpeg库的目录
function(link_ffmpeg_directory)
    link_directories(${ffmpeg_dir}/lib)
endfunction()

# 链接ffmpeg中的库
function(link_ffmpeg_library target)
    target_link_libraries(${target}
            avformat
            avcodec
            avdevice
            avfilter
            avutil
            swresample
            swscale)
endfunction()