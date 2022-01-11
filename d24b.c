#include <stdio.h>
#include <string.h>
unsigned monad(const int *d);
int main(int argc,char **argv) {
  char s[16];
  int d[16],i;
#ifndef D0  
  for (d[0]=9;d[0]>0;d[0]--) {
#else  
    d[0]=D0;
#endif    
    for (d[1]=9;d[1]>0;d[1]--) {
      for (d[2]=9;d[2]>0;d[2]--) {
        for (d[3]=9;d[3]>0;d[3]--) {
          for (d[4]=9;d[4]>0;d[4]--) {
            for (d[5]=9;d[5]>0;d[5]--) {
              for (d[6]=9;d[6]>0;d[6]--) {
                for (d[7]=9;d[7]>0;d[7]--) {
                  for (d[8]=9;d[8]>0;d[8]--) {
                    for (d[9]=9;d[9]>0;d[9]--) {
                      for (d[10]=9;d[10]>0;d[10]--) {
                        for (d[11]=9;d[11]>0;d[11]--) {
                          for (d[12]=9;d[12]>0;d[12]--) {
                            for (d[13]=9;d[13]>0;d[13]--) {
                              if (monad(d)==0) {
                                for (i=0;i<14;i++) s[i]=d[i]+'0';
                                printf("version=%.14s\n",s);
                                return 0;
                              }  
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
#ifndef D0                            
  }
#endif  
}
