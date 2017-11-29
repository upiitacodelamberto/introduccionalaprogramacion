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
  struct part part0,part1;
  part0.intVotos=part0.intIndex=0;
  int var;
//  char (*charArrayPt)[128];
//  charArrayPt=malloc(sizeof(linea0));
//  charArrayPt[0]=linea1;charArrayPt[1]=linea2;
  int intSumDVotos=0;
  var=contar_votos(4,linea0,linea1,&part0);
  intSumDVotos+=part0.intVotos;
  var=contar_votos(4,linea0,linea2,&part1);
  intSumDVotos+=part1.intVotos;
  printf("\nTotal de votos:%d\n",intSumDVotos);
  if(var==-1)
  {
    printf("\nExiste un error en el llamado a funcion :'v");
  }else{
    
  }
  
  
  system("PAUSE");	
  return 0;
}//end main()

int 
contar_votos(int intIndexPartido,char lineaH[128],
char linea[],struct part *partPt)
{
     int i=0,cantDComas=0, intQ=0,j;
     char *charVotos,*charNomDPart; 
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
    
//     printf("cantDComas=%d\n, i=%d, %s\n",cantDComas,i, linea);
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
//	 printf("Partido %s %s %d",charVotos,partPt->intVotos);
	 }
     else {
     	while(linea[i+intQ+1]!=','&&(i+intQ)<128){
     		intQ++;
        }
//		 printf("\nintQ=%d\n",intQ);
		charVotos=malloc(intQ*sizeof(char)+1);
		i++;
		for(j=0;j<intQ;j++){
			charVotos[j]=linea[(i)+j];
		}
		charVotos[intQ]=0; 
		partPt->intVotos=atoi(charVotos);
          i=intQ=cantDComas=0;
          do{
            if(lineaH[i]==','){
              cantDComas++;
            }
            if(cantDComas==intIndexPartido){
              break;
            }
            i++;
          }while(i<128);
          if (cantDComas==0){
     	    while(lineaH[i+intQ]!=','&&(i+intQ)<128){
     		intQ++;
	    }
            charNomDPart=malloc(intQ*sizeof(char)+1);
     	    for(j=0;j<intQ;j++){
     			charNomDPart[j]=lineaH[i+j];
	    }
	    charNomDPart[intQ]=0; 
		/*partPt->intVotos=atoi(charVotos);*/
          }else{
     	     while(lineaH[i+intQ+1]!=','&&(i+intQ)<128){
     		intQ++;
             }
       // printf("\nintQ=%d\n",intQ);
             charNomDPart=malloc(intQ*sizeof(char)+1);
             i++;
             for(j=0;j<intQ;j++){
               charNomDPart[j]=lineaH[(i)+j];
             }
             charNomDPart[intQ]=0; 
          }
          
     }/*-----------end  else{}*/
	 printf("\nPartido |%s|  |%s| |%d|\n",charNomDPart,charVotos,partPt->intVotos);
	 return 0;
 }else{
 	return -1;
 }
}












