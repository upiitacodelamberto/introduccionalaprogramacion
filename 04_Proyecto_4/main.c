#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int intVar,intVar2;
    float floatVar;
    printf("Teclea un entero: ");
    scanf("%d",&intVar);
    printf("Usted tecleo intVar=%d\n",intVar);
    printf("Teclea dos enteros: ");
    scanf("%d %d",&intVar,&intVar2);
    printf("Usted tecleo intVar=%d\tintVar2=%d\n",
           intVar,intVar2);
    printf("Teclea un valor real: ");
    scanf("%f",&floatVar);
    printf("Usted tecleo floatVar=%f\n",floatVar);
  
  system("PAUSE");	
  return 0;
}
