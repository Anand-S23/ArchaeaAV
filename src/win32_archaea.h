#ifndef WIN32_ARCHAEA_H
#define WIN32_ARCHAEA_H

static void *platform_allocate_memory(u64 size);
static void platform_free_memory(void *memory, u64 size);

#endif
