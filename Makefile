CC=clang
CFLAGS=-O2
LDFLAGS=-lncurses -ltinfo
EXEC=out

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)


all: $(OBJ)
	$(CC) $(EXEC) $^ $(LDFLAGS)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

run: all
	./$(EXEC)

clean:
	rm -f src/*.o
	[ ! -e $(EXEC) ]  || rm ./$(EXEC)
