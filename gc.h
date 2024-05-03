#ifndef INCLUDED_GC_H
#define INCLUDED_GC_H

#include "lobj.h"
#include <stdint.h>

#define GC_PAGESIZE 512

struct lgc {
  struct lgc_page *fstpg;
  struct lgc_page *lastpg;
};

struct lgc_page {
  struct gc_page *next;
  struct lispobj objs[GC_PAGESIZE];
  uint16_t count;
};

#endif /* INCLUDED_GC_H */
