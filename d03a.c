#include <stdio.h>
#include <string.h>
#define BITS 12
int main(int argc,char **argv) {
  FILE *f;
  char s[100];
  int  i,k[BITS],lines=0,x=0,y;
  for (i=0;i<BITS;i++)  k[i]=0;
  f=fopen("d03a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    lines++;
    for (i=0;i<BITS;i++) k[i]+=*(s+i)-'0';
    fgets(s,sizeof(s),f);
  } 
  lines/=2; 
  for (i=0;i<BITS;i++) x+=x+(k[i]>lines);
  y=(1<<BITS)-x-1;
  printf("gamma=%d epsilon=%d product=%d\n",x,y,x*y);  
  fclose(f); 
}
