#include <iostream>
extern "C" {
#include "libavformat/avformat.h"
}
using namespace std;
int main() {
    int version = avformat_version();
    const char* config = avformat_configuration();
    cout << "version:" << version << endl;
    cout << "config:" << config << endl;
    return 0;
}
