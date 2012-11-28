.PHONY: all clean dist
.SUFFIXES: .c .o .h .asm

all: scmp

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)


%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<

scmp: scmp.o cmp.o
	gcc $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *~
