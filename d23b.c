#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char rooms[4][4]={{3,4,4,1},{4,2,3,4},{2,1,2,3},{2,3,1,1}}; //real data
//char rooms[4][4]={{1,4,4,2},{4,2,3,3},{3,1,2,2},{1,3,1,4}};  //test data
//char rooms[4][4]={{1,1,1,4},{2,2,2,2},{3,3,3,3},{4,4,4,1}};
char hall[7]={0,0,0,0,0,0,0};
char dist[4][4][7]={{{6,5,5,7,9,11,12},{5,4,4,6,8,10,11},{4,3,3,5,7,9,10},{3,2,2,4,6,8,9}},
                    {{8,7,5,5,7,9,10},{7,6,4,4,6,8,9},{6,5,3,3,5,7,8},{5,4,2,2,4,6,7}},
                    {{10,9,7,5,5,7,8},{9,8,6,4,4,6,7},{8,7,5,3,3,5,6},{7,6,4,2,2,4,5}},
                    {{12,11,9,7,5,5,6},{11,10,8,6,4,4,5},{10,9,7,5,3,3,4},{9,8,6,4,2,2,3}}};
char si[100],sj[100],sk[100],kkk=0,vi[100],vj[100],vk[100],vkkk;                    
int ncost[5]={0,1,10,100,1000},best=999999,scost[100],vcost[100];
int move(int cost) {
  char open[4],c,ok;
  int i,j,k,n,m;
  if(cost>best) return cost;
  ok=1;
  for(i=0;i<4;i++) for (j=0;j<4;j++) if(rooms[i][j]!=i+1) ok=0;
  if (ok) {
    if(cost<best) {
      best=cost;
      memcpy(vi,si,sizeof(vi)); memcpy(vj,sj,sizeof(vj)); memcpy(vk,sk,sizeof(vk)); memcpy(vcost,scost,sizeof(vcost)); vkkk=kkk;
    }  
    return cost;
  }   
  for (i=0; i<4; i++) {
    open[i]=4;
    for (j=0;j<4;j++) {
      if (rooms[i][j]==0) {
        open[i]=j+1;
        break;
      }  
      if(rooms[i][j]!=i+1) {
        open[i]=0;
        break;
      }
    }
  }
  for (n=0;n<7;n++) {
    c=hall[n]; 
    if(c&&open[c-1]) {
      i=c-1;
      k=open[i]-1;
      ok=1;
      for (m=n+1;m<i+2;m++) if(hall[m]) ok=0;
      for (m=i+2;m<n;m++) if(hall[m]) ok=0;
      if (ok) {
        rooms[i][k]=c;
        hall[n]=0;
        si[kkk]=i;sj[kkk]=k;sk[kkk]=n;scost[kkk]=cost+ncost[c]*dist[i][k][n];kkk++;
        move(cost+ncost[c]*dist[i][k][n]);
        kkk--;
        hall[n]=c;
        rooms[i][k]=0;
      }
    }
  }  
  for (j=0;j<4;j++) {
    for (i=0;i<4;i++) {
      if(open[i]) continue;
      if((j==3||rooms[i][j]==0)&&rooms[i][j-1]) {
        if(rooms[i][j]) k=j; else k=j-1;
        c=rooms[i][k];
        for(n=0;n<7;n++) {
          ok=1;
          for (m=n;m<i+2;m++) if (hall[m]) ok=0;
          for (m=i+2;m<=n;m++) if (hall[m]) ok=0;
          if (ok) {
            rooms[i][k]=0;
            hall[n]=c;
            si[kkk]=i;sj[kkk]=k;sk[kkk]=n;scost[kkk]=cost+ncost[c]*dist[i][k][n]; kkk++;
            move(cost+ncost[c]*dist[i][k][n]);
            kkk--;
            rooms[i][k]=c;
            hall[n]=0;
          } 
        }              
      }
    }
  }          
  }       
int main(int argc,char **argv) {
  int i;
  move(0);
  printf("best=%d\n",best);
//  next line prints moves for best solution  
//  for(i=0;i<vkkk;i++) printf("rooms[%d][%d] hall[%d] dist=%d cost=%d\n",vi[i],vj[i],vk[i],dist[vi[i]][vj[i]][vk[i]],vcost[i]);
}
