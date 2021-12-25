#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
char rolls[]={0,0,0,1,3,6,7,6,3,1},turn=1,done;
int i,j,k,n,r,i2,j2,k2,n2,c=0;
long posn[10][10][21][21],pos2[10][10][21][21],p1,p2,c2,cnt;
memset(posn,0,sizeof(posn));
posn[5][1][0][0]=1;
p1=0;p2=0;
do {
  done=1;
  memset(pos2,0,sizeof(pos2));
  for (i=0;i<10;i++) for (j=0;j<10;j++) for (k=0;k<21;k++) for (n=0;n<21;n++) if (cnt=posn[i][j][k][n]) {
    if (turn) for (r=3;r<10;r++) {
      c2=cnt*rolls[r]; 
      i2=i+r; if (i2>=10) i2-=10;
      k2=k+i2+1;
      if (k2>=21) p1+=c2;
      else {
        pos2[i2][j][k2][n]+=c2;
        done=0;
      }   
    } else for (r=3;r<10;r++) {  
      c2=cnt*rolls[r]; 
      j2=j+r; if (j2>=10) j2-=10;
      n2=n+j2+1;
      if (n2>=21) p2+=c2;
      else {
        pos2[i][j2][k][n2]+=c2;
        done=0;
      } 
    }      
  }
  memcpy(posn,pos2,sizeof(pos2));
  turn=1-turn;
} while (!done);
printf("p1=%ld, p2=%ld\n",p1,p2);
}
