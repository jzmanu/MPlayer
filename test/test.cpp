/**
 * 测试GoogleTest单元测试框架
 */
#include <iostream>
#include <gtest/gtest.h>
#include "utils/Log.h"

extern "C" {
#include "libavformat/avformat.h"
}

int main() {
    ::testing::TestEventListeners &listeners = testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new testing::EmptyTestEventListener());
//    AddGlobalTestEnvironment(new planet::PlanetEnvironment());
    ::testing::InitGoogleTest();
    mplayer::Log::init();
    return RUN_ALL_TESTS();
}
