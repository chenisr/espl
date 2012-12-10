#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "xsum.h"

int old_main(int argc, char **argv) 
{
  char c;
  int x=0,j=1;
  int maxBytes=32;
    FILE* file_read_pointer;
    file_read_pointer = fopen(argv[optind], "r");
    FILE* file_write_pointer;
    int buffer[maxBytes/sizeof(int)];
    char *origin=argv[optind];
    char name[20];
    int numRead;
    while ((numRead=(fread(buffer, 1,maxBytes, file_read_pointer))))
    {
	sprintf(name, "%s.%d", origin, j);
        file_write_pointer = fopen(name, "w");
	//fprintf(file_write_pointer,"%x",tmp);
 	fwrite(buffer, 1,numRead ,file_write_pointer);
	j++;
	memset(buffer,0,sizeof(buffer));
    }
    return 0;
} 

 
