#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
FILE *f;
char s[200],*s2,*s3;
int c=0,l;
f=fopen("d8a.txt","r");
fgets(s,200,f);
while (!feof(f)) {
  if (s3=strchr(s,'\n')) *s3=0;
  s2=strchr(s,'|')+2;
  s3=strtok(s2," ");
  do {
    if (strlen(s3)<=4 || strlen(s3)==7)  c++;
  } while (s3=strtok(NULL," "));
  fgets(s,200,f);
}  
  fclose(f);
  printf("%d\n",c);
}  