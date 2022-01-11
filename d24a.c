#include <stdio.h>
#include <string.h>
unsigned monad(const int *d);
int main(int argc,char **argv) {
char high[20]="",low[20];
int d[15],count=0,i;
for (d[0]=3;d[0]>0;d[0]--) {
  for (d[1]=9;d[1]>7;d[1]--) {
    for (d[2]=9;d[2]>0;d[2]--) {
//      for (d[3]=9;d[3]>0;x1[3]--) {
      d[3]=d[2];
        for (d[4]=9;d[4]>5;d[4]--) {
          for (d[5]=6;d[5]>0;d[5]--) {
            for (d[6]=9;d[6]>1;d[6]--) {
//              for (d[7]=8;d[7]>7;d[7]--) {
                d[7]=d[6]-1;
                for (d[8]=7;d[8]>0;d[8]--) {
//                  for (d[9]=9;d[9]>0;d[9]--) {
                    d[9]=d[8]+2;
//                    for (d[10]=9;d[10]>0;d[10]--) {
                      d[10]=d[5]+3;
//                      for (d[11]=9;d[11]>0;d[11]--) {
                        d[11]=d[4]-5;
//                        for (d[12]=9;d[12]>0;d[12]--) {
                          d[12]=d[1]-7;
//                          for (d[13]=9;d[13]>0;d[13]--) {
                            d[13]=d[0]+6;
//                            if (monad(d)==0) {
                              if (!*high) for (i=0;i<14; i++) high[i]=d[i]+'0'; 
                              for (i=0;i<14;i++) low[i]=d[i]+'0';
                              count++;  
//                            }  
//                          }
//                        }
//                      }
//                    }
//                  }
                }
//              }
            }
          }
        }
//      }
    }
  }                        
}
printf("high=%.14s\n",high);
printf("low=%.14s\n",low);
printf("%d total versions\n",count);
}
