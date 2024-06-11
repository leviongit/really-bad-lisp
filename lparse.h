#ifndef INCLUDED_LPARSE_H
#define INCLUDED_LPARSE_H

#include <stdlib.h>

typedef void Token;
typedef void ASTNode;
typedef void Parser;

bool lisp_lexer_is_ws(char);
bool lisp_lexer_is_ident(char);
bool lisp_lexer_is_bin_num(char);
bool lisp_lexer_is_oct_num(char);
bool lisp_lexer_is_dec_num(char);
bool lisp_lexer_is_hex_num(char);

Parser *lisp_parser_construct(char *src, size_t srclen);
void lisp_parser_destroy(Parser *parser);
ASTNode *lisp_parser_parse(Parser *parser);

#endif /* INCLUDED_LPARSE_H */
