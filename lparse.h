#ifndef INCLUDED_LPARSE_H
#define INCLUDED_LPARSE_H

#include <stdlib.h>

typedef void ASTNode;
typedef void Parser;

Parser *lisp_parser_construct(char *src, size_t srclen);
void lisp_parser_destroy(Parser *parser);
ASTNode *lisp_parser_parse(Parser *parser);

#endif /* INCLUDED_LPARSE_H */
