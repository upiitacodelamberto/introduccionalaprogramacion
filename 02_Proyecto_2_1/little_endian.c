/**
 * little_endian.c - programa para indagar el orden o la forma en que 
 * se colocan en memoria los bytes de una variable de tipo int por 
 * parte del microprocesador intel o AMD de la PC (configuracion Little
 * Endian).
 * Utiliza una union, que es un tipo de dato del lenguaje C.
 * El programa asume que el compilador utiliza 4 bytes para almacenar 
 * un int y un byte para almacenar un char.
 *
 * En la ARC (A RISC COMPUTER) de Miles J. Murdocca y Vincent P. Heuring 
 * [Principles of Computer Architecture, Class test edition - August 1999]
 * Archivo Principles_of_Computer_Architecture(Prentice_Hall-1999).pdf, 
 * una computadora de 32  bits, tanto las instrucciones como los datos son 
 * de 32 bits, sin embargo la memoria se direcciona a nivel de byte, por lo 
 * cual se utilizan cuatro localidades contiguas de la memoria principal 
 * para formar una instruccion o un dato. En la configuracion Big Endian 
 * (microprocesadores de 32 bits) el byte mas significativo se coloca en la 
 * direccion mas baja.
 *
 * El presente programa lo escribo para indagar en que direccion se coloca 
 * el byte mas significativo de un int en la memoria de la PC. Como se indica
 * en el comentario cerca del final de la funcion main(), en la PC el byte 
 * mas significativo se coloca en la direccion mas alta, lo que corresponde 
 * a la configuracion Little Endian.
 * 
 * Big Endian: Byte mas significativo se coloca en la direccion mas baja.
 * Little Endian: Byte mas significativo se coloca en la direccion mas alta.
 * procesador   Configuracion
 * SPARC        Big Endian     (Today 2017.09.05, el fabricante Fujitsu sigue
 *                              fabricando procesadores SPARC, Dr Moises Leon Ponce)
 * intel        Little Endian 
 */
#include <stdio.h>
#include <stdlib.h>
#define SWAP_AND_CAT_BYTES(intByteH,intByteL)		((intByteH)|( ((intByteL)<<(8))&(0x0000ff00))) 
#define SWAP_AND_CAT_WORDS(intWordH,intWordL)	(((0xffff0000)&((intWordH)<<(16)))|(intWordL))
#define SPACE_OR_NOT(i)	((i%5)==0)?"":"        "
//#define TABLA_ASCII
/**
 * Se utilizaran tres instancias del siguiente tipo de union para almacenar 
 * tres enteros que contendran la cadena HOLA MUNDO\lf\cr\0
 */
union my_int{/* Esta union basicamente es un int */
  int intNum;
  char charByte[4];
};
/**
 * estructura con campos de bits
 */
struct MyInt{
  unsigned byte0      :8;  /* byte menos significativo */
  unsigned byte1      :8;  
  unsigned byte2      :8;
  unsigned byte3      :8;  /* byte mas significativo*/
};
union my_int_MyInt{   /* Esta union tambien basicamente es un int */
  union my_int intVar;/* en el cual podemos, usando los campos de */
  struct MyInt MyInt; /* de la struct MyInt acceder a sus bytes */
};
 
