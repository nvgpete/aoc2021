#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[1000],*s2;
  long fish[9]={0,0,0,0,0,0,0,0,0},f0;
  int i,j,f80;
  f=fopen("d06a.txt","r");
  fgets(s,sizeof(s),f);
  s2=s;
  while (*(s2+1)==',') {
    fish[*s2-'0']++;
    s2+=2;
  }  
  fclose(f);
  for (i=0;i<256;i++) {
    f0=fish[0];
    for (j=0;j<8;j++) fish[j]=fish[j+1];
    fish[8]=f0;
    fish[6]+=f0;
    if(i==79) {
      f80=0;
      for (j=0;j<9;j++) f80+=fish[j];
    }
  }  
  f0=0;
  for (i=0;i<9;i++) f0+=fish[i];
  printf("after 80 days=%d fish, after 256 days=%ld fish\n",f80,f0);   
}
