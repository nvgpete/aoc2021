#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  int main(int argc,char **argv) {
  FILE *f;
  char s[50000],*s2;
  int x[1010],last=0,dd,i,j,best,d3,low,high;
  f=fopen("d07a.txt","r");
  fgets(s,sizeof(s),f);
  fclose(f); 
  s2=strtok(s,",");
  x[last]=atoi(s2);
  while (s2=strtok(NULL,",")) {
    last++;
    x[last]=atoi(s2);
  }
  low=high=x[0];
  for (i=1;i<=last;i++) {
   if(x[i]<low) low=x[i];
   if(x[i]>high) high=x[i];
  }
  best=low;
  d3=0;
  for (i=0;i<=last;i++) d3+=abs(low-x[i])*(abs(low-x[i])+1)/2;
  for (j=low+1;j<=high;j++){
    dd=0;
    for (i=0;i<=last;i++) dd+=abs(j-x[i])*(abs(j-x[i])+1)/2;
    if(dd<d3) {
      best=j;
      d3=dd;
    }
  }
  printf("best=%d dist=%d\n",best,d3);   
}