int main(){
	int funcion_para_saludo(int),i;
	int funciondenteros(int intBL);
	/* Codigos ASCII del alfabeto ingles */
#ifdef TABLA_ASCII
    for(i=0;i<26;i++){
		printf("%s%c  %x",SPACE_OR_NOT(i),'A'+i,'A'+i);
		if((i+1)%5==0){
			printf("\n");
		}
	}
	printf("\n");
#endif /*TABLA_ASCII*/
	union my_int HOLA_MUNDO[4];
	HOLA_MUNDO[0].intNum=0x004c4f48;//funcion_para_saludo(0x484f4c00); /*HOL\0*/
	HOLA_MUNDO[1].intNum=0x004d2041;//funcion_para_saludo(0x41204d00); /*A M\0*/
	HOLA_MUNDO[2].intNum=0x00444e55;//funcion_para_saludo(0x554e4400); /*UND\0*/
	HOLA_MUNDO[3].intNum=0x000d0a4f;//funcion_para_saludo(0x4f0a0d00); /*O\lf\cr\0*/
	/* Imprimimos el saludo */
	for(i=0;i<4;i++){
      printf("%s",HOLA_MUNDO[i].charByte);
    }
    union my_int_MyInt unionAnIntNum;
    unionAnIntNum.intVar=HOLA_MUNDO[0];
    printf("El int correspondiente es %x\n",unionAnIntNum.intVar);
    printf("Imprimendo sus bytes uno por uno se obtiene:\n");
    /* Imprimimos los bytes de este int uno por uno */
    printf("%x\t%x\t%x\t%x\n",
            unionAnIntNum.MyInt.byte0,    /* byte menos significativo */
            unionAnIntNum.MyInt.byte1,
            unionAnIntNum.MyInt.byte2,
            unionAnIntNum.MyInt.byte3);   /* byte mas significativo*/
    /** El printf de arriba imprime :
        48    4f    4c    0
        mientras que el valor del int es 0x004c4f48. Ahora imprimimos 
        las direcciones de cada uno de los bytes.
    */
    printf("%x\t%x\t%x\t%x\n",&(unionAnIntNum.intVar.charByte[0])
                             ,&(unionAnIntNum.intVar.charByte[1])
                             ,&(unionAnIntNum.intVar.charByte[2])
                             ,&(unionAnIntNum.intVar.charByte[3]));
    printf("\n");
    printf("Byte\tAddress\n");
    printf("%x\t%x\n",unionAnIntNum.intVar.charByte[0],
                      &(unionAnIntNum.intVar.charByte[0]));
    printf("%x\t%x\n",unionAnIntNum.intVar.charByte[1],
                      &(unionAnIntNum.intVar.charByte[1]));
    printf("%x\t%x\n",unionAnIntNum.intVar.charByte[2],
                      &(unionAnIntNum.intVar.charByte[2]));
    printf("%x\t%x\n",unionAnIntNum.intVar.charByte[3],
                      &(unionAnIntNum.intVar.charByte[3]));
    /** Los 4 printf anteriores imprimieron:
        Byte    Address
        48      28ff1c
        4f      28ff1d
        4c      28ff1e
        0       28ff1f
        Es decir, el byte mas significativo se coloca en la direccion 
        mas alta, lo cual corresconde a la configuracion Little Endian.
     */
     /* Por otra parte, si queremos teclear los enteros a colocar en 
        la variable intNum de las uniones my_int como si el procesador 
        de la PC fuese un SPARC, podemos usar la funcion 
        funcion_para_saludo(int)
     */
	HOLA_MUNDO[0].intNum=funcion_para_saludo(0x484f4c00); /*HOL\0*/
	HOLA_MUNDO[1].intNum=funcion_para_saludo(0x41204d00); /*A M\0*/
	HOLA_MUNDO[2].intNum=funcion_para_saludo(0x554e4400); /*UND\0*/
	HOLA_MUNDO[3].intNum=funcion_para_saludo(0x4f0a0d00); /*O\lf\cr\0*/
	/* Imprimimos nuevamente el saludo */
	for(i=0;i<4;i++){ 
      printf("%s",HOLA_MUNDO[i].charByte);
    }	
	system("pause");
	return 0;
}//end main() 

int
funcion_para_saludo(int intA)
{
	int intBL=0x0000ffff&intA;	/* word baja */							// B0
	int intBH=0x0000ffff&(intA>>16);	/* word alta */					// A0
	int intWordL=funciondenteros(intBH);/*se esta pasando la word alta*/// C3
	int intWordH=funciondenteros(intBL);/*se esta pasando la word baja*/// C4
	return SWAP_AND_CAT_WORDS(intWordH,intWordL);
}

int funciondenteros(int intBL){
	int intByteL=0x000000ff&intBL;			// A1// B1
	int intByteH=0x000000ff&(intBL>>8);		// A2// B2
	return SWAP_AND_CAT_BYTES(intByteH,intByteL);
}
