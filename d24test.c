#include <stdio.h>
#include <string.h>
unsigned monad(int *d); 
int main(int argc,char **argv) {
  int d[16];
  unsigned i,k;
  for (k=0;k<14;k++) d[k]=k*k%9+1;
  for (k=0;k<10000000;k++) i=monad(d);
  printf("%u\n",i);   
}
