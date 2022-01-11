#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char *s2,s[105],xy[105][105];
  int x,y,xm=0,ym=1,sum;
  f=fopen("d09a.txt","r");
  fgets(s,sizeof(s),f);
  if (s2=strchr(s,'\n')) *s2=0;
  xm=strlen(s);
  while (!feof(f)) {
    for(x=1;x<=xm;x++) xy[x][ym]=s[x-1]-'0';
    ym++;  
    fgets(s,sizeof(s),f);
  } 
  fclose(f); 
  ym--;
  for (x=0;x<xm+2;x++) {
    xy[x][0]=9;
    xy[x][ym+1]=9;
  }  
  for (y=0;y<ym+2;y++) {
    xy[0][y]=9;
    xy[xm+1][y]=9;
  }
  sum=0;
  for(x=1;x<=xm;x++) for (y=1;y<=ym;y++) if(xy[x][y]<xy[x-1][y]&&xy[x][y]<xy[x+1][y]&&xy[x][y]<xy[x][y-1]&&xy[x][y]<xy[x][y+1]) sum+=xy[x][y]+1;
  printf("sum of low points=%d\n",sum);
}
