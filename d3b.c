#include <stdio.h>
#include <string.h>
#define BITS 12
int main(int argc,char **argv) {
FILE *f;
char s[100];
int  i,ones,zeros,x1,x2,lines=0,n1,n2,y,list[10000],cut,bit;
f=fopen("d3a.txt","r");
fgets(s,100,f);
while (!feof(f)) {
  y=0;
  for (i=0;i<BITS;i++) y+=y+*(s+i)-'0';
  i=lines-1;
  while (i>=0 && list[i]>y) {
    list[i+1]=list[i];
    i--;
  }
  list[i+1]=y;
  lines++;  
  fgets(s,100,f);
} 
  n1=0;
  n2=lines-1;
  bit=1<<(BITS-1);
  cut=bit;
  while (n1!=n2) {
    bit>>=1;
    i=0;
    while (i<=n2 && list[i]<cut) i++;
    ones=n2-i+1;
    zeros=i-n1; 
    if (ones>=zeros) {
      n1=i;
      cut+=bit;
    } else {
      n2=i-1;
      cut-=bit;
    }  
  }
  x1=list[n1];  
  n1=0;
  n2=lines-1;
  bit=1<<(BITS-1);
  cut=bit;
  while (n1!=n2) {
    bit>>=1;
    i=0;
    while (i<=n2 && list[i]<cut) i++;
    ones=n2-i+1;
    zeros=i-n1; 
    if (ones>=zeros) {
      n2=i-1;
      cut-=bit;
    } else {
      n1=i;
      cut+=bit;
    }  
  }
//  for (i=0; i<lines; i++) printf("%d\n",list[i]);
  x2=list[n1];
  printf("%d %d %d\n",x1,x2,x1*x2);  
  fclose(f); 
}
