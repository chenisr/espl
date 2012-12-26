# generic rule for compiling C files

CFLAGS=-g -O -Wall

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $<

%: %.o
	gcc $(CFLAGS) -o $@ $<

all: secret-elf-d secred-elf-e

secret-elf-d: secret-elf-b secret-elf-c
                gcc -o secret-elf-d secret-elf-b secret-elf-c

secret-elf-e: secret-elf-a secret-elf-c
               gcc -o secret-elf-e secret-elf-a secret-elf-c
clean:
	rm -f *.o