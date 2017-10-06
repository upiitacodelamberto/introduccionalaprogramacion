/** main.c Presenta en pantalla de 10 en 10 los bytes de 
 * un arreglo que contiene un programa ejecutable para el 
 * procesador ARC (A Risc Computer de Murdocca)
 */
#include <stdio.h>
#include <stdlib.h>
/* el programa ejecutable para la ARC */
unsigned char Byte[]={
         /*2048*/0xc2,
         /*2049*/0x00,
         /*2050*/0x28,
         /*2051*/0x10,
         /*2052*/0xc4,
         /*2053*/0x00,
         /*2054*/0x28,
         /*2055*/0x14,
         /*2056*/0x86,
         /*2057*/0x80,
         /*2058*/0x40,
         /*2059*/0x02,
         /*2060*/0xc6,
         /*2061*/0x20,
         /*2062*/0x28,
         /*2063*/0x18,
         /*2064*/0x0,
         /*2065*/0x0,
         /*2066*/0x0,
         /*2067*/0x0f,
         /*2068*/0x0,
         /*2069*/0x0,
         /*2070*/0x0,
         /*2071*/0x03,
         /*2072*/0x0,
         /*2073*/0x0,
         /*2074*/0x0,
         /*2075*/0x0};

int main(int argc, char *argv[])
{
  int dir_inic=2048,i,tam,mostrados=0,nomostrados;
  /* cantidad de elementos del arreglo Byte */
  tam=sizeof(Byte)/sizeof(unsigned char);

  nomostrados=tam;mostrados=0;
  do{
    if(tam-mostrados>=10){
      for(i=mostrados;i<mostrados+10;i++){
        printf("%d\t%d\n",dir_inic+i,Byte[i]);
      }
      mostrados=mostrados+10;
      system("PAUSE"); 
    }else{
      for(i=mostrados;i<tam;i++){
        printf("%d\t%d\n",dir_inic+i,Byte[i]);
      }
      //mostrados=mostrados+tam-mostrados;
      mostrados=tam;
    }
    nomostrados=tam-mostrados;
  }while(nomostrados>0);
  system("PAUSE");
  return 0;
}//end main()
