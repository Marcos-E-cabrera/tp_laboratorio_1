#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"

/* Valor del vuelo de Aerolineas */
float valorAerolineas(){
	system("cls");
	float y; //Aerolineas
	char letra;
	do{
		printf(" | Ingrese Precio vuelo Aerolíneas : ");
		fflush(stdin);
		scanf("%f", &y);
		scanf("%c", &letra);

		if(isalpha(letra)){
			system("cls");
			printf(" | Error, solo numeros\n");
		}

		if(y < 1){
			system("cls");
			printf(" | Error, en el precio\n");
		}

	}while((isalpha(letra)) || (y < 1));
	return y;
}

/* Valor del vuelo de Aerolineas */
float valorLatam(){
	system("cls");
	float z; //Latam
	char letra;
	do{
		printf(" | Ingrese el valor de Latam : ");
		fflush(stdin);
		scanf("%f", &z);
		scanf("%c", &letra);

		if(isalpha(letra)){
			system("cls");
			printf(" | Error, solo numeros\n");
		}

		if(z < 1){
			system("cls");
			printf(" | Error, en el precio\n");
		}
	}while((isalpha(letra)) || (z < 1));
	return z;
}

