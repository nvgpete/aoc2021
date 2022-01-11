#include <stdio.h>
#include <string.h>
unsigned monad(const int *d);
int main(int argc,char **argv) {
  char s[16];
  int d[16],i;
#ifndef D0
#ifdef UP
  for (d[0]=1;d[0]<10;d[0]++) {
#else  
  for (d[0]=9;d[0]>0;d[0]--) {
#endif  
#else  
    d[0]=D0;
#endif
    if (monad(d)==0) {
      for (i=0;i<14;i++) s[i]=d[i]+'0';
      printf("version=%.14s\n",s);
      return 0;
    }  
#ifndef D0                            
  }
#endif  
}
