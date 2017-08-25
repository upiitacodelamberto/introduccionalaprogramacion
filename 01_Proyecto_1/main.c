#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* variable global */
#define TAM	10	/* una constante */

int boleta[TAM];	/* arreglo de int, un tipo de dato compuesto */ 
/* 1 si SI esta, 0 si NO esta*/
int buscar(int Eq[]);
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
	int equipo0[]={boleta[0],boleta[3]};
	int equipo1[]={boleta[2],boleta[6]};
	int equipo2[]={boleta[5],boleta[8]};
	
	/*No estan en un quipo:
	 boleta[1], boleta[4],boleta[7], boleta[9]*/
	int Resultado[TAM];
	Resultado[0]=buscar(boleta[0]);
	Resultado[1]=buscar(boleta[1]);
	Resultado[2]=buscar(boleta[2]);
	
	
	
	
	return 0;
}

int buscar(int intBol){
	
}
