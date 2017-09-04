#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

main()

{
	int ix,e=-1,stop=0,z,x,cceb,n,n2=0;
	int nn2[50];
	float fx,fr;
	int ceb[32];
	int intx=31;
	int ieee754[32];
		int abcd=0;
	
	for(intx;intx>=0;intx--)
	{
		ceb[intx]=0;
	}
	
	intx=31;
	for(intx;intx>=0;intx--)
	{
		ieee754[intx]=0;
	}

	nn2[0]=0;
	printf("Ingrese un numero para convertir \n" );
	scanf("%f",&fx);
	if(fx>=0) ieee754[31]=0;
	if(fx<0) 
	{
		ieee754[31]=1;
		fx=-fx;
	    abcd=1;
	}
	n=fx;
	ix=fx;
	fr=fx-ix;
	cceb=0;
	printf("\n");
	printf("el numero en binario es: \n");
	if(abcd==1){
                printf("-");
         
    }     
	
	for (x=0;x<49;x++)
	{
		nn2[x]=n%2;
		n=n/2;
		if(n==0)
		break;
	}
	
	for(z=x;z>=0;z--)
	{
		printf("%d",nn2[z]);
		ceb[31-cceb]=nn2[z];
		cceb=cceb+1;
		e=e+1;
	}
	
	printf(".");
	
	while(stop==0)
	{	
		if((fr*2<1)&(fr>0)) 
		{
			printf("0");
			fr=fr*2;
			ceb[31-cceb]=0;
		    cceb=cceb+1;
		};
		if(fr*2>=1) 
		{
			fr=(fr*2)-1;
			printf("1");
			ceb[31-cceb]=1;
		    cceb=cceb+1;
		};
		if(fr<=0) 
		{
			stop=1;
		};
		
	}
	
	printf("\n \n");
	printf("el numero pasado a la norma IEEE754 es: ");
	
	e=127+e;
	int abc=0;
	
	for (x=0;x<49;x++)
	{
		nn2[x]=e%2;
		e=e/2;
		if(e==0)
		break;
	}
	for(z=x;z>=0;z--)
	{
		ieee754[30-abc]=nn2[z];
		abc=abc+1;
	}
	
	abc=31;
	intx=22;
	for(intx;intx>=0;intx--)
	{
		ieee754[intx]=ceb[abc];
		abc=abc-1;
	}
	
	printf("\n\n");
	intx=31;
	
	for(intx;intx>=0;intx--)
	{
		printf("%d",ieee754[intx]);
	}
	printf("\n\n");
	
	system("PAUSE");
}

