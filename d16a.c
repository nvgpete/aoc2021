#include <stdio.h>
#include <string.h>
char *s2,s[1500],sbin[6000];
int data,left,vtot,nb;
int getbit() {
    nb++;
    if(!left) { sscanf(s2,"%8x",&data); left=32; s2+=8;}
    return (data>>(--left))&1;
}    
int getint(int n) {
  int i,j;
  for (i=0,j=0;i<n;i++) j=j+j+getbit();
  return j;
}
long parse() {
  long op,ival,j,k,pval;
  vtot+=getint(3);
  op=getint(3);
  if(op==4) {
    ival=0;
    do {
      j=getint(5);
      ival=ival*16+(j&15);
    } while(j>15);       
    return ival;
  }     
  if (getbit()) {
    j=getint(11);
    k=99999;
  } else {
    k=getint(15)+nb;
    j=99999;
  }
  ival=parse();
  j--;
  while (j--&&nb<k) {
    pval=parse();
    switch (op) {
      case 0: ival+=pval;
              break;
      case 1: ival*=pval;
              break;
      case 2: if (pval<ival) ival=pval;
              break;
      case 3: if (pval>ival) ival=pval;
              break;
      case 5: ival=(ival>pval);
              break;
      case 6: ival=(ival<pval);
              break;
      case 7: ival=(ival==pval);
    }
  }                                          
  return ival;  
}       
int main(int argc,char **argv) {
  FILE *f;
  int vv;
  f=fopen("d16a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    while ((vv=strlen(s))&7) { s[vv]='0'; s[vv+1]=0;}
    s2=s;
    left=0;
    vtot=0;
    nb=0;
    printf("version total=%d, result=%ld\n",vtot,parse());  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
}
