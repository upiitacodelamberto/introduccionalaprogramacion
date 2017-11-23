#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* variable global */
#define TAM	10	/* una constante */

int boleta[TAM];	/* arreglo de int, un tipo de dato compuesto */ 
/* 1 si SI esta, 0 si NO esta*/
int equipo0[2];//={boleta[0],boleta[3]};
int equipo1[2];//={boleta[2],boleta[6]};
int equipo2[2];//={boleta[5],boleta[8]};

int buscar(int);	/* protipo de la funcion buscar */
main() {
	boleta[0]=2017390771;
	boleta[1]=2017421589;
	boleta[2]=2015090216;
	boleta[3]=2015090796;
	boleta[4]=2013090223;
	boleta[5]=2015111316;
	boleta[6]=2015090606;
	boleta[7]=2015090114;
	boleta[8]=2015090345;
	boleta[9]=2015090584;
	
	/* declaracion por extension */
	equipo0[0]=boleta[0];equipo0[1]=boleta[3];
	equipo1[0]=boleta[2];equipo1[1]=boleta[6];
	equipo2[0]=boleta[5];equipo2[1]=boleta[8];
	
	/*No estan en un quipo:
	 boleta[1], boleta[4],boleta[7], boleta[9]*/
	int Resultado[TAM],i;
	Resultado[0]=buscar(boleta[0]);
	Resultado[1]=buscar(boleta[1]);
	Resultado[2]=buscar(boleta[2]);
	Resultado[3]=buscar(boleta[3]);
	Resultado[4]=buscar(boleta[4]);
	Resultado[5]=buscar(boleta[5]);
	Resultado[6]=buscar(boleta[6]);
	Resultado[7]=buscar(boleta[7]);
	Resultado[8]=buscar(boleta[8]);
	Resultado[9]=buscar(boleta[9]);
//	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
//		Resultado[0],
//		Resultado[1],
//		Resultado[2],
//		Resultado[3],
//		Resultado[4],
//		Resultado[5],
//		Resultado[6],
//		Resultado[7],
//		Resultado[8],
//		Resultado[9]);
	for(i=0;i<TAM;i++){
		printf("%d\t",Resultado[i]);
	}printf("\n");
//	if(Resultado[0]==0)printf("%d\n",boleta[0]);
//	if(Resultado[1]==0)printf("%d\n",boleta[1]);
	//...
//	if(Resultado[k]==0)printf("%d\n",boleta[k]);
	int k;
	for(k=0;k<TAM;k++){
		if(Resultado[k]==0)printf("boleta[%d]=%d\n",k,boleta[k]);
	}
	
	
	
	
	return 0;
}//end main()

int buscar(int intBol){//stub
	int intResult;
	intResult=((intBol==equipo0[0])||(intBol==equipo0[1]))?1:0;
	if(intResult==0)goto Equipo1;
	return intResult;
Equipo1:
	intResult=((intBol==equipo1[0])||(intBol==equipo1[1]))?1:0;
	if(intResult==0)goto Equipo2;
	return intResult;
Equipo2:
	intResult=((intBol==equipo2[0])||(intBol==equipo2[1]))?1:0;
	return intResult;
}
