#ifndef ARCHAEA_MEMORY_H
#define ARCHAEA_MEMORY_H

// Arenas: https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-001/

typedef struct arena {
    u8 *buffer;
    u64 max_size;
    u64 current_offset;
    u64 previous_offset;
} arena_t;

typedef struct temp_sub_arena {
    arena_t arena;
    u64 current_offset;
    u64 previous_offset;
} temp_sub_arena_t;

#endif // !ARCHAEA_MEMORY_H
