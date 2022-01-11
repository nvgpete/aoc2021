#include <stdio.h>
#include <string.h>
void strsort(char *s){
  char s2[8],c,j;
  strcpy(s2,s);
  j=0;
  for(c='a';c<='g';c++)  if (strchr(s2,c)) *(s+j++)=c;
}   
int main(int argc,char **argv) {
  FILE *f;
  char *c2,c3,s[200],*s2,*s3,xl[5040][8],segs[5040][10][8],cc[8],nn[10][8]={"abcefg","cf","acdeg","acdfg","bcdf","abdfg","abdefg","acf","abcdefg","abcdfg"};
  char *inputs[10];
  int c,i,j,k,last=0,sum=0;
  memset(segs,0,sizeof(segs));
  for (i=0;i<(1<<21)-1;i++) {
    sprintf(cc,"%7.7o",i);
    if (strchr(cc,'7')) continue;
    for (c3='0';c3<'7';c3++) if ((c2=strchr(cc,c3))==NULL) break;
    if (c2==NULL) continue;
    for(j=0;j<7;j++) xl[last][j]=*(cc+j)-'0'+'a';
    xl[last][7]=0;
    for(j=0;j<10;j++) {
      for (c2=nn[j],s2=segs[last][j];*c2;c2++,s2++) *s2=xl[last][*c2-'a'];
      strsort(segs[last][j]);
    }   
    last++;
  }  
  f=fopen("d08a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if (s3=strchr(s,'\n')) *s3=0;
    for (i=0;i<10;i++) inputs[i]=NULL;
    s2=strchr(s,'|')+2;
    *(s2-2)=0;
    s3=strtok(s," ");
    last=0;
    do {
      strsort(s3);
      for(i=0;i<last;i++) if (!strcmp(s3,inputs[i])) break;
      if (i==last)  inputs[last++]=s3;
    } while (s3=strtok(NULL," "));
    for (k=0;k<5040;k++) {  
      for (j=0;j<10;j++) {
        for (i=0;i<10;i++) if (!(c=strcmp(segs[k][i],inputs[j]))) break;
        if (c) break;
      }
      if(!c) break;
    }
    if(c) {printf("ERROR\n"); return 0;}
    s3=strtok(s2," ");
    c=0;
    do {
      strsort(s3); 
      for(i=0;i<10;i++) if(!strcmp(s3,segs[k][i])) break;
      c=c*10+i;
    } while (s3=strtok(NULL," "));
    fgets(s,sizeof(s),f);
    sum+=c;
  }  
  printf("sum=%d\n",sum);
  fclose(f);
}  