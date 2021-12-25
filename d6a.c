#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
FILE *f;
char s[1000],*s2;
long fish[9]={0,0,0,0,0,0,0,0,0},f0;
int i,j,max=256;
f=fopen("d6a.txt","r");
fgets(s,1000,f);
s2=s;
while (*(s2+1)==',') {
  fish[*s2-'0']++;
  s2+=2;
}  
  fclose(f);
  for (i=0;i<max;i++) {
    f0=fish[0];
    for (j=0;j<8;j++) fish[j]=fish[j+1];
    fish[8]=f0;
    fish[6]+=f0;
  }
  f0=0;
  for (i=0;i<9;i++) f0+=fish[i];
  printf("fish=%ld\n",f0);   
}
