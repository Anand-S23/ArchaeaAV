#include "archaea_memory.h"

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void *))
#endif

b8 is_power_of_two(unitptr_t x) {
    return (x & (x-1)) == 0;
}

uintptr_t align_forward(uintptr_t ptr, u64 align) {
	assert(is_power_of_two(align));
	uintptr_t modulo = ptr & ((uintptr_t)a - 1);
	if (modulo != 0) {
		ptr += (uintptr_t)align - modulo;
	}

	return ptr;
}

void *arena_alloc_align(arena_t *a, u64 size, u64 align) {
	uintptr_t current_ptr = (uintptr_t)a->buffer + (uintptr_t)a->current_offset;
	uintptr_t offset = align_forward(current_ptr, align);
	offset -= (uintptr_t)a->buffer;

	if (offset + size <= a->max_size) {
		void *ptr = &a->buffer[offset];
		a->previous_offset = offset;
		a->current_offset = offset + size;

		memset(ptr, 0, size);
		return ptr;
	}

    return NULL;
}

void *arena_alloc(arena_t *a, size_t size) {
	return arena_alloc_align(a, size, DEFAULT_ALIGNMENT);
}

void arena_init(arena_t *a, void *backing_buffer, size_t backing_buffer_length) {
	a->buffer = (unsigned char *)backing_buffer;
	a->max_size = backing_buffer_length;
	a->current_offset = 0;
	a->previous_offset = 0;
}

void arena_free(arena_t *a) {
	a->curr_offset = 0;
	a->prev_offset = 0;
}

temp_sub_arena_t temp_sub_arena_begin(arena_t *a) {
	return (temp_sub_arena_t) {
        .arena = a,
        .current_offset = a->current_offset,
        .previous_offset = a->previous_offset
    }; 
}

void temp_sub_arena_end(temp_sub_arena_t temp) {
	temp.arena->previous_offset = temp.previous_offset;
	temp.arena->current_offset = temp.current_offset;
}

