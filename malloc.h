#ifndef INCLUDED_MALLOC_H
#define INCLUDED_MALLOC_H

[[gnu::malloc]] void *xmalloc(unsigned long size, const char *msg);
void xfree(void *ptr, const char *msg);
void *xrealloc(void *ptr, unsigned long size, const char *msg);

#ifndef MALLOC_H_IMPL
#define malloc_stringify2(MACRO) #MACRO
#define malloc_stringify(MACRO) malloc_stringify2(MACRO)
#define malloc_xmalloc_internal(SIZE, FILE, LINE) xmalloc(SIZE, "[" FILE ":" malloc_stringify(LINE) "]")
#define malloc(SIZE) malloc_xmalloc_internal(SIZE, __FILE__, __LINE__)
#define malloc_xfree_internal(PTR, FILE, LINE) xfree(PTR, "[" FILE ":" malloc_stringify(LINE) "]")
#define free(PTR) malloc_xfree_internal(PTR, __FILE__, __LINE__)
#define malloc_xrealloc_internal(PTR, SIZE, FILE, LINE)  xrealloc(PTR, SIZE, "[" FILE ":" malloc_stringify(LINE) "]")
#define realloc(PTR, SIZE) malloc_xrealloc_internal(PTR, SIZE, __FILE__, __LINE__)
#endif

#endif /* INCLUDED_MALLOC_H */
