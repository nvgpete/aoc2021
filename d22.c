#include <stdio.h>
int main(int argc,char **argv) {
FILE *f;
char s[100],*s2,val;
int x1,x2,y1,y2,z1,z2;
f=fopen("d22.txt","r");
fgets(s,100,f);
while (!feof(f)) {
  val=(s[1]=='n');
  if (val) s2=s+3; else s2=s+4;
  sscanf(s2,"x=%d..%d,y=%d..%d,z=%d..%d",&x1,&x2,&y1,&y2,&z1,&z2);
  printf("%3s %d %d %d %d %d %d\n",s,x1,x2,y1,y2,z1,z2);
  fgets(s,100,f);
}  
  fclose(f); 
}
