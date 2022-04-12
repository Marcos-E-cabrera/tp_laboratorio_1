#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"

/* Kilometros del vuelo ingresado */
float kilometrosDeVuelo(){
	system("cls");
	int kilometros; // kms
	char letra;
	do
	{
		printf(" | Ingrese los kilometros del vuelo : ");
		fflush(stdin);
		scanf("%d", &kilometros);
		scanf("%c", &letra);

		if( isalpha(letra) ){
			system("cls");
			printf(" | Error, Reingrese los kilometros del vuelo\n");
		}

		if(kilometros < 1){
			system("cls");
			printf(" | Error, Reingrese los kilometros del vuelo\n");
		}
	}while(	(isalpha(letra)) || (kilometros < 1 ));
    return kilometros;
}

/* Descuento */
float descuento(float importe){
	float porcentaje;
	float descuento;
	descuento = importe * 0.1;
	porcentaje = importe - descuento;
	return porcentaje;
}

/* Credito */
float credito(float importe){
	float porcentaje;
	float interes;
	interes = importe* 0.25;
	porcentaje = importe - interes;
	return porcentaje;
}

/* Bitcoin */
float bitcoin(float importe){
	float equivalente;
	equivalente = (importe * 1) / 4606954.55;
	return equivalente;
}

/* Precio Unitario */
float precioUnitario(float importe, float kms){
	return (importe/kms);
}

/* Diferencia de precio */
float difPrecio(float y , float z){
	if (y <= 0){
		return printf("$0");
	}else if(z <= 0){
		return printf("$0");
	}
	if(y > z){
		return y-z;
	}else{
		return z-y;
	}
}
