#include <stdio.h>
#include <stdlib.h>

int
main(void){
  int m,n;/*filas, columnas*/
  int i,j;
  printf("Filas? ");scanf("%d",&m);
  printf("Colummnas? ");scanf("%d",&n);
  float **M=(float**)malloc(m*sizeof(float*));
  for(i=0;i<m;i++){
    M[i]=(float*)malloc(n*sizeof(float));
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("M[%d][%d]=",i,j);
      scanf("%f",*(M+i)+j);//M[i][j]=*(M[i]+j)=*(*(M+i)+j)
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%g\t",*(*(M+i)+j));
    }
    printf("\n");
  }
  return 0;
}//end main()
