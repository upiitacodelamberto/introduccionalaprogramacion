#include <stdio.h>
#include <stdlib.h>
#define SUBM(fil,col) float subm##fil##col[2][2]

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j;
	float A[2][3]={{2,4,6},{8,10,12}};
	printf("A =\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("\t%f",A[i][j]);
		}
		printf("\n");
	}
	float At[3][2];
	//Obtencion de la matriz transpuesta
	printf("At =\n");
    for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("\t%f",At[i][j]=A[j][i]);
		}
		printf("\n");
	}

//	for(i=0;i<3;i++){
//		for(j=0;j<2;j++){
//			printf("\t%f",At[i][j]);
//		}
//		printf("\n");
//	}
    float C[3][3]={{1,3,5},{7,9,11},{13,15,17}};
    for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("\t%f",C[i][j]);
		}
		printf("\n");
	}
    SUBM(0,0);
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<0 && j<0){
          subm00[i][j]=C[i][j];
        }
        if(i<0 && j>0){
          subm00[i][j-1]=C[i][j];
        }
        if(i>0 && j<0){
          subm00[i-1][j]=C[i][j];
        }
        if(i>0 && j>0){
          subm00[i-1][j-1]=C[i][j];
        }
      }//end for()
    }//end for() 
    printf("subm =\n");
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        printf("\t%f",subm00[i][j]);
      }
      printf("\n");
    }
          
    system("pause");
	return 0;
}
