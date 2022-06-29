#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#include "ArrayPassenger.h"
#include "typePassenger.h"
#include "statusFlight.h"

#define ELEMENTS 2000
#define TAM_SEC 4
#define TAM_STS 3

int mainMenu (){
	int opcion;
	char letra;
	char salir;
	int flag = 0;
	int proximoId = 1;

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
		{4, "Economica"},
	};

	initPassengers(lista, ELEMENTS);

	do{
		system("cls");
		printf("\n  _______________________________\n");
		printf(" |     * MENU DE AEROLINEAS *    |\n");
		printf(" |_______________________________|\n");
		printf(" | 1  | ALTA AEROLINEA           |\n");
		printf(" | 2  | MODIFICAR AEROLINEA      |\n");
		printf(" | 3  | BAJA AEROLINEA           |\n");
		printf(" | 4  | INFORMAR LISTA :         |\n");
		printf(" | 5  | ALTA FORZADA             |\n");
		printf(" | 6  | SALIR                    |\n");
		printf(" |-------------------------------|\n");

		do{ /* Filtro de la opci�n elegida por el usuario */
			printf("  ___________________________________________");
			printf("\n | Por favor no ingrese letras, solo numeros |");
			printf("\n  __________________________");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
			scanf("%c", &letra);

		} while ((isalpha(letra)) || (opcion < 1 || opcion > 6));

		system("cls");

		switch ( opcion ){
		case 1:
    		if(addPassenger(lista, ELEMENTS, passenger.name, passenger.lastName, passenger.price,  passenger.flycode, sectores, TAM_SEC, status,TAM_STS, &proximoId) != -1){
    			flag = 1;
    			printf(" | * Pasajero agregado con exito * |\n");
    			system("pause");
    		}else{
    			printf(" | * Problema al hacer el alta de Pasajero * |\n");
    		}
		break;
		case 2:
			if( flag == 1){
	            if( modifyPassenger(lista, ELEMENTS, sectores, status, TAM_SEC, TAM_STS) != -1 )
	            {
	    			printf(" | * Pasajero modificado con exito * |\n");
	    			system("pause");
	    		}else{
	    			printf(" | * Problema al modificar Pasajero * |\n");
	            }
			}else{
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 3:
			if (flag == 1){
	    		if(removePassenger(lista, ELEMENTS, sectores, status) != -1 )
	    		{
	    			printf(" | * Pasajero eliminado con exito * |\n");
	    			system("pause");
	    		}else{
	    			printf(" | * Problema al hacer la baja de pasajero * |\n");
	    		}
			}else{
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 4:
			if (flag == 1 )
			{
				subMenuInformes(lista, ELEMENTS, sectores, TAM_SEC, status, TAM_STS);
				system("pause");
			}else{;
				printf(" | Error, Introduzca una opcion valida\n");
			}
		break;
		case 5:
			hardcodearPasajeros(lista, ELEMENTS, 6, &proximoId);
			listarPasajeros(lista, ELEMENTS, sectores, status);
			flag =1;
			system("pause");
		break;
		case 6:
			salir = 's';
		break;
		}
	}while((isalpha(letra)) || (salir!='s'));
	return EXIT_SUCCESS;
}
