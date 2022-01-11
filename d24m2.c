#include <stdio.h>
#include <string.h>
  int main(int argc,char **argv) {
  FILE *f,*f2;
  char s[100],*s2,*op,reg,*vv,b[1]={0};
  int i;
  f2=fopen("d24s2.c","w");
  fprintf(f2,"#include <stdio.h>\n");
  fprintf(f2,"int monad(int *d) {\n");
  fprintf(f2,"  int w=0,x=0,y=0,z=0;\n");
  fprintf(f2,"  int z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13;\n");

  f=fopen("d24a.txt","r");
  fgets(s,sizeof(s),f);
  i=0;
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    op=s;
    reg=s[4];
    vv=s+6;
    if(s2=strchr(vv,' '))*s2=0;
    if(strncmp(op,"inp",3)==0) {
//      fprintf(f2,"  %c=*(d++);\n",reg);
      if (i==0) {
        fprintf(f2,"#ifdef D0\n  %c=D0;\n  d[0]=D0;\n#else\n",reg);
        fprintf(f2,"  %c=d[0];\n#endif\n",reg);
      }  
      else {
        fprintf(f2,"%*sz%d=z;\n#ifdef UP\n",i*2,b,i);
        fprintf(f2,"%*sfor (d[%d]=1;d[%d]<10;d[%d]++) {\n#else\n",i*2,b,i,i,i);
        fprintf(f2,"%*sfor (d[%d]=9;d[%d]>0;d[%d]--) {\n#endif\n",i*2,b,i,i,i);
        fprintf(f2,"%*sz=z%d;\n%*sw=d[%d];\n",i*2+2,b,i,i*2+2,b,i);
      }
      i++; 
    }  
     else if (strncmp(op,"add",3)==0) fprintf(f2,"%*c+=%s;\n",i*2+1,reg,vv);
     else if (strncmp(op,"mul",3)==0) fprintf(f2,"%*c*=%s;\n",i*2+1,reg,vv);
     else if (strncmp(op,"div",3)==0) fprintf(f2,"%*c/=%s;\n",i*2+1,reg,vv);
     else if (strncmp(op,"mod",3)==0) fprintf(f2,"%*c%%=%s;\n",i*2+1,reg,vv);
     else if (strncmp(op,"eql",3)==0) fprintf(f2,"%*c=(%c==%s);\n",i*2+1,reg,reg,vv);
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  fprintf(f2,"%*sif(z==0) return z;\n",i*2,b);
  i--;
  while (i>0) {
    fprintf(f2,"%*s}\n",i*2,b);
    i--;
  }    
  fprintf(f2,"  return z;\n}\n"); 
  fclose(f2);
}
