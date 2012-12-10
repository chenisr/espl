.PHONY: all clean
.SUFFIXES: .c .o .h .asm

all: main

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)


%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<

main:  main.o

	    gcc $(LDFLAGS) -o $@ $^

main.o: main.asm


clean:
	rm -f *.o *~

