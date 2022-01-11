#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100];
  int x1[500],x2[500],y1[500],y2[500],xy[1000][1000],last=0,i,j,n;
  f=fopen("d05a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    sscanf(s,"%d,%d -> %d,%d",x1+last,y1+last,x2+last,y2+last);
    last++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  memset(xy,0,sizeof(xy));
  for (n=0;n<last;n++) {
    if (x1[n]==x2[n]) if (y2[n]>y1[n]) for (i=y1[n];i<=y2[n];i++) xy[x1[n]][i]++; else for (i=y2[n];i<=y1[n];i++) xy[x1[n]][i]++; 
    else if (y1[n]==y2[n]) if (x2[n]>x1[n]) for (i=x1[n];i<=x2[n];i++) xy[i][y1[n]]++; else for (i=x2[n];i<=x1[n];i++) xy[i][y1[n]]++;
#ifdef PARTB
    else {
      if (x1[n]>x2[n]) { j=x2[n];x2[n]=x1[n];x1[n]=j;j=y2[n];y2[n]=y1[n];y1[n]=j; }
      if (y1[n]<y2[n]) for (i=x1[n],j=y1[n];i<=x2[n];i++,j++) xy[i][j]++; else  for (i=x1[n],j=y1[n];i<=x2[n];i++,j--) xy[i][j]++;
    }  
#endif  
  }  
  n=0; 
  for (i=0;i<1000;i++) for (j=0;j<1000;j++) if (xy[i][j]>1) n++;
  printf("Total bad spots=%d\n",n);
}
