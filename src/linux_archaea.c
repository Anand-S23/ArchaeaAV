#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <x86intrin.h>
#define _GNU_SOURCE
#include <dlfcn.h>

#include "linux_archaea.h"

static void *platform_allocate_memory(u64 size) {
    void *memory = mmap(0, size, PROT_READ | PROT_WRITE,
                        MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    return memory;
}

static void platform_free_memory(void *memory, u64 size) {
    if (memory) {
        munmap(memory, size);
    }
}

