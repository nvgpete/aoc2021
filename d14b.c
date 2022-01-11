#include <stdio.h>
#include <string.h>
char xlat[20];
char getx(char c) {
  char i=0;
  while (xlat[i]&&c!=xlat[i]) i++;
  if (!xlat[i]) xlat[i]=c;
  return i;
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,cfirst,clast,c,c2,c3,qq[20][20];
  int first,i,j,k,sz;
  long cc[20][20],cc2[20][20],count[20],min,max;
  memset(xlat,0,sizeof(xlat));
  memset(qq,-1,sizeof(qq));
  memset(cc,0,sizeof(cc));
  f=fopen("d14a.txt","r");
  fgets(s,sizeof(s),f);
  first=1;
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    if (first) {
      i=0;
      cfirst=getx(s[i]);
      while (c=s[i]) {
        c=getx(c);
        if(i) cc[getx(s[i-1])][c]+=1;
        clast=c;
        i++;
      }
      fgets(s,sizeof(s),f);
      first=0;
    } else {
      sscanf(s,"%c%c -> %c",&c,&c2,&c3);
      qq[getx(c)][getx(c2)]=getx(c3);
    }      
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  sz=strlen(xlat);
  for(k=0;k<40;k++) {
    memcpy(cc2,cc,sizeof(cc));
    memset(cc,0,sizeof(cc));
    for(i=0;i<sz;i++) for(j=0;j<sz;j++) {
      c=qq[i][j];
      cc[i][c]+=cc2[i][j];
      cc[c][j]+=cc2[i][j];
    }  
  }   
  for(i=0;i<sz;i++) count[i]=0;
  for (i=0;i<sz;i++) for(j=0;j<sz;j++) {
    count[i]+=cc[i][j];
    count[j]+=cc[i][j];
  }
  count[cfirst]++;
  count[clast]++;
  for (i=0;i<sz;i++) count[i]/=2;
  min=max=count[0];
  for (i=1;i<sz;i++)
   if(count[i]<min) min=count[i];
   else if (count[i]>max) max=count[i];
  printf("difference=%ld\n",max-min);    
}
