#include <stdio.h>
#include <stdlib.h>
char partido[9][32]={
  {"pan"},{"pri"},{"prd"},{"verde"},{"pt"},
  {"panal"},{"mc"},{"morena"},{"encuentro social"}
};

struct coal{
  char coal_name[128];
  int *intPt;         /*apunta a los indices de los partidos en el arreglo partido*/
  int intVotos;
};
struct part{
  int intIndex;
  int intVotos;
};
int 
contar_votos(int intIndexPartido,char lineaH[128],
char linea[],struct part *partPt);

int main(int argc, char *argv[])
{
  char linea0[128]="pan,pri,prd,verde,pt,panal,mc,morena,encuentro social,nulo";
  char linea1[128]="500,300,150,10,    2,  200, 1,   250,100,253";
  char linea2[128]="500,300,150,10,    2,  200, 1,   250,100,200";
  struct part part0;
  part0.intVotos=part0.intIndex=0;
  int var;
  var=contar_votos(9,linea0,linea1,&part0);
  if(var==-1)
  {printf("\nExiste un error en el llamado a funcion :'v");
  }
  
  system("PAUSE");	
  return 0;
}//end main()

int 
contar_votos(int intIndexPartido,char lineaH[128],
char linea[],struct part *partPt)
{
     int i=0,cantDComas=0, intQ=0,j;
     char *charVotos; 
	 do{
       if(linea[i]==','){
         cantDComas++;
       }
       if(cantDComas==intIndexPartido){
         break;
       }
       i++;
     }while(i<128);
     if((intIndexPartido<=cantDComas+1) && (intIndexPartido>=0))
	{
    
     printf("cantDComas=%d\n, i=%d, %s\n",cantDComas,i, linea);
     if (cantDComas==0){
     	while(linea[i+intQ]!=','&&(i+intQ)<128){
     		intQ++;
		 }
		charVotos=malloc(intQ*sizeof(char)+1);
		for(j=0;j<intQ;j++){
			charVotos[j]=linea[i+j];
		}
		charVotos[intQ]=0; 
		partPt->intVotos=atoi(charVotos);
	 printf(" %s %d",charVotos,partPt->intVotos);
	 }
     else {
     	while(linea[i+intQ+1]!=','&&(i+intQ)<128){
     		intQ++;
		 }
		 printf("\nintQ=%d\n",intQ);
		charVotos=malloc(intQ*sizeof(char)+1);
		i++;
		for(j=0;j<intQ;j++){
			charVotos[j]=linea[(i)+j];
		}
		charVotos[intQ]=0; 
		partPt->intVotos=atoi(charVotos);
	 printf("\n %s %d\n",charVotos,partPt->intVotos);
	 }
	 return 0;
 }else{
 	return -1;
 }
}












