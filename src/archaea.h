#ifndef ARCHAEA_H
#define ARCHAEA_H

#include <stdint.h>

// Signed Integers
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
//
// Unsigned Integers
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// Booleans
typedef int8_t   b8;
typedef int16_t  b16;
typedef int32_t  b32;
typedef int64_t  b64;

// Floats
typedef float    f32;
typedef double   f64;

typedef struct archaea_platform {
    void *memory;
    u64 memory_size;
} archaea_platform_t;

#endif
