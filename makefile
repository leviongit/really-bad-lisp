CC = clang
CFLAGS = -std=c2x -g

SRCS=

lisp: $(SRCS:%.c=%.o)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
