#ifndef INCLUDED_LLEX_H
#define INCLUDED_LLEX_H

#include <stdint.h>
#include <stdlib.h>

#include "typedefs.h"
#include "arena.h"

enum TokenType : uint8_t {
  TOKEN_TYPE_NIL = 0,
  TOKEN_TYPE_TRUE,
  TOKEN_TYPE_FALSE,
  TOKEN_TYPE_INTEGER,
  TOKEN_TYPE_FLOAT,
  /* TOKEN_TYPE_STRING, */
  TOKEN_TYPE_ATOM,
  TOKEN_TYPE_LPAREN,
  TOKEN_TYPE_RPAREN,
  TOKEN_TYPE_APOSTRPHE,

  TOKEN_TYPE_UNKNOW = 0xfe,
  TOKEN_TYPE_ERROR = 0xff,
};

typedef struct Token {
  char const *const pos;
  size_t len;
  union {
    bool boolean;
    long integer;
    double real; // nearly
  } as;
  enum TokenType type;
} Token;

typedef struct TokenList {
  Token tokens[255];
  struct TokenList *prev;
  struct TokenList *next;
  u8 used;
} TokenList;

typedef struct Lexer {
  const char *src;
  size_t len;
  size_t idx;
	Arena *arena;
  TokenList *token_list_fst;
  TokenList *token_list_curr;
} Lexer;

Lexer *lisp_lexer_construct(char const *const src, size_t len, Arena *arena);
void lisp_lexer_destroy(Lexer *lexer);

bool lisp_lexer_is_ws(char);
bool lisp_lexer_is_ident_begin(char);
bool lisp_lexer_is_ident(char);
bool lisp_lexer_is_bin_num(char);
bool lisp_lexer_is_oct_num(char);
bool lisp_lexer_is_dec_num(char);
bool lisp_lexer_is_hex_num(char);

Token lisp_lexer_lex1(Lexer *lexer);
TokenList *lisp_lexer_lex_all(Lexer *lexer);

#endif /* INCLUDED_LLEX_H */
