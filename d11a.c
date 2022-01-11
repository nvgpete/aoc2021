#include <stdio.h>
#include <string.h>
  int main(int argc,char **argv) {
  FILE *f;
  char s[100],xy[12][12];
  int x,y,i,j,k,done,flash,flash2=0;
   memset(xy,0,sizeof(xy));
  f=fopen("d11a.txt","r");
  fgets(s,sizeof(s),f);
  y=1;
  while (!feof(f)) {
    for(x=1;x<11;x++) xy[y][x]=s[x-1]-'0';
    y++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  k=0;
  do {
    flash=0;
    for(y=1;y<11;y++) for(x=1;x<11;x++) xy[y][x]++;
    do{
      done=1;
      for(y=1;y<11;y++) for(x=1;x<11;x++) if(xy[y][x]==10){
        done=0;
        xy[y][x]=0;
        flash++;
        for(j=y-1;j<=y+1;j++) for (i=x-1;i<=x+1;i++) if(xy[j][i]&&xy[j][i]<10) xy[j][i]++;
      }
    } while (!done);
    if (k<100) flash2+=flash;
    k++;
  } while (flash!=100);
  printf("After 100 turns, %d total flashes\nAll flash at turn=%d\n",flash2,k);
}
