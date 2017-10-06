/**
 * arreglosbidimensionales.c
 * Grupo de Introducción a la programación 1MV2. En la clase de hoy lunes 18 de 
 * agosto de 2017, faltaba agregar los tres archivos de cabecera siguientes. 
 * Descarguen este archivo y comprueben que ahora si ya este archivo se compila 
 * y se ejecuta correctamente.
 * 
 * Prof. Beto
 * Saludos 
 */
#include <stdio.h>         /* printf()*/
#include <stdlib.h>        /* atof() */
#include "sistddosec.h"

 float MA[2][3];  /*Matriz Aumentada de un sistema de 2x2*/
 
 
 long
 main(int argc,char *argv[])
{
  int i,j;
  if(argc<6){
    printf("Forma de uso:./%s float1 float2 float3 \
float4 float5 float6\n",argv[0]);
    system("pause");
    return 0;
  }
  /* Funcion a utilizar:
     ((0,0),1) --> ((0,0),0+1)
     ((0,1),2) --> ((0,1),1+1)
     ((0,2),3) --> ((0,2),2+1)
     ((1,0),4) --> ((1,0),0+4)
     ((1,1),5) --> ((1,1),1+4)
     ((1,2),6) --> ((1,2),2+4)
  */
  for(i=0;i<2;i++){
    for(j=0;j<3;j++){
      MA[i][j]=atof(argv[((i==0)?j+1:j+4)]);
      printf("%f\t",MA[i][j]);
    }printf("\n");
  }
  mostrar_sist_decs(MA,2,2);
  
  system("pause");
  return 0;
}
 
