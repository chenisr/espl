#include <stdio.h>
 
/* count number of words in sentence */
int main(int argc, char **argv) {
  int i;
 
 
  for(i=argc; i!=1; --i) {
    printf("%s ", argv[i-1]);
 
  }
  printf("\n");
 
  return 0;
}