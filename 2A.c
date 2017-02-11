#include<stdio.h>

int main(int argc,char *argv[]){
  FILE *fp;
  int i,ch0,ch1,ch2,marker=0;
  for(i=1;i<argc;i++){
    if((fp=fopen(argv[i],"r"))==NULL){
      fprintf(stderr,"cannot open %s\n",argv[i]);
      continue;
    }
    ch0=getc(fp);
    ch1=getc(fp);
    while(ch0!=EOF){
      ch2=getc(fp);
      if(marker==0){
        putchar(ch0);
      }
      if((ch1=='/')&&(ch2=='/')){
        marker++;
      }
      if(marker>=1){
        if(ch1=='\n'){
          marker=0;
        }
      }
      ch0=ch1;
      ch1=ch2;
     }
      fclose(fp);
}
}
