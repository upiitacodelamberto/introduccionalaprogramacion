#include <stdio.h>
#include <stdlib.h>
void bits_dint(int intNum); /*prototipo de una funcion*/
//#define MAIN
#ifdef MAIN
int main(int argc, char *argv[])
{
  scanf("%d",&argc);
  bits_dint(argc);
  system("PAUSE");	
  return 0;
}/*end main()*/
#endif /*MAIN*/
void bits_dint(int intNum){
  int tamNBits=8*sizeof(intNum);
  int i=tamNBits-1;
  while(i>=0){
    printf("%d",(intNum>>i)&0x1);
    i--;
  }
}
