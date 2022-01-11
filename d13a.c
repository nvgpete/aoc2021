#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,xy[1000][1400],c;
  int f2,ff,x,y,xmax=0,ymax=0,folds[30],last=0,counta=0;
  memset(xy,' ',sizeof(xy));
  f=fopen("d13a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    if (*s=='f') {
      sscanf(s,"fold along %c=%d",&c,&x);
      if(c=='x') {
        folds[last]=x; 
        if(!xmax) xmax=x*2;
      } else {
        folds[last]=-x;
        if(!ymax) ymax=x*2;
      }  
      last++;
    }
    else if (*s) {
      sscanf(s,"%d,%d",&x,&y);
      xy[y][x]='#';
    }  
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for (f2=0;f2<last;f2++) if (folds[f2]<0) {
    ff=-folds[f2];
    for(y=ff+1;y<=ymax;y++) for (x=0;x<=xmax;x++) if (xy[y][x]=='#') xy[ymax-y][x]='#';
    ymax=ymax/2-1;
    if(counta==0) for(y=0;y<=ymax;y++) for(x=0;x<=xmax;x++) counta+=(xy[y][x]=='#');
  } else {
    ff=folds[f2];
    for(y=0;y<=ymax;y++) for (x=ff+1;x<=xmax;x++) if (xy[y][x]=='#') xy[y][xmax-x]='#';
    xmax=xmax/2-1;
    if(counta==0) for(y=0;y<=ymax;y++) for(x=0;x<=xmax;x++) counta+=(xy[y][x]=='#');
  }
  printf("\nPart a=%d\n\n",counta);
  for(y=0;y<=ymax;y++) { 
    for(x=0;x<=xmax;x++) printf("%c",xy[y][x]);
    printf("\n");
  }
}
