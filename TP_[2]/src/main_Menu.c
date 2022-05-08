#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main_Menu.h"
#include "ArrayPassenger.h"

#define TAM 10
#define TAMS 4

int main_Menu (int opcion){
	char letra;
	int flagOne = 0;
	int flagTwo = 0;
	int flagthree = 0;
	int flagFour = 0;

	int proximoId = 770;

	ePassenger lista[TAM];

	eTypePassenger sectores[TAMS] ={
		{1, "Primera clase"},
		{2, "Ejecutiva"},
		{3, "Premium economy"},
		{4, "Económica"},
	};

	inicializarPasajeros(lista, TAM);
	hardcodearPasajeros(lista, TAM, 5, &proximoId);

	do{
		system("cls");
		printf("\n          ****  MENU DE AEROLINEAS  ****\n");
		printf(" ----------------------------------------------\n");
		printf(" | 1) Alta\n");
		printf(" | 2) Modificar\n");
		printf(" | 3) Baja\n");
		printf(" | 4) Informar\n");
		printf(" | 5) Salir\n");

		do{ /* Filtro de la opción elegida por el usuario */
			printf("\n | Por favor no ingrese letras, solo numeros");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
			scanf("%c", &letra);
		} while ((isalpha(letra))||(opcion < 1 || opcion >5));

		system("cls");

		switch ( opcion ){
		case 1:
    		if(addPassengers(lista, TAM, sectores, TAMS, &proximoId)){
    			flagOne = 1;
    			printf("Empleado agregado con exito\n");
    		}else{
    			printf("Problema al hacer el alta de empleado\n");
    		}
		break;
		case 2:
			if( (flagOne == 1 && flagTwo == 0)){
				flagTwo = 1;
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 3:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 0){
	    		if( removePassenger(lista, TAM, sectores, TAMS) == 0)
	    		{
	    			flagthree = 1;
	    			printf("Problema al hacer la baja de empleado\n");
	    		}
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 4:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 0 && flagFour == 0){
				if( removePassenger(lista, TAM, sectores, TAMS) == 0){
					flagFour = 1;
				}
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 5:
			listarPasajeros(lista, TAM, sectores, TAMS);
		break;
		}
		system("pause");
	}while((isalpha(letra)) || (opcion !=6) );
	return opcion;
}
