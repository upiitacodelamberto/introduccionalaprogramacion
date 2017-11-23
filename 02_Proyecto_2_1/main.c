#include <stdio.h>
#include <stdlib.h>
void show_bits(int intTmp);

int main(int argc, char *argv[])
{
  int intVar=8,i,k,tmp;
  float floatVar=0.015625;
  /*    intVar=*(int *)(void *)&floatVar; 
	printf("sizeof(float)=%d\n",sizeof(float));    
	printf("%d representado en 8*%d=%d bits:\n",
			intVar,sizeof(intVar),8*sizeof(int));   
	/*intVar=float_to_int(floatVar);*/
	intVar=*((int*)(&floatVar));
	printf("%f\t",floatVar);
	for(i=8*sizeof(int)-1;i>=0;i--){
		printf("%d",(intVar>>i)&0x00000001);
	}
	printf("\n");
	for(i=0;i<10;i++){
//      printf("%d\n",i);
      tmp=i;
      floatVar=*((float*)(&tmp));
      printf("%d\t%f\t",i,floatVar);
      intVar=*((int*)(&floatVar));
      printf("%d\t",intVar);
      for(k=8*sizeof(int)-1;k>=0;k--){
		printf("%d",(intVar>>k)&0x00000001);
	  }
	  printf("\n");
    }
  system("PAUSE");	
  return 0;
}//end main()

void show_bits(int intTmp){
  int i;
  for(i=8*sizeof(int)-1;i>=0;i--){        //A1:
    printf("%d",((intTmp)>>i)&0x00000001);//A2:
  }                                       //A3:
}












