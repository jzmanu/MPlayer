/**
 * 测试ffmpeg
 */
#include "gtest/gtest.h"

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
        cout << "version:" << version << endl;
        const char *config = avformat_configuration();
        ASSERT_TRUE(config);
        cout << "config:" << config << endl;
    }
}