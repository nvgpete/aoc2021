#include <stdio.h>
#include <string.h>
char bin(char *s){
  char c;
  c=0;
  while (*s) c+=1<<(*(s++)-'a');
  return c;
}   
int main(int argc,char **argv) {
  FILE *f;
  char ONE,FOUR,c,s[200],*s2,*s3;
  int v,i,sum,sum2=0;
  f=fopen("d08a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if (s2=strchr(s,'\n')) *s2=0;
    s2=strchr(s,'|')+2;
    *(s2-2)=0;
    s3=strtok(s," ");
    do {
      c=strlen(s3);
      if (c==2) ONE=bin(s3);
      else if (c==4) FOUR=bin(s3);
    } while(s3=strtok(NULL," "));  
    s3=strtok(s2," ");
    sum=0;
    do {
      i=strlen(s3);
      switch (i) {
        case 2: v=1; break;
        case 3: v=7; break;
        case 4: v=4; break;
        case 7: v=8; break;
        case 5: c=bin(s3);
                if((c&ONE)==ONE) v=3;
                else if(((c|ONE)&FOUR)==FOUR) v=5;
                else v=2;
                break;
        case 6: c=bin(s3);
                if((c&FOUR)==FOUR) v=9;
                else if((c&ONE)==ONE) v=0;
                else v=6;
        }
        sum=sum*10+v;                
    } while (s3=strtok(NULL," "));
    fgets(s,sizeof(s),f);
    sum2+=sum;
  }  
  printf("sum=%d\n",sum2);
  fclose(f);
}
  