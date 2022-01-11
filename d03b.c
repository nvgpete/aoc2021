#include <stdio.h>
#include <string.h>
#define BITS 12
int main(int argc,char **argv) {
  FILE *f;
  char s[100];
  int i,ones,zeros,x1,x2,lines=0,n1,n2,y,list[1005],cut,bit;
  f=fopen("d03a.txt","r");
  fgets(s,sizeof(s),f);
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
    fgets(s,sizeof(s),f);
  } 
  fclose(f); 
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
  x2=list[n1];
  printf("Oxygen=%d CO2=%d product=%d\n",x1,x2,x1*x2);  
}
