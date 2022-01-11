#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[110],*s2,c;
  int v,v2,i,x,y,xy[510][510],dd[510][510],xx[10000],yy[10000],vv[10000],sptr,sp2,xmax,ymax=1;
#ifdef PARTB
  int j,i2,j2;
#endif    
  memset(dd,7,sizeof(dd));
  memset(xy,0,sizeof(xy));
  f=fopen("d15a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    i=1;
    while (c=s[i-1]) xy[ymax][i++]=c-'0';
    xmax=i;
    ymax++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
#ifdef PARTB  
  for (x=0;x<5;x++) for (y=0;y<5;y++) if (x+y) {
    for (i=1,i2=(ymax-1)*y+1;i<ymax;i++,i2++) for (j=1,j2=(xmax-1)*x+1;j<xmax;j++,j2++) {
      v=xy[i][j]+x+y;
      if (v>9) v-=9;
      xy[i2][j2]=v;
    }
  }
  xmax=(xmax-1)*5+1;
  ymax=(ymax-1)*5+1;
#endif  
  for (i=0;i<=ymax;i++) dd[i][0]=dd[i][ymax]=dd[0][i]=dd[ymax][i]=0;
  dd[1][1]=0;
  sptr=1; xx[1]=1; yy[1]=1; vv[1]=0; vv[0]=99999;
  while (sptr) {
    x=xx[sptr];
    y=yy[sptr];
    v=dd[y][x]; 
    vv[sptr]=v;
    sptr--;
    if (xy[y][x-1]+v<dd[y][x-1]) {
      v2=dd[y][x-1]=xy[y][x-1]+v;
      sptr++;
      sp2=sptr-1;
      while (vv[sp2]<v2) { vv[sp2+1]=vv[sp2]; xx[sp2+1]=xx[sp2]; yy[sp2+1]=yy[sp2]; sp2--;}
      xx[sp2+1]=x-1;
      yy[sp2+1]=y;
      vv[sp2+1]=v2;
    }
    if (xy[y][x+1]+v<dd[y][x+1]) {
      v2=dd[y][x+1]=xy[y][x+1]+v;
      sptr++;
      sp2=sptr-1;
      while (vv[sp2]<v2) { vv[sp2+1]=vv[sp2]; xx[sp2+1]=xx[sp2]; yy[sp2+1]=yy[sp2]; sp2--;}
      xx[sp2+1]=x+1;
      yy[sp2+1]=y;
      vv[sp2+1]=v2;
    }
    if (xy[y-1][x]+v<dd[y-1][x]) {
      v2=dd[y-1][x]=xy[y-1][x]+v;
      sptr++;
      sp2=sptr-1;
      while (vv[sp2]<v2) { vv[sp2+1]=vv[sp2]; xx[sp2+1]=xx[sp2]; yy[sp2+1]=yy[sp2]; sp2--;}
      xx[sp2+1]=x;
      yy[sp2+1]=y-1;
      vv[sp2+1]=v2;
    }
    if (xy[y+1][x]+v<dd[y+1][x]) {
      v2=dd[y+1][x]=xy[y+1][x]+v;
      sptr++;
      sp2=sptr-1;
      while (vv[sp2]<v2) { vv[sp2+1]=vv[sp2]; xx[sp2+1]=xx[sp2]; yy[sp2+1]=yy[sp2]; sp2--;}
      xx[sp2+1]=x;
      yy[sp2+1]=y+1;
      vv[sp2+1]=v2;
    }
    if(sptr>9990) {printf("STACK\n"); return 0;}
  }
  printf("Cheapestpath = %d\n",dd[ymax-1][xmax-1]);
}