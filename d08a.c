#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[200],*s2,*s3;
  int c=0;
  f=fopen("d08a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if (s2=strchr(s,'\n')) *s2=0;
    s2=strchr(s,'|')+2;
    s3=strtok(s2," ");
    do {
      if (strlen(s3)<=4 || strlen(s3)==7)  c++;
    } while (s3=strtok(NULL," "));
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  printf("1's,7's,4's,8's=%d\n",c);
}  