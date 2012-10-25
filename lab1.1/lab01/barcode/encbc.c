 
#include <assert.h>
#include <stdio.h>
#include "bclib.h"

char** encodetobar(int numOfWords, char** argu)
{
  int i=0,j=0,k=0;
  int barcodes[BC_WIDTH][BC_NBITS];
  for (i=1;i<numOfWords; i++)
    { 
      while (argu[i][j]!='\0')
      {
	
      bc_char2bits(argu[i][j],barcodes[k]);
      k++;
      j++;
      } 
      j=0;
    }
    for(j=0;j<8;j++)
    {
      for(i=0;i<k;i++)
      {
	if (barcodes[i][j]==1)
	  printf ("#");
	else
	  printf(" ");
      }
      printf("\n");
    }
    printf ("\n");
 
}




int main(int argc, char **argv) 



{
   
    int i=0;
     encodetobar(argc,argv);
    return 0;
}
