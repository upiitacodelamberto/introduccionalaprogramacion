#include <stdio.h>
#include <stdlib.h>
#define MATRIZ_INVERSA 0
#define MATRIX         2
#define SUBM(fil,col) float SM##fil##col[2][2]
#define subm(k,w,i,j) SM##k##w[i][j]
//#ifdef MATRIZ_INVERSA
#if(MATRIZ_INVERSA >= MATRIX)
#error ESTE ERROR ES DELIBERADO 20171025
#endif
//#endif
#define PI  3.141592
#define NOMBC(first,last)      int first##_##last
#define maximo(a,b) (a>b)?a:b

#define show_m3x3(c)	\
printf("\t%f\t%f\t%f\n",c[0][0],c[0][1],c[0][2]);\
printf("\t%f\t%f\t%f\n",c[1][0],c[1][1],c[1][2]);\
printf("\t%f\t%f\t%f\n",c[2][0],c[2][1],c[2][2]);\
printf("\n");

#define show_m2x2(c)	\
printf("\t%f\t%f\n",c[0][0],c[0][1]);\
printf("\t%f\t%f\n",c[1][0],c[1][1]);\
printf("\n");

#define SUBM2x2	printf("SUBMATRICES DE 2 x 2\n")
#define SM(i,j)	printf("SM%d%d[2][2] =\n",i,j)

#define LMC0
#define LMC1


int main(int argc, char *argv[])
{
  int i,j,k,w;
  float area=PI*10*10;
  NOMBC(Beto,Maza);   /* int Beto_Maza;*/
  Beto_Maza=maximo(10.5,20);
  printf("%d\n",Beto_Maza);
  float A[3][3]={{1,3,5},{7,9,11},{13,15,17}};
  show_m3x3(A);
  /**********************************************/
#ifndef LMC0
  for(k=0;k<3;k++){
    for(w=0;w<3;w++){
  SUBM(k,w);//
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<k && j<w){
//          SM00[i][j]=A[i][j];
          subm(k,w,i,j)=A[i][j];
        }
        if(i<k && j>w){
//          SM00[i][j-1]=A[i][j];
          subm(k,w,i,j-1)=A[i][j];
        }
        if(i>0 && j<0){
//          SM00[i-1][j]=A[i][j];
          subm(k,w,i-1,j)=A[i][j];
        }
        if(i>0 && j>0){
//          SM00[i-1][j-1]=A[i][j];
          subm(k,w,i-1,j-1)=A[i][j];
        }
      }//end for()
    }//end for() 
  for(i=0;i<2;i++){
      for(j=0;j<2;j++){
//        printf("\t%f",SM00[i][j]);
        printf("\t%f",subm(k,w,i,j));
      }
      printf("\n");
    }
    printf("/***********************************/\n");
}//end for, k
}//end for, w
#endif /* LMC0 */
#ifdef LMC1
  SUBM2x2;
  SM(0,0);
  SUBM(0,0);// float SM00[2][2];
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<k && j<w){
          SM00[i][j]=A[i][j];
        }
        if(i<k && j>w){
          SM00[i][j-1]=A[i][j];
        }
        if(i>0 && j<0){
          SM00[i-1][j]=A[i][j];
        }
        if(i>0 && j>0){
          SM00[i-1][j-1]=A[i][j];
        }
      }//end for()
    }//end for() 
  for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        printf("\t%f",SM00[i][j]);
      }
      printf("\n");
  }
  show_m2x2(SM00);
    printf("/***********************************/\n");
    /************************************/
    SUBM(0,1);// float SM01[2][2];
    SM(0,1);
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<0 && j<1){
          SM01[i][j]=A[i][j];
        }
        if(i<0 && j>1){
          SM01[i][j-1]=A[i][j];
        }
        if(i>0 && j<1){
          SM01[i-1][j]=A[i][j];
        }
        if(i>0 && j>1){
          SM01[i-1][j-1]=A[i][j];
        }
      }//end for()
    }//end for()
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        printf("\t%f",SM01[i][j]);
      }
      printf("\n");
    }
    printf("/***********************************/\n");
    /**************************************************/
    SUBM(0,2);
    SM(0,2);
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){               
        if(i<0 && j<2){
          SM02[i][j]=A[i][j];
        }
        if(i<0 && j>2){
          SM02[i][j-1]=A[i][j];
        }
        if(i>0 && j<2){
          SM02[i-1][j]=A[i][j];
        }
        if(i>0 && j>2){
          SM02[i-1][j-1]=A[i][j];
        }
      }//end for()
    }//end for()
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        printf("\t%f",SM02[i][j]);
      }
      printf("\n");
    }
    printf("/***********************************/\n");
#endif /* LMC1 */
  system("PAUSE");	
  return 0;
}
