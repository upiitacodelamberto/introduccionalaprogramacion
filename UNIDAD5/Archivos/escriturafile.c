#include <stdio.h>
#include <string.h> /*memset()*/
#define MAXSIZE	1024
int
main(void){
  FILE *file;
  char buf[MAXSIZE];
  int intCount=0;
  memset(buf,0,MAXSIZE);
  file=fopen("fuente.S","r");
//  do{
//    fread(buf,1,1,file);/*leer 1 char una vez*/
//    printf("%s",buf);
//    intCount++;
//  }while((buf[0]!='!')&&(buf[0]!='\n')&&(intCount<MAXSIZE));
  fread(buf,1,1,file);/*leer 1 char una vez*/
  while((buf[0]!='!')&&(buf[0]!='\n')&&(intCount<MAXSIZE)){
    printf("%s",buf);
    intCount++;
    fread(buf,1,1,file);
  }
  fclose(file);

  file=fopen("out.txt","w+");
  fprintf(file,"%d de diciembre de %d\n",6,2017);
  

  char str[64];
  sprintf(str,"%d%d%d%d",0,0,0,1);
  printf("%s\n",str);
  fprintf(file,str);
  fclose(file);
  return 0;
}//end main()
