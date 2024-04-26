#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "macros.h"

struct lexer_t *lexer_construct(const char *src, size_t len) {
  alloc_zero(struct lexer_t, lexer);
  lexer->src = src;
  lexer->len = len;
  return lexer;
}

void lexer_destroy(struct lexer_t *lexer) { free(lexer); }

static inline bool lexer_isatend(const struct lexer_t *lexer) {
  return lexer->at >= lexer->len;
}

static inline char lexer_peek(const struct lexer_t *lexer) {
  if (lexer_isatend(lexer))
    return 0;
  return lexer->src[lexer->at];
}

static inline bool lexer_isop(const char c) {
  return c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '-' ||
         c == '.' || c == '/' || c == ':' || c == '<' || c == '=' || c == '>' ||
				 c == '?' || c == '^' || c == '|' || c == '~';
}
static inline bool lexer_isother(const char c) { return c == '_'; }
static inline bool lexer_isdigit(const char c) { return isdigit(c); }
static inline bool lexer_isalpha(const char c) { return isalpha(c); }
static inline bool lexer_isalnum(const char c) { return isalnum(c); }
static inline bool lexer_isidbeg(const char c) {
  return lexer_isalpha(c) || lexer_isop(c) || lexer_isother(c);
}
static inline bool lexer_isident(const char c) {
  return lexer_isalnum(c) || lexer_isop(c) || lexer_isother(c);
}
static inline bool lexer_isspace(const char c) { return isspace(c); }

static inline void lexer_advance_(struct lexer_t *lexer) {
  if (!lexer_isatend(lexer))
    ++lexer->at;
}

static inline char lexer_advance(struct lexer_t *lexer) {
  if (lexer_isatend(lexer))
    return 0;
  return lexer->src[lexer->at++];
}

static inline char lexer_match(struct lexer_t *lexer, const char c) {
  if (lexer_isatend(lexer))
    return 0;
  const char cc = lexer_peek(lexer);
  if (cc == c) {
    lexer_advance_(lexer);
    return cc;
  }
  return 0;
}

static inline char lexer_matchf(struct lexer_t *lexer,
                                const lexer_charp_fun pred) {
  if (lexer_isatend(lexer))
    return 0;
  const char cc = lexer_peek(lexer);
  if (pred(cc)) {
    lexer_advance_(lexer);
    return cc;
  }
  return 0;
}

static inline void lexer_skipws(struct lexer_t *lexer) {
	while (lexer_matchf(lexer, lexer_isspace));
}

bool lexer_lex1(struct lexer_t *lexer, struct token_t **token) {
  if (lexer_isatend(lexer))
    return false;
  struct token_t _;
  struct token_t *tok;
  if (token == nullptr) {
    tok = &_;
  } else if (token != nullptr && *token == nullptr) {
    *token = malloc(sizeof(struct token_t));
    if (*token == nullptr) {
      perror("lexer_lex1");
      exit(1);
    }
    **token = (struct token_t){0};
    tok = *token;
  } else {
    tok = *token;
  }

	lexer_skipws(lexer);
  begin_tok(lexer);
  if (lexer_match(lexer, '(')) {
    tok->tt = TOKEN_LEFTPAREN;
  } else if (lexer_match(lexer, ')')) {
    tok->tt = TOKEN_RIGHTPAREN;
  } else if (lexer_matchf(lexer, lexer_isdigit)) {
    tok->tt = TOKEN_INT;
    while (lexer_matchf(lexer, lexer_isdigit))
      ;
  } else if (lexer_matchf(lexer, lexer_isidbeg)) {
    tok->tt = TOKEN_ID;
    while (lexer_matchf(lexer, lexer_isident))
      ;
  } else {
    if (lexer_isatend(lexer))
      tok->tt = TOKEN_EOF;
    else
      tok->tt = TOKEN_ERROR;

    lexer_advance_(lexer);
    return false;
  }

  end_tok(lexer);

  tok->position = lexer->position;

  return true;
}
