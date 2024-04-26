#ifndef INCLUDED_LVALUE_H
#define INCLUDED_LVALUE_H

#include <assert.h>
#include <stdint.h>

enum lvalue_type {
  TYPE_NIL = 0,
  TYPE_INT,
  TYPE_TRUE,
  TYPE_SYM,
  TYPE_CONS,
  TYPE_FUNC,
  TYPE_MAXTYPE
};

#define lvalue_type(lvalue) ((struct lvalue_){.as.lval = lvalue}).as.tt
#define lvalue_shift 4
#define lvalue_get_int(lvalue) ((lvalue).w >> lvalue_shift)
#define lvalue_get_cons(lvalue) (lcons *)((lvalue).w >> lvalue_shift)
#define lvalue_value_width sizeof(struct lvalue) * 8 - lvalue_shift

typedef struct lvalue {
  uintptr_t w;
} lvalue;

typedef struct lcons {
  struct lvalue car;
  struct lvalue cdr;
} lcons;

struct lvalue_ {
  union {
    union {
      struct {
        uintptr_t tt : lvalue_shift;
        uintptr_t : lvalue_value_width;
      };
      struct {
        uintptr_t tti : lvalue_shift;
        intptr_t integer : lvalue_value_width;
      };
      struct {
        uintptr_t ttp : lvalue_shift;
        uintptr_t ptr : lvalue_value_width;
      };
    };
    struct lvalue lval;
  } as;
};

static_assert(sizeof(struct lvalue) == sizeof(struct lvalue_));

static inline bool lvalue_nil_p(lvalue lval) { return lval.w == 0; }
static inline bool lvalue_test(lvalue lval) { return lval.w; }
static inline bool lvalue_int_p(lvalue lval) {
  return lvalue_type(lval) == TYPE_INT;
}
static inline bool lvalue_sym_p(lvalue lval) {
  return lvalue_type(lval) == TYPE_SYM;
}
static inline bool lvalue_boolish_p(lvalue lval) {
  return (lval.w & ~(uintptr_t)TYPE_TRUE) == 0;
}
static inline bool lvalue_cons_p(lvalue lval) {
  return lvalue_type(lval) == TYPE_CONS;
}
static inline bool lvalue_func_p(lvalue lval) {
  return lvalue_type(lval) == TYPE_FUNC;
}

static inline lvalue lvalue_wrap_int(int64_t integer) {
  return (struct lvalue_){.as.tti = TYPE_INT, .as.integer = integer}.as.lval;
}

static inline lvalue lvalue_wrap_cons(lcons *cons) {
  return (struct lvalue_){.as.ttp = TYPE_CONS, .as.ptr = (uintptr_t)cons}
      .as.lval;
}

void print_lvalue(lvalue lval);
void print_cons_cell(lvalue lval);

#endif
