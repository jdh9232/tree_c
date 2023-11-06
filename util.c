#include "util.h"

void* xalloc(size_t size)
{
	if (size < 1) {
		fprintf(stderr, "fatal: size error (malloc of %lu bytes).\n", size);
		perror("size error");
		assert(0);
	}

	void *p = malloc(size);
	if (is_null(p)) {
		fprintf(stderr, "fatal: memory exhausted (malloc of %lu bytes).\n", size);
		perror("malloc");
		assert(0);
	}
	return p;
}

void* xcalloc(size_t size)
{
	void *p = xalloc(size);
	memset(p, 0, size);
	return p;
}

void* xrealloc(void *ptr, size_t size)
{
	if (size < 1) {
		fprintf(stderr, "fatal: size error (realloc of %lu bytes).\n", size);
		perror("realloc size error");
		assert(0);
	}

	void *p = realloc(ptr, size);
	if (is_null(p)) {
		fprintf(stderr, "fatal: memory exhausted (realloc of %lu bytes).\n", size);
		perror("realloc");
		assert(0);
	}

	return p;
}

