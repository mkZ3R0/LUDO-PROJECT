#include "utility.h"

void _sleep(unsigned int milli) {
    #ifdef _WIN32
    Sleep(milli);
    #else
    usleep(milli*1000);
    #endif
}
