#ifndef INCLUDED_ARENA_H
#define INCLUDED_ARENA_H

#include <stdlib.h>

#ifdef ARENA_IMPL

typedef struct {
	size_t capacity;
	size_t offset;
	char *ptr;
} Arena;

#else

typedef void Arena;

#endif

Arena *arena_construct(size_t capa);
Arena *arena_construct_nozero(size_t capa);
void arena_destroy(Arena *arena);

size_t arena_save_offset(Arena *arena);
bool arena_restore_offset(Arena *arena, size_t offset);

void *arena_allocate(Arena *arena, size_t size);
void *arena_allocate_nozero(Arena *arena, size_t size);

#endif /* INCLUDED_ARENA_H */
