#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "macros.h"
#include "lexer.h"
#include "lvalue.h"

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    printf("usage:\n"
           "\t%s file\n"
           "\n",
           *argv);
    exit(1);
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("main");
    exit(1);
  }

  struct stat fs;
  if (fstat(fd, &fs)) {
    perror("main");
    close(fd);
    exit(1);
  }
  size_t size = fs.st_size;

  char *src = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (src == MAP_FAILED) {
    perror("main");
    exit(1);
  }

  close(fd);

  struct lexer_t *lexer = lexer_construct(src, size);
  struct token_t token;
  while (lexer_lex1(lexer, &(struct token_t *){&token})) {
		printf("%s (%i) "tok_fmt" (%zu)\n", token_type_str[token.tt], token.tt, tok_fmta(lexer, token), token.position.length);
  }

	lexer_destroy(lexer);
	munmap(src, size);

/* 	alloc_zero(lcons, c1); */
/* 	alloc_zero(lcons, c2); */
/* 	alloc_zero(lcons, c3); */

/* 	c1->car = lvalue_wrap_int(1); */
/* 	c1->cdr = lvalue_wrap_cons(c2); */
/* 	c2->car.w = 0; */
/* 	c2->cdr = lvalue_wrap_cons(c3); */
/* 	c3->car = lvalue_wrap_int(3); */

/* 	print_lvalue(lvalue_wrap_cons(c1)); */
}
