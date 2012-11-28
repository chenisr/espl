#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int cmpstr(char* a, char* b) 
{
	int i=0;
	for( i=0;a[i]!=0 && b[i]!=0;i++)
	{
	  if (a[i]>b[i])
	    return 1;
	  if(a[i]<b[i])
	    return 2;
	}
	if (a[i]==0 && b[i]!=0)
	  return 2;
	if(a[i]!=0 && b[i]==0)
	  return 1;
	return 0;
}
 
