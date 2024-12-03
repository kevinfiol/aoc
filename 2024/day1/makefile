CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

all: main

main: main.c
	$(CC) $(CFLAGS) main.c -o main.o

run: main
	./main.o

clean:
	rm -f main.o

build-debug: main.c
	$(CC) $(CFLAGS) -g main.c -o main.o

debug: build-debug
	gdb ./main.o