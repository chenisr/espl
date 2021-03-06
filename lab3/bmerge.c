#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "xsum.h"


int main(int argc, char **argv) 
{
     char c;
     int o=0,j=1,chk=0;
     int maxBytes=32;
     char *newOne;
     
     while((c=getopt (argc, argv, "ho:x:"))!=-1)
     { 
	 switch (c) 
	{
	  case 'h':
	    printf ("OPTIONS\n  -b SIZE     put at most SIZE bytes per output file\n  -h          print summary of options and exit\n -x          print the checksum of FILE on the standard output\n");
	    break;   
        case 'o':
            newOne=optarg;
	    o++;
	    break;
	case 'x':
	    chk=atoi(optarg);
	    break;	    
	}    
     }
      if (optind>=argc)
    printf ("Expected to get a file\n");
    else
    {
       unsigned int ch=0;
       int numRead;
       FILE* file_read_pointer;
       char str[20];
       int i=1;
       strcpy (str,argv[optind]);
       strcat (str,".1");
       file_read_pointer = fopen(str,"r");
       FILE* file_write_pointer;
       int buffer[sizeof(int)];
       if(o==0)
	 newOne=argv[optind];	
       file_write_pointer = fopen(newOne, "w");
       unsigned int tmp=xsum(buffer);
       while (numRead=(fread(buffer, 1,sizeof(int), file_read_pointer)))
       {
	 printf ("%s\n",str);
	 tmp=xsum(buffer);
	 ch=ch^tmp;
	 memset(buffer,0,sizeof(buffer));
	 while (numRead=(fread(buffer, 1,sizeof(int), file_read_pointer)))
	 {
	   fwrite(buffer, 1,numRead,file_write_pointer);
	   memset(buffer,0,sizeof(buffer));
	 }
	  
	 strcpy (str,argv[optind]);
	 strcat (str,".");
	  i++;
	 char s[2];
	 sprintf(s, "%d",i);
	 strcat (str,s);
	 memset(buffer,0,sizeof(buffer));
	 if(!(file_read_pointer = fopen(str,"r")))
	   break;
       }
  if(chk>0)
  {
    if(chk==tmp)
      printf("even\n");
    else
      printf("Different\n");
  }
    }
    return 0;
} 

  
