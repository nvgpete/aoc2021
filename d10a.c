#include <stdio.h>
#include <string.h>
  
int main(int argc,char **argv) {
FILE *f;
char *s2,s[200],stk[200];
int sptr,err=0,line=0,n=0,last=0;
long x,nn[100];
f=fopen("d10a.txt","r");
fgets(s,200,f);
if (s2=strchr(s,'\n')) *s2=0;
while (!feof(f)) {
  line++;
  sptr=0;
  s2=s;
  while (*s2) {
    if (*s2=='<'||*s2=='('||*s2=='{'||*s2=='[') stk[sptr++]=*s2;
    else if(*s2==')'&&stk[--sptr]!='(') { err+=3; break;}
    else if(*s2==']'&&stk[--sptr]!='[') { err+=57; break;}
    else if(*s2=='}'&&stk[--sptr]!='{') { err+=1197; break;}
    else if(*s2=='>'&&stk[--sptr]!='<') { err+=25137; break;}
    s2++;
  }
  if(!*s2) {  
    x=0;
//    printf("sptr=%d ",sptr);
    while (sptr) {
      sptr--;
//      printf("%c",stk[sptr]);
      x*=5;
      if (stk[sptr]=='(') x++;
      else if (stk[sptr]=='[') x+=2;
      else if (stk[sptr]=='{') x+=3;
      else if (stk[sptr]=='<') x+=4;
    }
    n=last;
    while (n&&x<nn[n-1]) {
      nn[n]=nn[n-1];
      n--;
    }
    last++;
    nn[n]=x;  
  }    
  fgets(s,200,f);
} 
  printf("part1=%d\n",err);
  printf("part2=%ld\n",nn[(last-1)/2]);   
  fclose(f); 
}
