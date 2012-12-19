#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "xsum.h"


int readWrite (FILE* f, int numof, int maxB,char* or,FILE* w)
{
   int numRead;
   int buffer[1000]={0};
   unsigned int ch=0; 
   char nam[20];
   fseek (f,numof*maxB,0);
   numRead=(fread(buffer, 1,maxB, f));
   sprintf(nam, "%s.%d", or, numof+1);
   w= fopen(nam, "w");
   fwrite(buffer, 1,numRead ,w);
   return xsum(buffer);
}
   
   
   



int main(int argc, char **argv) 
{
  char c;
  int x=0,j=1;
  int maxBytes=32;
  int numofprocesses=1;
  while((c=getopt (argc, argv, "b:hp:"))!=-1)
  { 
	 switch (c) 
	{
	  case 'b':
	      maxBytes=atoi(optarg);
	    break;   
        case 'h':
            printf ("OPTIONS\n  -b SIZE     put at most SIZE bytes per output file\n  -h          print summary of options and exit\n -x          print the checksum of FILE on the standard output\n -b          maximum Processes\n");
	    break;	
	case 'p':
	    numofprocesses=atoi(optarg);
	    break;
	}    
  }
  if (optind>=argc)
    printf ("Expected to get a file\n");
  else
  {
    int i=1;
    FILE* file_read_pointer;
    file_read_pointer = fopen(argv[optind], "r");
    FILE* file_write_pointer;
    int buffer[maxBytes/sizeof(int)];
    char *origin=argv[optind];
    char name[20]; 
    int jump=fseek(file_read_pointer,0,SEEK_END);
    long int sizeOfFile=ftell(file_read_pointer);
    int pros=0;
    if(sizeOfFile%maxBytes==0)
      pros=sizeOfFile/maxBytes;
    else
      pros=(sizeOfFile/maxBytes) -1 ;
   for (i=0;i<pros;i++)
   {
        if(fork())
	{
	  /* Parent */
	}
	else
	{
	  /* Child */
	  readWrite(file_read_pointer,i,maxBytes,origin,file_write_pointer);
	  exit(0);
	}
     //unsigned int tmp=xsum(buffer);
     //fwrite(&tmp,1,sizeof(unsigned int),file_write_pointer);
   }
   for(i=0;i<pros;i++)
     wait(0);
  }
    return 0;
}  
