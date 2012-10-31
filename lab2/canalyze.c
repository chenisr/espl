#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "fgetname.h"
#include "namelist.h"

int res (char *src)
{
 int j=0;
  char* reserved[] = {"auto","break","case", "char","const","continue", "default", "do", "double", "else" , "enum","extern","float","for","goto","if","int","long","register","return","short"
		   , "signed","sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Packed"};
 for(j=0;j<(sizeof(reserved)/sizeof(char*));j++)
 {
   if(strcmp(src,reserved[j])==0)
     return 1;
 }
 return 0;
}   

int compare (const void * a, const void * b)
{
  return strcmp((((struct namestat*) a)->name),(((struct namestat*) b)->name));
}

int main(int argc, char **argv) 
{
 namelist nl= make_namelist();
 char name[64];
 FILE *stream;
 int i=0;
 for (i=1;i<argc;i++)
 { 
    stream = fopen(argv[i], "r");
    char name[64];
    while(fgetname(name, sizeof(name), stream))
    { 
      if(res(name)==0)
	{
	  add_name(nl,name);  
	}  
    }  
 }
      qsort(nl->names, nl->size, sizeof(struct namestat),compare);
 for (i=0;i!=nl->size;++i)
 {
   printf ("%s",nl->names[i].name);
   printf ("%d \n", nl->names[i].count);
   
 } 
 return 0;
}
