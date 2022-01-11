#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100];
  int cnt=0,cnt2=-2,last2,n1,n2,n3;
  f=fopen("d01a.txt","r");
  fgets(s,sizeof(s),f);
  sscanf(s,"%d",&n3);
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    last2=n1+n2+n3;
    n1=n2;
    n2=n3;
    sscanf(s,"%d",&n3);
    if (cnt2<0) cnt2++;
     else if (n1+n2+n3>last2) cnt2++;
    if (n3>n2) cnt++;
    fgets(s,sizeof(s),f);
  }  
  printf("part a=%d\npart b=%d\n",cnt,cnt2);
  fclose(f); 
}
