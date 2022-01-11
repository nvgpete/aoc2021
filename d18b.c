#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned char add(unsigned char c1,unsigned char c2) {
  unsigned char cc;
  if (c1>127) c1&=127; else c1-='0';
  if (c2>127) c2&=127; else c2-='0';
  cc=c1+c2;
  if (cc>127) printf("Overflow\n");
  if (cc<10) cc+='0';
  else cc+=128;
  return cc;
}  
int main(int argc,char **argv) {
  FILE *f;
  unsigned char c,cc,s[200],s3[200],sdat[110][200],*ss,*ss2,*ss3,*last,save;
  int x,i,j,max=0,nb,changed,big=0;
  f=fopen("d18a.txt","r");
  i=0;
  fgets(sdat[0],sizeof(sdat[0]),f);
  while (!feof(f)) {
    if(ss=strchr(sdat[max],'\n'))*ss=0;
    max++;
    fgets(sdat[max],sizeof(sdat[0]),f);
  } 
  fclose(f); 
  for (i=0;i<max;i++) for (j=0;j<max;j++) if (i!=j) {  
    sprintf(s,"[%s,%s]",sdat[i],sdat[j]);
    do {
      changed=0;
      nb=0;
      last=NULL;
      save=0;
      ss=s; ss3=s3;
      while (c=*(ss++)) {
        if (c=='[') nb++;
        else if (c==']') nb--;
        else if (c!=',') {
          last=ss3;
          if (save) {
            c=add(c,save);
            save=0;
          }
        }    
        if (nb==5) {
          changed=1;
          if (save) *ss=add(*ss,save);
          if (last) *last=add(*last,*ss);
          last=ss3;
          c='0';
          save=*(ss+2);
          ss+=4;
          nb--;
        } 
        *(ss3++)=c;
      }      
      *ss3=0;
      if (changed) {
        strcpy(s,s3);
        changed=0;
      }
      if (nb) printf("MALFORMED!\n");
      ss=s; ss3=s3;
      while (c=*(ss++)) {
        if (!changed&&c>128) {
          changed=1;
          *ss3++='[';
          cc=(c&127)/2;
          if (cc<10) cc+='0'; else cc+=128;
          *ss3++=cc;
          *ss3++=',';
          cc=((c&127)+1)/2;
          if (cc<10) cc+='0'; else cc+=128;
          *ss3++=cc;
          c=']';
        }
        *ss3++=c;
      }
      *ss3=0;
      if (changed) {
        strcpy(s,s3);
      }  
    } while (changed);
    while (s[0]=='[') {
      ss=s;
      ss3=s3;
      while (*ss) {
        while (*ss&&(*ss!=','||*(ss-1)==']'||*(ss+1)=='[')) *(ss3++)=*(ss++);
        if (*ss) {
          ss2=ss;
          while (*ss2!='[') ss2--;
          x=atoi(ss2+1)*3+atoi(ss+1)*2;
          while (*ss!=']') ss++;
          ss++;
          ss3--;
          while (*ss3!='[') ss3--;
          sprintf(ss3,"%d",x);
          while (*ss3) ss3++;
        }  
      } 
      *ss3=0;
      strcpy(s,s3);
    }   
    sscanf(s,"%d",&x);
    if (x>big) big=x;
  }
  printf("Largest modulus=%d\n",big); 
}
