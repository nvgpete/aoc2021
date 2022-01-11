#include <stdio.h>
#include <string.h>
  int main(int argc,char **argv) {
  FILE *f,*f2;
  char s[100],*s2,*op,reg,*vv;
  f2=fopen("d24s.c","w");
  fprintf(f2,"#include <stdio.h>\n");
  fprintf(f2,"int monad(int *d) {\n");
  fprintf(f2,"int w=0,x=0,y=0,z=0;\n");

  f=fopen("d24a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if(s2=strchr(s,'\n'))*s2=0;
    op=s;
    reg=s[4];
    vv=s+6;
    if(s2=strchr(vv,' '))*s2=0;
    if(strncmp(op,"inp",3)==0) fprintf(f2,"  %c=*(d++);\n",reg);
     else if (strncmp(op,"add",3)==0) fprintf(f2,"  %c+=%s;\n",reg,vv);
     else if (strncmp(op,"mul",3)==0) fprintf(f2,"  %c*=%s;\n",reg,vv);
     else if (strncmp(op,"div",3)==0) fprintf(f2,"  %c/=%s;\n",reg,vv);
     else if (strncmp(op,"mod",3)==0) fprintf(f2,"  %c%%=%s;\n",reg,vv);
     else if (strncmp(op,"eql",3)==0) fprintf(f2,"  %c=(%c==%s);\n",reg,reg,vv);
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  fprintf(f2,"  return z;\n}\n"); 
  fclose(f2);
}
