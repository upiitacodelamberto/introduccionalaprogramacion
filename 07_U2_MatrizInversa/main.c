#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MATRIZ_INVERSA 0
#define MATRIX         2

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

//#define M3x3(fil,col) float M##fil##col[fil][col]
/*Matriz de cofACTORES*/
#define Mcof(M,fil,col) float M[fil][col]
/*declares a 2 times 2 array in order to be used 
 in macro MSUBM(f,c)*/
#define SUBM(fil,col) float SM##fil##col[2][2]
/* Make SUBMatrix ignoring row row & column col */
#define MSUBM(row,col,A)    for(i=0;i<3;i++){\
      for(j=0;j<3;j++){\
        if(i<row && j<col){\
          SM##row##col[i][j]=A[i][j];\
        }\
        if(i<row && j>col){\
          SM##row##col[i][j-1]=A[i][j];\
        }\
        if(i>row && j<col){\
          SM##row##col[i-1][j]=A[i][j];\
        }\
        if(i>row && j>col){\
          SM##row##col[i-1][j-1]=A[i][j];\
        }\
      }\
    }

#define DET2x2(sm2x2) sm2x2[0][0]*sm2x2[1][1]-\
sm2x2[0][1]*sm2x2[1][0]

#define M2x2name(i,j)  SM##i##j

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
  MSUBM(0,0,A);
  show_m2x2(SM00);
    printf("/***********************************/\n");
    /************************************/
  SM(0,1);
  SUBM(0,1);// float SM01[2][2];
  MSUBM(0,1,A);
  show_m2x2(SM01);

  printf("/***********************************/\n");
  /**************************************************/
  SM(0,2);
  SUBM(0,2);
  MSUBM(0,2,A);
  show_m2x2(SM02);
  printf("/***********************************/\n");
  SM(1,0);
  SUBM(1,0);
  MSUBM(1,0,A);
  show_m2x2(SM10);
  printf("/***********************************/\n");
  SM(1,1);
  SUBM(1,1);
  MSUBM(1,1,A);
  show_m2x2(SM11);
  printf("/***********************************/\n");
  SM(1,2);
  SUBM(1,2);
  MSUBM(1,2,A);
  show_m2x2(SM12);
  printf("/***********************************/\n");
  SM(2,0);
  SUBM(2,0);
  MSUBM(2,0,A);
  show_m2x2(SM20);
  printf("/***********************************/\n");
  SM(2,1);
  SUBM(2,1);
  MSUBM(2,1,A);
  show_m2x2(SM21);
  printf("/***********************************/\n");
  SM(2,2);
  SUBM(2,2);
  MSUBM(2,2,A);
  show_m2x2(SM22);
  printf("/***********************************/\n");    
  /*Matriz de cofactores*/
/*El problema se podria solucionar asi, pero no es lo que se pretende,
  ya que de esta forma se "hardcodea" el tamanio de la matriz a 3x3*/
//Mcof(MCof,3,3)={//float MCof[3][3]={
//    {pow(-1,0+0)*DET2x2(SM00),pow(-1,0+1)*DET2x2(SM01),pow(-1,0+2)*DET2x2(SM02)},
//    {pow(-1,1+0)*DET2x2(SM10),pow(-1,1+1)*DET2x2(SM11),pow(-1,1+2)*DET2x2(SM12)},
//    {pow(-1,2+0)*DET2x2(SM20),pow(-1,2+1)*DET2x2(SM21),pow(-1,2+2)*DET2x2(SM22)},
//  };
  Mcof(MCof,3,3); /*float MCof[3][3];*/
/*Lo que se necesita es un apuntador a arreglos de 2x2*/
//  float (*array2x2Pt)[2][2]=malloc(9*sizeof(float**));
//  float ***array2x2Pt=(float***)malloc(9*sizeof(float**));
//                      {SM00,SM01,SM02,
//                      SM10,SM11,SM12,
//                      SM20,SM21,SM22};
float dumm[2][2];
/*A pointer to 2x2 float array*/
float (*array2x2Pt)[2][2]=malloc(20*sizeof(dumm));
array2x2Pt[0]=(float**)SM00;
//{  /*horrible mistake!!*/
//    SM00,SM01,SM02,
//    SM10,SM11,SM12,
//    SM20,SM21,SM22
//};
/*clumsy, pero no me quedo mas remedio que usar apuntadores */
  int index[3][3]={{0,1,2},{3,4,5},{6,7,8}};/*clumsy too!*/
  int var;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      var=array2x2Pt[index[i][j]];
      MCof[i][j]=pow(-1,i+j)*DET2x2(var);
    }
  }

  printf("Matriz de cofactores:\n");
  show_m3x3(MCof);
#endif /* LMC1 */
  system("PAUSE");	
  return 0;
}
