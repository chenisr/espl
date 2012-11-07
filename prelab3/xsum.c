#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) 
{
  char c;
  int x=0;
  FILE *f;
  while((c=getopt (argc, argv, "hx"))!=-1)
  { 
	 switch (c) 
	{
        case 'h':
            printf ("OPTIONS\n -h  print a summary of options and exit\n -x  print the checksum as a hexadecimal rather than decimal number.\n");
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
	    f = fopen(argv[optind], "r");  
	    unsigned int sum=0;
	    unsigned int word=0; 
           while(fread(&word, 1,sizeof(word), f)) 
	   {
	     sum=sum^word;
	     word=0;
           }
           if(x==0)
	     printf ("%d\n",sum);
	   else
	     printf("%#x\n",sum); 
  }	
  fclose(f);
	   
    return 0;
} 

