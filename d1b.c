#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
FILE *f;
char s[100],*s2;
int cnt=0,last,n1,n2,n3;
f=fopen("d1a.txt","r");
fgets(s,100,f);
sscanf(s,"%d",&n1);
fgets(s,100,f);
sscanf(s,"%d",&n2);
fgets(s,100,f);
sscanf(s,"%d",&n3);
fgets(s,100,f);
while (!feof(f)) {
  last=n1+n2+n3;
  n1=n2;
  n2=n3;
  sscanf(s,"%d",&n3);
  if (n1+n2+n3>last) cnt++;
  fgets(s,100,f);
}  
  printf("%d\n",cnt);
  fclose(f); 
}
