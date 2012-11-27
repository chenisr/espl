#include <stdlib.h>
#include <stdio.h>

extern int malami(char*);

int main(int argc, char **argv) {
	char* c="124";
	printf ("%d\n",malami(c));

	return 0;
}
