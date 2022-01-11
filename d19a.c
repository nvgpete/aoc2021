#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static inline int dd(int x,int y,int z) {
  return x*x+y*y+z*z;
}
int find(int m,int cnt) {
  int i=0;
  while (((m>>i)&1)==0) i++;
  if (cnt==1) return i;
  i++;  
  while (((m>>i)&1)==0) i++;
  return i;
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int match[100],match2[100]; // arrays of values for 2 scanners where 2 bits are set in each to indicate pairs at the same distance
  int sx[36],sy[36],sz[36]; // locations of the scanners
  int *x[36],*y[36],*z[36],lasts[36]; // locations of beacons by scanner; lasts[] is how many beacons per scanner
  int xb[500],yb[500],zb[500];  // locations of beacons relative to scanner 0
  int sdist[36][26][26]; // square of distance between pairs of beacons, by scanner
  int scanok[36]; // which scanners have been normalized to scanner 0 
  int last,i,i2,j,j2,k,k2,d,b,n,lastb=0,sdd,done,*tmp,lastm,cc[26];
  int dx,dy,dz,dx2,dy2,dz2;
  f=fopen("d19a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    sscanf(s,"--- scanner %d",&i);
    fgets(s,sizeof(s),f);
    x[i]=malloc(30*sizeof(int)); y[i]=malloc(30*sizeof(int)); z[i]=malloc(30*sizeof(int));
    j=0;
    while (!feof(f)&&*s) {
      sscanf(s,"%d,%d,%d",x[i]+j,y[i]+j,z[i]+j);
      if (i==0) {xb[j]=x[0][j];yb[j]=y[0][j];zb[j]=z[0][j];lastb++;} // scanner 0 beacons to beacon list
      j++;
      fgets(s,sizeof(s),f);
      if(s2=strchr(s,'\n'))*s2=0;
    }
    lasts[i]=j;  
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  last=i+1;
// calculate squared pairwise distances beteen beacons for each scanner  
  for (k=0;k<last;k++) for (i=0;i<lasts[k]-1;i++) for (j=i+1;j<lasts[k];j++) {
    d=dd(x[k][i]-x[k][j],y[k][i]-y[k][j],z[k][i]-z[k][j]);
    sdist[k][i][j]=sdist[k][j][i]=d;
  }
  sx[0]=sy[0]=sz[0]=0;  // scanner 0
  memset(scanok,0,sizeof(scanok));
  scanok[0]=1;  
  do {
   done=1;
   for (k=0;k<last;k++) { 
    if (!scanok[k]) continue; // if scanner k not normalized, skip it
    for (k2=0;k2<last;k2++) {
      if (scanok[k2]||k==k2) continue; // if scanner k2 normalized, skip it
      lastm=0;
      for (i=0;i<lasts[k]-1;i++) {
        for (j=i+1;j<lasts[k];j++) {
          sdd=sdist[k][i][j];
          for (i2=0;i2<lasts[k2]-1;i2++) {
            for (j2=i2+1;j2<lasts[k2];j2++) {
              if (sdist[k2][i2][j2]==sdd) {  // make a list of all pairs from each scanner that are the same distance apart 
                match[lastm]=(1<<i)+(1<<j);
                match2[lastm]=(1<<i2)+(1<<j2);
                lastm++;
              }
            }
          }
        }
      }
      if (lastm>66) {  // get rid of extraneous matches not part of 12 overlapping beacons
        memset(cc,0,sizeof(cc));
        for (i=0;i<lastm;i++) {
          cc[find(match[i],1)]++;
          cc[find(match[i],2)]++;
        }
        for (i=0,j=0;i<lastm;i++) {
          if (cc[find(match[i],1)]<11||cc[find(match[i],2)]<11) continue;
          match[j]=match[i]; match2[j]=match2[i]; j++;
        }
        lastm=j;  
      }  
      if (lastm==66) {  // exactly 12 overlapping beacons=66 pairs 
        i=find(match[0],1); // use first pair
        j=find(match[0],2);
        i2=find(match2[0],1);
        j2=find(match2[0],2);
        if(i2!=find(match2[1],1)&&i2!=find(match2[1],2)) {d=i2; i2=j2; j2=d;} // exchange if not in same order.
        dx=x[k][i]-x[k][j]; dy=y[k][i]-y[k][j]; dz=z[k][i]-z[k][j]; // x,y,x distances between pairs
        dx2=x[k2][i2]-x[k2][j2]; dy2=y[k2][i2]-y[k2][j2]; dz2=z[k2][i2]-z[k2][j2]; // for each scanner
        if (abs(dx)==abs(dy2)) {tmp=x[k2]; x[k2]=y[k2]; y[k2]=tmp; d=dx2; dx2=dy2; dy2=d;} // exchange x,y axis if necessary
        if (abs(dx)==abs(dz2)) {tmp=x[k2]; x[k2]=z[k2]; z[k2]=tmp; d=dx2; dx2=dz2; dz2=d;} // x,z axis
        if (abs(dy)==abs(dz2)) {tmp=y[k2]; y[k2]=z[k2]; z[k2]=tmp; d=dy2; dy2=dz2; dz2=d;} // y,x axis
        if (dx!=dx2) for (n=0;n<lasts[k2];n++) x[k2][n]=-x[k2][n]; // invert x axis if necessary
        if (dy!=dy2) for (n=0;n<lasts[k2];n++) y[k2][n]=-y[k2][n]; // y axis
        if (dz!=dz2) for (n=0;n<lasts[k2];n++) z[k2][n]=-z[k2][n]; // z axis
        dx=x[k][i]-x[k2][i2]; for (n=0;n<lasts[k2];n++) x[k2][n]+=dx; // translate x axis to scanner 0 coordinate system
        dy=y[k][i]-y[k2][i2]; for (n=0;n<lasts[k2];n++) y[k2][n]+=dy; // y axis
        dz=z[k][i]-z[k2][i2]; for (n=0;n<lasts[k2];n++) z[k2][n]+=dz; // z axis
        sx[k2]=dx; sy[k2]=dy; sz[k2]=dz;  // add scanner location to list 
        scanok[k2]=1;               
        for (n=0;n<lasts[k2];n++) {   // add beacons which aren't already there to beacon list
          for (b=0;b<lastb;b++) {
            if(xb[b]==x[k2][n]&&yb[b]==y[k2][n]&&zb[b]==z[k2][n]) break;
          }
          if (b==lastb) { xb[b]=x[k2][n]; yb[b]=y[k2][n]; zb[b]=z[k2][n]; lastb++; }
        }
        done=0;
      }
    }
   }                  
  } while (!done);
  printf("Beacons=%d\n",lastb);
  sdd=0;
  for (i=0;i<last-1;i++) for(j=i+1;j<last;j++) {
    d=abs(sx[i]-sx[j])+abs(sy[i]-sy[j])+abs(sz[i]-sz[j]);
    if (d>sdd) sdd=d;
  }
  printf("max separation=%d\n",sdd);  
}
