#include <stdio.h>
#include <string.h>
char rts[20][10],small[20],visit[20],name[20][10],twice=0;
int count=0;
void mv(int i) {
  char oldtwice,oldvisit;
  int j;
  if (i==1) {count++; return;}
  if (small[i]) {
    if(twice&&visit[i]) return;
    oldtwice=twice;
    oldvisit=visit[i];
    if (visit[i]) twice=1; else visit[i]=1;
  }  
  j=0;
  while (rts[i][j]) { mv(rts[i][j]); j++;}
  if (small[i]) {
    visit[i]=oldvisit;
    twice=oldtwice;
  }  
}  
int main(int argc,char **argv) {
FILE *f;
char s[100],*s2;
int last=2,c1,c2,i;
strcpy(name[0],"start");
strcpy(name[1],"end");
for (c1=0;c1<20;c1++) visit[c1]=rts[c1][0]=0;
f=fopen("d12a.txt","r");
fgets(s,sizeof(s),f);
while (!feof(f)) {
  if (s2=strchr(s,'\n')) *s2=0;
  s2=strchr(s,'-')+1;
  *(s2-1)=0;
  for (c1=0;c1<last;c1++) if(!strcmp(s,name[c1])) break;
  if (c1==last) {strcpy(name[c1],s); small[last++]=(*s>='a');}  
  for (c2=0;c2<last;c2++) if(!strcmp(s2,name[c2])) break;
  if (c2==last) {strcpy(name[c2],s2); small[last++]=(*s2>='a');}
  if (c2&&c1!=1) {i=0; while (rts[c1][i]) i++; rts[c1][i]=c2;}  
  if (c1&&c2!=1) {i=0; while (rts[c2][i]) i++; rts[c2][i]=c1;}  
  fgets(s,sizeof(s),f);
}  
//  for (c1=0;c1<last;c1++) { printf("%d %s %d",c1,name[c1],small[c1]);i=0;while(rts[c1][i]) { printf(" %d",rts[c1][i]); i++;} printf("\n");}
  fclose(f);
  mv(0); 
  printf("count=%d\n",count);
}
