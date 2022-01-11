#include <stdio.h>
#include <string.h>
char xlat[20]; // convert small ints to corresponding character
char getx(char c) { // convert characters to small ints, add to xlat[] if new
  char i=0;
  while (xlat[i]&&c!=xlat[i]) i++;
  if (!xlat[i]) xlat[i]=c;
  return i;
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,p1[20000],p2[20000],c,c2,c3,qq[20][20];
  int first,last=0,i,j,k,count[20];
  memset(xlat,0,sizeof(xlat));
  memset(qq,-1,sizeof(qq));
  f=fopen("d14a.txt","r");
  fgets(s,sizeof(s),f);
  first=1;
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    if (first) {
      i=0;
      while (c=s[i]) {
        p1[i]=getx(c);
        i++;
        last++;
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
  for(k=0;k<10;k++) {
    memcpy(p2,p1,last);
    p1[0]=p2[0];  
    for(i=1,j=1;i<last;i++) {
      if((c=qq[p2[i-1]][p2[i]])>=0) p1[j++]=c;
      p1[j++]=p2[i];
    }
    last=j; 
  }   
  c=strlen(xlat);
  for(i=0;i<c;i++) count[i]=0;
  for (i=0;i<last;i++) count[p1[i]]++;
  j=k=count[0];
  for (i=1;i<c;i++)
   if(count[i]<j) j=count[i];
   else if (count[i]>k) k=count[i];
  printf("difference=%d\n",k-j);    
}
