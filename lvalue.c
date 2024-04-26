#include "lvalue.h"
#include <assert.h>
#include <stdio.h>

void print_lvalue(lvalue lval) {
  assert(lvalue_type(lval) < TYPE_MAXTYPE);

  switch (lvalue_type(lval)) {
  case TYPE_NIL:
    printf("nil");
    return;
  case TYPE_INT:
    printf("%ld", lvalue_get_int(lval));
    return;
  case TYPE_TRUE:
    printf("#t");
    return;
  case TYPE_SYM:
    printf("[[no]]");
    return;
  case TYPE_CONS:
    return print_cons_cell(lval);
  case TYPE_FUNC:
    printf("[[no (function)]]");
    return;
  default:
    __builtin_unreachable();
  }
}

void print_cons_cell(lvalue lval) {
  assert(lvalue_cons_p(lval));
  lcons *cons = lvalue_get_cons(lval);

  printf("(");

  print_lvalue(cons->car);

  printf(" . ");

  print_lvalue(cons->cdr);
  printf(")");
}
