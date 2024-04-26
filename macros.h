#ifndef INCLUDED_MACROS_H
#define INCLUDED_MACROS_H

#define alloc_zero(type, name)                                                 \
  type *name = malloc(sizeof(type));                                           \
  *name = (type) {}

#endif
