#ifndef INCLUDED_LOBJ_H
#define INCLUDED_LOBJ_H

#include <stdint.h>

enum lisptype: uint8_t {
	LISP_TYPE_NIL = 0,
	LISP_TYPE_INT,
	LISP_TYPE_SYM,
	LISP_TYPE_TRUE,
	LISP_TYPE_PAIR,
	LISP_TYPE_FUNC,
	LISP_TYPE_MACRO
};



struct lispobj {
	union {
		int64_t integer;
		
	} as;
	enum lisptype type;
};

#endif /* INCLUDED_LOBJ_H */
