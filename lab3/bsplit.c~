#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "xsum.h"

int main(int argc, char **argv) 
{
  char c;
  int x=0,j=1;
  int maxBytes=32;
  while((c=getopt (argc, argv, "b:hx"))!=-1)
  { 
	 switch (c) 
	{
	  case 'b':
	      maxBytes=atoi(optarg);
	      printf("%d\n",maxBytes);
	    break;   
        case 'h':
            printf ("OPTIONS\n  -b SIZE     put at most SIZE bytes per output file\n  -h          print summary of options and exit\n -x          print the checksum of FILE on the standard output\n");
	    break;
	case 'x':
	  x++;
	    break;	    
	}    
  }
  if (optind>=argc)
    printf ("Expected to get a file\n");
  else
  {
   
    FILE* file_read_pointer;
    file_read_pointer = fopen(argv[optind], "r");
    FILE* file_write_pointer;
    int buffer[maxBytes/sizeof(int)];
    char *origin=argv[optind];
    char name[20];
    int numRead;
    unsigned int chk=0; 
    while(numRead=(fread(buffer, 1,maxBytes, file_read_pointer)))
    {
	sprintf(name, "%s.%d", origin, j);
        file_write_pointer = fopen(name, "w");
	int i=0;
	unsigned int tmp=xsum(buffer);
	fwrite(&tmp,1,sizeof(unsigned int),file_write_pointer);
	//fprintf(file_write_pointer,"%x",tmp);
 	fwrite(buffer, 1,numRead ,file_write_pointer);
	j++;
	chk=chk^tmp;
	memset(buffer,0,sizeof(buffer));
    }
  if(x>0)
    printf("0x%x\n",chk);
  }
    return 0;
} 

 
