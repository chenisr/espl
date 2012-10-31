#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) 
{
  FILE *tmp;
  int numOfLines=0;
  int randi=0,i=0;
  char ln[5000];
  int done=0;
  tmp=fopen(argv[1],"r");
      if (tmp!=NULL)
      {
	while (fgets(ln,120,tmp))
	{
	  numOfLines++;
	}
	rewind(tmp);
	  srand(time(NULL));
	  randi=rand()%(numOfLines-1);
	  printf ("%d:  ",randi);
	  for(i=0;i<randi;i++)
	  {
	    fgets(ln,120,tmp);
	  }
	  printf ("%s\n",ln);
      }
      else 
      {
	printf ("%s\n", "Error while Reading");
      }
      fclose(tmp);
    return 0;
}