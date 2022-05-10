/*
 ============================================================================
 Name        : tp_[1]
 Author      : marcos cabrera - 1 A
 Version     : 1.5
 Copyright   : Your copyright notice
 Description : Trabajo práctico #2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "typePassenger.h"
#include "statusFlight.h"

#define ELEMENTS 5 /// TAM
#define TAM_SEC 4 /// TAMS
#define TAM_STS 3

int main(void){
	setbuf(stdout, NULL);
	int opcion;

	setbuf(stdout, NULL);
	char letra;
	int flagOne = 0;
	int flagTwo = 0;
	int flagthree = 0;
	int flagFour = 0;

	int proximoId = 770;

	ePassenger lista[ELEMENTS];
	ePassenger passenger;

	eStatusFlight status[TAM_STS] ={
		{1, "ACTIVO"},
		{2, "DEMORADO"},
		{3, "CANCELADO"},
	};

	eTypePassenger sectores[TAM_SEC] ={
		{1, "Primera clase"},
		{2, "Ejecutiva"},
		{3, "Premium economy"},
		{4, "Económica"},
	};


	initPassengers(lista, ELEMENTS);

	//hardcodearPasajeros(lista, ELEMENTS, 5, &proximoId);

	do{
		system("cls");
		printf("\n | * MENU DE AEROLINEAS  *   |\n");
		printf(" |  1) Alta                  |\n");
		printf(" |  2) Modificar              |\n");
		printf(" |  3) Baja                  |\n");
		printf(" |  4) Informar              |\n");
		printf(" |  5) Salir                 |\n");

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
    		if(addPassenger(lista, ELEMENTS, passenger.name, passenger.lastName, passenger.price,  passenger.flycode, sectores, TAM_SEC, status,TAM_STS, &proximoId)){
    			flagOne = 1;
    			printf("Pasajero agregado con exito\n");
    		}else{
    			printf("	Problema al hacer el alta de Pasajero\n");
    		}
		break;
		case 2:
			if( (flagOne == 1 && flagTwo == 0)){
//	            if( modificarEmpleado(lista, ELEMENTS, sectores, TAM_SECTORES) == 0)
//	            {
//	            	flagTwo = 1;
//	                printf("Problema al hacer la modificacion de empleado\n");
//	            }
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
				printf(" | Introduzca alta empleado, Para poder modificar\n");
			}
		break;
		case 3:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 0){
//	    		if( removePassenger(lista, ELEMENTS, sectores, TAM_SECTORES) == 0)
//	    		{
//	    			flagthree = 1;
//	    			printf("Problema al hacer la baja de empleado\n");
//	    		}
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 4:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 0 && flagFour == 0){
//				if( removePassenger(lista, ELEMENTS, sectores, TAM_SECTORES) == 0){
//					flagFour = 1;
//				}
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 5:
			listarPasajeros(lista, ELEMENTS, sectores, status);
		break;
		}
		system("pause");
	}while((isalpha(letra)) || (opcion !=6) );
	return EXIT_SUCCESS;
}

