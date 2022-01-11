#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv) {
  int card[125][5][5],won[125],nbrs[100],x,nc=0,last,left,i,j,i2,j2,sum,found;
  FILE *f;
  char s[1000],*s2,c;
  int n=0,cc;
  f=fopen("d04a.txt","r");
  fgets(s,sizeof(s),f);
  s2=s;
  last=-1;
  while (c=*s2) {
    x=c-'0';
    s2++;
    c=*s2;
    if (c>='0' && c<='9') {
      x=x*10+c-'0';
      s2++;
    }
    last++;
    nbrs[last]=x;
    if (*s2==',') s2++;
  }
  fgets(s,sizeof(s),f);
  i=0;
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    sscanf(s," %d %d %d %d %d",&card[nc][i][0],&card[nc][i][1],&card[nc][i][2],&card[nc][i][3],&card[nc][i][4]);
    i++;
    if (i==5) {
      i=0;
      won[nc]=0;
      nc++;
      fgets(s,sizeof(s),f);
    }   
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  left=nc;
  for (n=0;n<last;n++) {
    x=nbrs[n];
    for (cc=0;cc<nc;cc++) {
      if (won[cc]) continue;
      found=0;
      for (i=0;i<5;i++) {
        for (j=0;j<5;j++) {
          if (card[cc][i][j]==x) {
            card[cc][i][j]=100;
            if (card[cc][i][0]+card[cc][i][1]+card[cc][i][2]+card[cc][i][3]+card[cc][i][4]==500 ||
                card[cc][0][j]+card[cc][1][j]+card[cc][2][j]+card[cc][3][j]+card[cc][4][j]==500) {
              left--;
              if(left==0) {  
                sum=0;
                for (i2=0;i2<5;i2++) for (j2=0;j2<5;j2++) {
                  if (card[cc][i2][j2]!=100) sum+=card[cc][i2][j2];
                }  
                printf("answer=%d last=%d\n",sum*x,x);
                exit(0);
              }
              won[cc]=1;
            }  
            found=1;
            break;
          }
        }  
        if (found) break;
      }
    }
  }             
  printf("end left=%d won[1]=%d last nbr=%d\n",left,won[1],x); //shouldn't get here  
}
