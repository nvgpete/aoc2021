#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
int main(int argc,char **argv) {
  FILE *f;
#ifdef PARTB
  int x1[SIZE],x2[SIZE],y1[SIZE],y2[SIZE],z1[SIZE],z2[SIZE],last=0,kk;
#else
  char xyz[101][101][101];
  int j,k;
#endif
  char s[100],*s2,on;
  int xx1,xx2,yy1,yy2,zz1,zz2,i;
  long count;
#ifndef PARTB
  memset(xyz,0,sizeof(xyz));
#endif
  f=fopen("d22a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    on=(s[1]=='n');
    if (on) s2=s+3; else s2=s+4;
    sscanf(s2,"x=%d..%d,y=%d..%d,z=%d..%d",&xx1,&xx2,&yy1,&yy2,&zz1,&zz2);
#ifndef PARTB  
    if(abs(xx1)<=50) for(k=zz1+50;k<=zz2+50;k++) for(j=yy1+50;j<=yy2+50;j++) for (i=xx1+50;i<=xx2+50;i++) xyz[i][j][k]=on;
#else
    kk=last;
    for(i=0;i<kk;i++) {
      if(xx1>x2[i]||xx2<x1[i]) continue;
      if(yy1>y2[i]||yy2<y1[i]) continue;
      if(zz1>z2[i]||zz2<z1[i]) continue;
      if(xx1>x1[i]) {
        x1[last]=x1[i];
        x2[last]=xx1-1;
        y1[last]=y1[i];
        y2[last]=y2[i];
        z1[last]=z1[i];
        z2[last]=z2[i];
        x1[i]=xx1;
        last++;
      }  
      if(xx2<x2[i]) {
        x1[last]=xx2+1;
        x2[last]=x2[i];
        y1[last]=y1[i];
        y2[last]=y2[i];
        z1[last]=z1[i];
        z2[last]=z2[i];
        x2[i]=xx2;
        last++;
      }  
      if(yy1>y1[i]) {
        x1[last]=x1[i];
        x2[last]=x2[i];
        y1[last]=y1[i];
        y2[last]=yy1-1;
        z1[last]=z1[i];
        z2[last]=z2[i];
        y1[i]=yy1;
        last++;
      }   
      if(yy2<y2[i]) {
        x1[last]=x1[i];
        x2[last]=x2[i];
        y1[last]=yy2+1;
        y2[last]=y2[i];
        z1[last]=z1[i];
        z2[last]=z2[i];
        y2[i]=yy2;
        last++;
      }  
      if(zz1>z1[i]) {
        x1[last]=x1[i];
        x2[last]=x2[i];
        y1[last]=y1[i];
        y2[last]=y2[i];
        z1[last]=z1[i];
        z2[last]=zz1-1;
        z1[i]=zz1;
        last++;
      }  
      if(zz2<z2[i]) {
        x1[last]=x1[i];
        x2[last]=x2[i];
        y1[last]=y1[i];
        y2[last]=y2[i];
        z1[last]=zz2+1;
        z2[last]=z2[i];
        z2[i]=zz2;
        last++;
      }  
      if(last>SIZE-8) {
        printf("array overflow %d\n",last);
        break;
      }
      last--;
      x1[i]=x1[last];
      x2[i]=x2[last];
      y1[i]=y1[last];
      y2[i]=y2[last];
      z1[i]=z1[last];
      z2[i]=z2[last];
      if(last<kk) {i--;kk--;}
    }
    if(on) {
      x1[last]=xx1;
      x2[last]=xx2;
      y1[last]=yy1;
      y2[last]=yy2;
      z1[last]=zz1;
      z2[last]=zz2;
      last++;
    }
    if(last>SIZE-8) {
      printf("array overflow %d\n",last);
      break;
    }
#endif    
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
#ifdef PARTB  
  count=0;
  for (i=0;i<last;i++) count+=(long)(x2[i]-x1[i]+1)*(y2[i]-y1[i]+1)*(z2[i]-z1[i]+1);
  printf("cells count=%ld nshapes=%d\n",count,last);
#else   
  count=0;
  for(k=0;k<101;k++) for (j=0;j<101;j++) for(i=0;i<101;i++) count+=xyz[i][j][k];
  printf("Cells on=%ld\n",count);
#endif  
}
