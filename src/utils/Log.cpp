/**
 * @brief 日志
 * @author jzman
 * @date 2022/8/1 14:28.
 */
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Log.h"

namespace mplayer {
    std::shared_ptr<spdlog::logger> Log::mCoreLogger;
    void mplayer::Log::init() {
        // 每个logger可以有多个sink
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>()); // 标准输出
        logSinks.emplace_back(
                std::make_shared<spdlog::sinks::basic_file_sink_mt>("MPlayer.txt", true)); // 文件输出
        // 设置日志格式
        logSinks[0]->set_pattern("%^[%Y-%m-%d %T] [%P %t] %n: %v");
        logSinks[1]->set_pattern("[%Y-%m-%d %T] [%P %t] %n: %v");
        // 创建logger
        mCoreLogger = std::make_shared<spdlog::logger>("MPlayer", begin(logSinks), end(logSinks));
        // 全局注册logger
        spdlog::register_logger(mCoreLogger);
        mCoreLogger->set_level(spdlog::level::trace);
        // 实时刷新日志
        mCoreLogger->flush_on(spdlog::level::trace);
    }
}


