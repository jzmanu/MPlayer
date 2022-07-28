/**
 * sdglog日志框架测试
 */
#include "gtest/gtest.h"
#include "spdlog/spdlog.h"

namespace mplayer {
    TEST(mplayer_test, spdlog_test) {
        spdlog::info("Welcome to spdlog version {}.{}.{} !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
                     SPDLOG_VER_PATCH);
        spdlog::warn("test spdlog warn log");
    }
}
