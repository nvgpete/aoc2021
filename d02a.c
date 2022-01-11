#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
FILE *f;
char s[100];
int x=0,d=0,y;
f=fopen("d02a.txt","r");
fgets(s,sizeof(s),f);
while (!feof(f)) {
  if (*s=='u') {
    sscanf(s+3,"%d",&y);
    d-=y;
  } else if (*s=='d') {
    sscanf(s+5,"%d",&y);
    d+=y;
  } else if (*s=='f') {   
    sscanf(s+8,"%d",&y);
    x+=y;
  }
  fgets(s,sizeof(s),f);
} 
  printf("forward=%d depth=%d product=%d\n",x,d,x*d); 
  fclose(f); 
}
