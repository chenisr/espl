#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"



unsigned int  xsum (int buf[]) 
{
  int i=0;
  unsigned int sm=0;
  for(i;i<sizeof(buf)/sizeof(int);i++)
  {
    sm=sm^buf[i];
  }
  return sm;
} 
