#include <stdio.h>
#include <stdlib.h>
#include "funrecursiva.h"
int main(int argc, char *argv[])
{
  int N=20;
  system("mode 100,120");
  system("color 70");
  printf("%i!=%d\n",N,factorial(N));
  
  int n=20,m=3;
  printf("20P3=%d\n",nPm(n,m));
  system("PAUSE");	
  return 0;
}
