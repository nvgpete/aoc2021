#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[208][208],s3[208][208],xlat[515],*s2,c;
  int i,j,k=53,n,v,i2,j2,count,count2;
  memset(s,'.',sizeof(s));
  memset(s3,'.',sizeof(s3));
  f=fopen("d20a.txt","r");
  fgets(xlat,sizeof(xlat),f);
  fgets(s[99],sizeof(s[99]),f);
  fgets(s[k]+53,sizeof(s[0]),f);
  while (!feof(f)) {
    if(s2=strchr(s[k],'\n'))*s2='.';
    n=strlen(s[k]);
    s[n][k]='.';
    k++;
    fgets(s[k]+53,sizeof(s[0]),f);
  }  
  fclose(f); 
  for (k=0;k<50;k++) {
    for (j=1;j<207;j++) for (i=1;i<207;i++) {
      v=0;
      for(j2=j-1;j2<=j+1;j2++) for (i2=i-1;i2<=i+1;i2++) {
        v+=v+(s[j2][i2]=='#');
        s3[j][i]=xlat[v];
      }
    }
    if (xlat[0]=='#') {
      c=s3[1][1];
      for (i=0;i<207;i++) {
        s3[0][i]=c;
        s3[207][i]=c; 
        s3[i][0]=c;
        s3[i][207]=c;
      }  
    }   
    memcpy(s,s3,sizeof(s));
    if (k==1) {
      count2=0;
      for (j=0;j<208;j++) for (i=0;i<208;i++) count2+=(s[j][i]=='#');
    }       
  }      
  count=0;
  for (j=0;j<208;j++) for (i=0;i<208;i++) count+=(s[j][i]=='#');
  printf("Count of '#' pixels\nAfter  2 iterations=%d\nAfter 50 iterations=%d\n",count2,count);
}