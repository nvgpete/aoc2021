#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[150],*s2,xy[150][150];
  int xmax,ymax,i,j,count=0,moved;
  f=fopen("d25a.txt","r");
  fgets(s,sizeof(s),f);
  ymax=0;
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    strcpy(xy[ymax],s);
    ymax++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  xmax=strlen(xy[0]);
  moved=1;
  while(moved) {
    moved=0; 
    for (j=0;j<ymax;j++) {
      xy[j][xmax]=xy[j][0];
      for (i=0;i<xmax;i++) {
        if(xy[j][i]=='>'&&xy[j][i+1]=='.') {
          xy[j][i]='.';
          if (i!=xmax-1) xy[j][i+1]='>';
          else xy[j][0]='>';
          i++;
          moved=1;
        }
      }
    }
    for(i=0;i<xmax;i++) {
      xy[ymax][i]=xy[0][i];
      for(j=0;j<ymax;j++) {
        if(xy[j][i]=='v'&&xy[j+1][i]=='.') {
          xy[j][i]='.';
          if(j!=ymax-1) xy[j+1][i]='v';
          else xy[0][i]='v';
          j++;
          moved=1;
        }
      }
    }
    count++;
  }
  printf("moves until stationary=%d\n",count);
}  