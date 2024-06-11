#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MALLOC_H_IMPL
#include "malloc.h"

[[gnu::malloc]] void *xmalloc(unsigned long size, const char *msg) {
	void *ptr = malloc(size);

	if (ptr == nullptr) {
		perror(msg);
		exit(errno);
	}

	return ptr;
}

void xfree(void *ptr, const char *msg) {
	free(ptr);
}

void *xrealloc(void *ptr, unsigned long size, const char *msg) {
	void *new_ptr = realloc(ptr, size);

	if (new_ptr == nullptr) {
		perror(msg);
		exit(errno);
	}

	return ptr;
}
