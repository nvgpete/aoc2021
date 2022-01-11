#include <stdio.h>
#include <string.h>
  int main(int argc,char **argv) {
  FILE *f;
  char *s2,s[105],xy[105][105];
  int x,y,x1,y1,xm=0,ym=1,sum,b1=0,b2=0,b3=0,xx[1000],yy[1000],sptr;
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
  for(y=1;y<=ym;y++) for (x=1;x<=xm;x++) if(xy[x][y]<9) {
    sum=0;
    sptr=1; xx[0]=x; yy[0]=y;
    while (sptr) {
      sptr--;
      x1=xx[sptr]; y1=yy[sptr];
      if(xy[x1][y1]==9) continue;
      xy[x1][y1]=9;
      sum++;
      if (xy[x1][y1+1]<9) {xx[sptr]=x1;yy[sptr]=y1+1;sptr++;}
      if (xy[x1][y1-1]<9) {xx[sptr]=x1;yy[sptr]=y1-1;sptr++;}
      if (xy[x1+1][y1]<9) {xx[sptr]=x1+1;yy[sptr]=y1;sptr++;}
      if (xy[x1-1][y1]<9) {xx[sptr]=x1-1;yy[sptr]=y1;sptr++;}
      if(sptr>990)printf("Stack overflow\n");
    }
    if(sum>b1) {b3=b2;b2=b1;b1=sum;}
    else if (sum>b2) {b3=b2;b2=sum;}
    else if (sum>b3) b3=sum;
  } 
  printf("Product of basins=%d\n",b1*b2*b3);
}
