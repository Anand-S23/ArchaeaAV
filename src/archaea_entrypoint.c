#include "archaea.h"

#if defined(_WIN32) || defined(_WIN64)
    #include "win32_archaea.c"
#elif defined(__LINUX__)
    #include "linux_archaea.c"
#elif defined(__APPLE__)
    // TODO: Support apple
#endif

archaea_platform_t global_platform = {0};

int main(void) {
    return 0;
}
