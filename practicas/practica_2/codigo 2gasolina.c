#include <stdio.h>
int main(){
    float capacidad_tanque, litros, porcentaje;
    scanf("%f",&capacidad_tanque);
    scanf("%f",&litros);
    porcentaje = litros*100 /capacidad_tanque;
    if (porcentaje < 30){              //La primera condici�n es si es menor a 30
       printf("VAC�O");                 //En caso verdadero imprime "VAC�O"
    } else {                                                  //En caso falso 
    	if (porcentaje > 80){  //pregunta si es mayor a 80
    	printf("LLENO");   //En caso verdadero imprime "LLENO"
        } else {
    	printf("MEDIO");  //En caso falso imprime "MEDIO"
        }
    }
    getch();
}

