/**
 * sistddosec.c 
 */
#include <stdlib.h>     /* malloc() */
#include "sistddosec.h"

struct sistddosec *inic_sis(float ma[2][3],int numDEcs,int numDVars){
  int i,j;
  struct sistddosec *structResult=(struct sistddosec *)
                    malloc(sizeof(*structResult));
  structResult->M=numDEcs;
  structResult->N=numDVars+1;
  structResult->MA=(float**)malloc(numDEcs*sizeof(float*));
  for(i=0;i<numDEcs;i++){
    structResult->MA[i]=(float*)malloc((structResult->N)*sizeof(float));
  }
  for(i=0;i<numDEcs;i++){
    for(j=0;j<numDVars+1;j++){
      *(*(structResult->MA+i)+j)=ma[i][j];
    }
  }
  return structResult;
}
 

void print_sistddosec(struct sistddosec *sisddosecPt){
  int i,j;
  for(i=0;i<sisddosecPt->M;i++){
    for(j=0;j<=sisddosecPt->N-3;j++){
      printf(" %.2f x_%d +",sisddosecPt->MA[i][j],j+1);
    }
    printf(" %.2f x_%d",sisddosecPt->MA[i][sisddosecPt->N-2],j+1);
    printf(" = %.2f\n",sisddosecPt->MA[i][sisddosecPt->N-1]);
  }
}

void mostrar_sist_decs(float ma[2][3],int numDEcs,int numDVars){
  struct sistddosec *ejem=(struct sistddosec *)inic_sis(ma,2,2);
  print_sistddosec(ejem);
}
