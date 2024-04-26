CC = clang
CFLAGS = -std=c2x -g

lisp: lvalue.o lexer.o parser.o rt.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
