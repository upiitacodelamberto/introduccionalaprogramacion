#include <stdio.h>
#include <stdlib.h>
#define SWAP_AND_CAT_BYTES(intByteH,intByteL)		((intByteH)|( ((intByteL)<<(8))&(0x0000ff00))) 
#define SWAP_AND_CAT_WORDS(intWordH,intWordL)	(((0xffff0000)&((intWordH)<<(16)))|(intWordL))
#define SPACE_OR_NOT(i)	((i%5)==0)?"":"        "
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
* recibe un entero de la forma 0x0000MNRS y devuelve un entero
* de la forma 0x0000RSMN
*/
/* variable global */
int cuenta;		/* cuantas veces se ha ingresado a alguna funcion 
definida en esta proyecto  */
int funciondenteros(int intBL){
	static int intFunciondenteros=0;
	int intByteL=0x000000ff&intBL;			// A1// B1
	int intByteH=0x000000ff&(intBL>>8);		// A2// B2
	//int tmp=intByteL;						// A3// B3
	//intByteL=intByteH;						// A4// B4
	//return intByteL|((tmp<<8)&0x0000ff00);	// A5// B5
	printf("intFunciondenteros=%d\n",++intFunciondenteros);
	cuenta++;
	return SWAP_AND_CAT_BYTES(intByteH,intByteL);
}
int main(int argc, char *argv[]) {
	int intA,intBH,intBL,intByteH,intByteL,intWordL,intWordH,tmp,i;
	static int intMain=0;
	printf("intMain=%d\n",++intMain);
	cuenta++;
	printf("cuenta=%d\n",cuenta);
	printf("Para un int se usan %i bytes\n",sizeof(intA));
	printf("Para un int se usan %i bytes\n",sizeof(int));
	printf("%c\t%i\n\n",0x48,0x48);/* imprime la letra H */
	union Regard{
		int saludo;
		char c[4];
	} ache,*p;
	/*
	H 0x48, O 0x4f, L 0x4c, A  0x41, \0  0x00
	0x4f4c4100--->0x41004f4c--->0x00414c4f
	saludo=0x00414c4f
	*/
	intA=0x4f4c4100;
	printf("intA=%x\n",intA);
	int funcion_para_saludo(int);
//B0:	intBL=0x0000ffff&intA;	/* word baja */
//A0:	intBH=0x0000ffff&(intA>>16);	/* word alta */
////	printf("intBH=0x%x\tintBL=0x%x\n",intBH,intBL);
////A1:	intByteL=0x000000ff&intBH;	/*esto se hace en funciondenteros*/
////A2:	intByteH=0x000000ff&(intBH>>8);/*esto se hace en funciondenteros*/
////	printf("intByteH=0x%x\tintByteL=0x%x\n",intByteH,intByteL);
////A3:	tmp=intByteL;				/*esto se hace en funciondenteros*/
////A4:	intByteL=intByteH;			/*esto tmb se hace en funciondenteros*/
////A5:	intWordL=intByteL|((tmp<<8)&0x0000ff00);	/*esto tmb se hace en funciondenteros*/
//C3:	intWordL=funciondenteros(intBH);/*se esta pasando la word alta*/
//	printf(".....>intWordL=0x%x\n",intWordL);
////B1:	intByteL=0x000000ff&intBL; 
////B2:	intByteH=0x000000ff&(intBL>>8);
////B3:	tmp=intByteL;
////B4:	intByteL=intByteH;
////B5:	intWordH=intByteL|((tmp<<8)&0x0000ff00);
//C4:	intWordH=funciondenteros(intBL);/*se esta pasando la word baja*/
//	printf(".....>intWordH=0x%x\n",intWordH);
	p=&ache;
	/*p->saludo=0x00414c4f;*/
//C5:	p->saludo=tmp=(0xffff0000&(intWordH<<16))|intWordL;
//	p->saludo=tmp=funcion_para_saludo(intA);
//	printf("p->saludo=0x%x\n",p->saludo);
//	printf("H%s ",p->c);
		p->saludo=funcion_para_saludo(0x484f4c00);
		printf("%s",p->c);
		p->saludo=funcion_para_saludo(0x41204d00);
		printf("%s",p->c);
		p->saludo=funcion_para_saludo(0x554e4400);
		printf("%s",p->c);
		p->saludo=funcion_para_saludo(0x4f204300);
		printf("%s",p->c);
		printf("\n");
		for(i=0;i<26;i++){
				printf("%s%c  %x",SPACE_OR_NOT(i),'A'+i,'A'+i);
			if((i+1)%5==0){
				printf("\n");
			}
		}
		printf("\n");
		union Regard unionR[4];
		unionR[0].saludo=funcion_para_saludo(0x484f4c00);
		unionR[1].saludo=funcion_para_saludo(0x41204d00);
		unionR[2].saludo=funcion_para_saludo(0x554e4400);
		unionR[3].saludo=funcion_para_saludo(0x4f204300);
		printf("cuenta=%d\n",cuenta);
		for(i=0;i<4;i++){
			printf("%s",unionR[i].c);
		}
		printf("\n");
/*	printf("%i",(tmp>>31)&0x1);
	printf("%i",(tmp>>30)&0x1);
	printf("%i",(tmp>>29)&0x1);
	printf("%i",(tmp>>28)&0x1);
	printf("%i",(tmp>>27)&0x1);
	printf("%i",(tmp>>26)&0x1);
	printf("%i",(tmp>>25)&0x1);
	printf("%i",(tmp>>24)&0x1);
	printf("%i",(tmp>>23)&0x1);
	printf("%i",(tmp>>22)&0x1);
	printf("%i",(tmp>>21)&0x1);
	printf("%i",(tmp>>20)&0x1);
	printf("%i",(tmp>>19)&0x1);
	printf("%i",(tmp>>18)&0x1);
	printf("%i",(tmp>>17)&0x1);
	printf("%i",(tmp>>16)&0x1);
	printf("%i",(tmp>>15)&0x1);
	printf("%i",(tmp>>14)&0x1);
	printf("%i",(tmp>>13)&0x1);
	printf("%i",(tmp>>12)&0x1);
	printf("%i",(tmp>>11)&0x1);
	printf("%i",(tmp>>10)&0x1);
	printf("%i",(tmp>>9)&0x1);
	printf("%i",(tmp>>8)&0x1);
	printf("%i",(tmp>>7)&0x1);
	printf("%i",(tmp>>6)&0x1);
	printf("%i",(tmp>>5)&0x1);
	printf("%i",(tmp>>4)&0x1);
	printf("%i",(tmp>>3)&0x1);
	printf("%i",(tmp>>2)&0x1);
	printf("%i",(tmp>>1)&0x1);
	printf("%i",(tmp>>0)&0x1);*/
	for(i=31;i>=0;i--){
		printf("%d",(tmp>>i)&0x1);
	}
	printf("\n");
	printf("Para el int p->saludo se usan %i bytes\n",sizeof(p->saludo));
	printf("Para el arreglo  p->c se usan %i bytes\n",sizeof(p->c));
	printf("Pointer a p->saludo:%p\n",&p->saludo);
/*	printf("Pointer a p->c[0]:%p\n",&p->c[0]);
	printf("Pointer a p->c[1]:%p\n",&p->c[1]);
	printf("Pointer a p->c[2]:%p\n",&p->c[2]);
	printf("Pointer a p->c[3]:%p\n",&p->c[3]);*/
	for(i=0;i<4;i++){
		printf("Pointer a p->c[%d]:%p\n",i,&p->c[i]);	
	}
	void despedida(void);
	despedida();
	printf("cuenta=%i",cuenta);
	return 0;
}/*end main()*/

int
funcion_para_saludo(int intA)
{
	static int intFuncion_para_saludo=0;		/*cuantas veces se ha llamado a esta funcion */
	printf("intFuncion_para_saludo=%d\n",++intFuncion_para_saludo);
	int intBL=0x0000ffff&intA;	/* word baja */							// B0
	int intBH=0x0000ffff&(intA>>16);	/* word alta */					// A0
	int intWordL=funciondenteros(intBH);/*se esta pasando la word alta*/// C3
	printf("cuenta=%d\n",cuenta);
	int intWordH=funciondenteros(intBL);/*se esta pasando la word baja*/// C4
	printf("cuenta=%d\n",cuenta);
	//return ((0xffff0000)&((intWordH)<<(16)))|(intWordL);				// C5
	cuenta++;
	return SWAP_AND_CAT_WORDS(intWordH,intWordL);
}
