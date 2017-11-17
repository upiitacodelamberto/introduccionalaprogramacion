#include <stdio.h>
#include <stdlib.h>	/*int atoi(const char *nptr)*/
int comparar(char *,char *);
int get_seccion(char strCas[128],char str[64]);
int main(void){
  char line[]="Seccion,Distrito,Tipo,PRI,PAN,PRD,MORENA,NUEVA ALIANZA,PT,PARTIDO VERDE";
  char casilla[2][128]={
    {"9,200,B,380,256,315,4,20,46,57"},
    {"45675,14,C,380,256,315,4,20,46,57"}
  };
  if(comparar(casilla[0],casilla[1])==1){
    printf("SON IGUALES");
  }else{
    printf("SON DIFERENTES");
  }
  return 0;
}/*end main()*/

int comparar(char c1[128],char c2[128]){
  int s1,s2;
  char Cas[128],Sec[64];
  Sec[get_seccion(c1,Sec)]='\0';
  s1=atoi(Sec);
  Sec[get_seccion(c2,Sec)]='\0';
  s2=atoi(Sec);
  printf("%s\n",Sec);
  return (s1==s2)?1:0;
}
int get_seccion(char strCas[128],char str[64]){
  int i=0;
  while(strCas[i]!=','){
    str[i]=strCas[i];
    i=i+1;
  }
  return i;
}
