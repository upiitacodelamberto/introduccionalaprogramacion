/** file.c
 */
 #include <stdio.h> /* printf() */
 extern int cuenta;
 
 void despedida(){
 	static int intDespedida=0;
 	printf("intDespedida=%d\n",++intDespedida);
 	cuenta++;
 	printf("ADIOS MUNDO C!");
 }
