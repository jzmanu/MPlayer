/**
 * @brief 日志
 * @author jzman
 * @date 2022/8/1 14:28.
 */
#ifndef MPLAYER_LOG_H
#define MPLAYER_LOG_H

#include <spdlog/spdlog.h>

#define LOG_TRACE(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::trace, __VA_ARGS__)
#define LOG_INFO(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::info, __VA_ARGS__)
#define LOG_DEBUG(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::debug, __VA_ARGS__)
#define LOG_WARN(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::warn, __VA_ARGS__)
#define LOG_ERROR(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::error, __VA_ARGS__)
#define LOG_CRITICAL(...) \
    SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::critical, __VA_ARGS__)
namespace mplayer {
    class Log {
    private:
        // logger声明
        static std::shared_ptr<spdlog::logger> mCoreLogger;
    public:
        // Log初始化函数
        static void init();

        static std::shared_ptr<spdlog::logger> &getCoreLogger() {
            return mCoreLogger;
        }
    };
}

#endif //MPLAYER_LOG_H
