#ifndef INCLUDED_LEXER_H
#define INCLUDED_LEXER_H

#include <stddef.h>

typedef bool (*lexer_charp_fun)(char);

enum token_type {
  TOKEN_ERROR = 0,
  TOKEN_LEFTPAREN,
  TOKEN_RIGHTPAREN,
  TOKEN_ID,
  TOKEN_INT,
  TOKEN_EOF,
  TOKEN_MAXTOKEN
};

static const char *token_type_str[] = {
    "T_ERROR", "T_LEFTPAREN", "T_RIGHTPAREN", "T_ID",
    "T_INT",   "T_EOF",       "T_MAXTOKEN"};

struct position_t {
  size_t offset;
  size_t length;
};

struct token_t {
  enum token_type tt;
  struct position_t position;
};

struct lexer_t {
  const char *src;
  size_t at;
  size_t len;
  struct position_t position;
};

struct lexer_t *lexer_construct(const char *src, size_t len);
void lexer_destroy(struct lexer_t *lexer);
bool lexer_lex1(struct lexer_t *lexer, struct token_t **token);

#define begin_tok(lexer)                                                       \
  do {                                                                         \
    struct lexer_t *ll = (lexer);                                              \
    ll->position.offset = ll->at;                                              \
    ll->position.length = 0;                                                   \
  } while (0)
#define end_tok(lexer)                                                         \
  do {                                                                         \
    struct lexer_t *ll = (lexer);                                              \
    ll->position.length = ll->at - ll->position.offset;                        \
  } while (0)

#define tok_fmt "%.*s"
#define tok_fmta(lexer, tok) (int){(tok).position.length}, &lexer->src[(tok).position.offset]

#endif
