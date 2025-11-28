#include "archaea.h"

#if defined(_WIN32) || defined(_WIN64)
    #include "win32_archaea.c"
#elif defined(__LINUX__)
    #include "linux_archaea.c"
#elif defined(__APPLE__)
    // TODO: Support apple
#endif

int main(void) {
    return 0;
}
