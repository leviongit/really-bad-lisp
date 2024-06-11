#define ARENA_IMPL
#include "arena.h"

Arena *arena_construct(size_t capa) {
	Arena *arena = malloc(sizeof(Arena));

	arena->offset = 0;

	char *ptr = malloc(capa);
	arena->ptr = ptr;
	arena->capacity = capa;
	
	return arena;
}


void arena_destroy(Arena *arena) {
	free(arena->ptr);
	free(arena);
}

size_t arena_save_offset(Arena *arena) {
	return arena->offset;
}

bool arena_restore_offset(Arena *arena, size_t offset) {
	if (offset > 0 && offset < arena->capacity) {
		arena->offset = offset;
		return true;
	}

	return false;
}

void *arena_allocate(Arena *arena, size_t size) {
	if (arena->capacity - arena->offset < size) return nullptr;

	void *ptr = arena->ptr;

	arena->offset += size;

	char *end = arena->ptr;
	for (char *p = ptr; p < end; ++p) {
		*p = 0;
	}
	
	return ptr;
}

void *arena_allocate_nozero(Arena *arena, size_t size) {
	if (arena->capacity - arena->offset < size) return nullptr;

	void *ptr = arena->ptr;

	arena->offset += size;

	return ptr;
}
