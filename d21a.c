#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
char turn=1;
int roll[]={6,5,4,3,2,1,0,9,8,7},rr=0;
int p1=5,p2=1,pt1=0,pt2=0,c=0;
do {
  if (turn) {
    p1+=roll[rr];
    if(p1>=10) p1-=10;
    pt1+=p1+1;
  } else {
    p2+=roll[rr];
    if (p2>=10) p2-=10;
    pt2+=p2+1;
  }  
  rr++; if (rr==10) rr=0;
  turn=1-turn;
  c++;
} while ((pt1<1000)&&(pt2<1000));
printf("pts1=%d, pts2=%d turns=%d val=%d\n",pt1,pt2,c,pt2*c*3);
}
