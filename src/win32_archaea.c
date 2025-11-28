#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "win32_archaea.h"

static void *platform_allocate_memory(u64 size) {
    void *memory = VirtualAlloc(0, memory_size, MEM_COMMIT, PAGE_READWRITE);
    return memory;
}

static void platform_free_memory(void *memory, u64 size) {
    if (memory) {
        VirutalFree(memory, size, MEM_DECOMMIT);
    }
}

