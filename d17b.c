#include <stdio.h>
#include <string.h>
int xloc(int v,int t) {
  int i,j;
  if (t>=v) return (v+1)*v/2;
  for (i=0,j=0;i<t;i++,v--) j+=v;
  return j;
}
int yloc(int v,int t) {
  int i,j;
  for (i=0,j=0;i<t;i++,v--) j+=v;
  return j;
}     
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int count=0,nx,ny,vx0,i,j,t,xmin,xmax,ymin,ymax,x,y,vx,oldvxmax,vy,oldvymin;
  f=fopen("d17a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    sscanf(s,"target area: x=%d..%d, y=%d..%d",&xmin,&xmax,&ymin,&ymax);
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  vx0=0; while(vx0*(vx0+1)/2<xmin) vx0++;
  t=1;
  oldvxmax=xmax+1;
  oldvymin=ymin-1;
  while (t<=(-ymin)*2+1) {
    vx=oldvxmax; 
    while(xloc(vx,t)>xmax) vx--;
    oldvxmax=vx;
    while(xloc(vx,t)>=xmin) vx--;
    nx=oldvxmax-vx;
    vy=oldvymin; 
    while(yloc(vy,t)<ymin) vy++;
    oldvymin=vy;
    while(yloc(vy,t)<=ymax) vy++;
    ny=vy-oldvymin;
    count+=nx*ny;
    if (t>1) for (i=vx+1;i<=oldvxmax;i++) for (j=oldvymin;j<vy;j++) {
      y=yloc(j,t-1);
      if (y>ymax||y<ymin) continue;
      x=xloc(i,t-1);
      if (x>xmax||x<xmin) continue;
      count--;
    }  
    t++;
  }
printf("%d different initial velocities\n",count);  
}
