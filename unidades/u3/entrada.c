#include <stdio.h>
#include <stdlib.h>
#define ENTRADA
#ifdef ENTRADA
void main(void){
  int intA;
  //printf("Teclea un entero: ");
  scanf("%i",&intA);
  printf("%i",intA);
  bits_dint(intA);
}
#endif /*ENTRADA*/
