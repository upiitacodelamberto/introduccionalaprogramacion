/** main.c Presenta en pantalla de 10 en 10 los bytes de 
 * un arreglo que contiene un programa ejecutable para el 
 * procesador ARC (A Risc Computer de Murdocca)
 */
#include <stdio.h>
#include <stdlib.h>
/* el programa ejecutable para la ARC */
unsigned char Byte[]={0xc2,0x00,0x28,0x10,0xc4,0x00,
0x28,0x14,0x86,0x80,0x40,0x02,0xc6,0x20,0x28,
0x18};//0x18 esta en 2063

int main(int argc, char *argv[])
{
  int dir_inic=2048,i,tam,mostrados=0,nomostrados;
  /* cantidad de elementos del arreglo Byte */
  tam=sizeof(Byte)/sizeof(unsigned char);
//  nomostrados=tam-mostrados;
//  
//  if(tam>=10){
//    for(i=0;i<10;i++){
//      printf("%d\t%d\n",dir_inic+i,Byte[i]);
//    }
//    mostrados=10;
//  }else{
//    for(i=0;i<tam;i++){
//      printf("%d\t%d\n",dir_inic+i,Byte[i]);
//    }
//    system("PAUSE");
//    //return tam; /* tiene sentido si tam<=255 */
//    //mostrados=tam;    
//  }
//  nomostrados=tam-mostrados;
//  system("PAUSE");
//
//  if(tam-mostrados>=10){
//    for(i=mostrados;i<mostrados+10;i++){
//      printf("%d\t%d\n",dir_inic+i,Byte[i]);
//    }
//    mostrados=mostrados+10;
//  }else{/*for(i=mostrados;i<mostrados+tam-mostrados;i++)*/
//    for(i=mostrados;i<tam;i++){
//      printf("%d\t%d\n",dir_inic+i,Byte[i]);
//    }
//    //mostrados=mostrados+tam-mostrados;
//    mostrados=tam;
// }
//  nomostrados=tam-mostrados;
//  system("PAUSE");
//  
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
