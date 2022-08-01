/**
 * 测试ffmpeg
 */
#include "gtest/gtest.h"
#include "utils/Log.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "libavformat/avformat.h"
#ifdef __cplusplus
}
#endif
using namespace std;

namespace mplayer {
    TEST(mplayer_test, ffmpeg_config_test) {
        int version = avformat_version();
        ASSERT_GT(version, 0);
        LOG_INFO("avformat version : {}", version);
        const char *config = avformat_configuration();
        ASSERT_TRUE(config);
        LOG_INFO("avformat config : {}", config);
    }
}