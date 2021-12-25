#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
FILE *f;
char s[100],*s2;
int x=0,d=0,y,aim=0;
f=fopen("d2a.txt","r");
fgets(s,100,f);
while (!feof(f)) {
  if (*s=='u') {
    sscanf(s+3,"%d",&y);
    aim-=y;
  } else if (*s=='d') {
    sscanf(s+5,"%d",&y);
    aim+=y;
  } else if (*s=='f') {   
    sscanf(s+8,"%d",&y);
    x+=y;
    d+=y*aim;
  }
  fgets(s,100,f);
} 
  printf("%d %d %d\n",x,d,x*d); 
  fclose(f); 
}
