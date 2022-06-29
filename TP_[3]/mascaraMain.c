#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// PROPIAS
#include "mascaraMain.h"
// TP 3
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

// Menu
void menu_Passenger_Main()
{
	int option;
	char letra;

    int flagArchivo = 0; // Bandera para saber si abrimos un Archivo
    int flagGuardado = 0;
	LinkedList* listaPasajeros = ll_newLinkedList();
	controller_passengerId("PassengerId.bin", listaPasajeros);

	do{
		printf("\n  ______________________________________________________________________________________\n");
		printf(" |                                * MENU DE AEROLINEAS *                                |\n");
		printf(" |______________________________________________________________________________________|\n");
		printf(" | 1  | Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).       |\n");
		printf(" | 2  | Cargar los datos de los pasajeros desde el archivo datos.bin (modo binario).    |\n");
		printf(" | 3  |	Alta de pasajero                                                                |\n");
		printf(" | 4  | Modificar datos de pasajero                                                     |\n");
		printf(" | 5  | Baja de pasajero                                                                |\n");
		printf(" | 6  | Listar pasajeros                                                                |\n");
		printf(" | 7  | Ordenar pasajeros                                                               |\n");
		printf(" | 8  | Guardar los datos de los pasajeros en el archivo data.csv (modo texto).         |\n");
		printf(" | 9  | Guardar los datos de los pasajeros en el archivo datos.bin (modo binario).      |\n");
		printf(" | 10 | Salir                                                                           |\n");
		printf(" |--------------------------------------------------------------------------------------|\n");

		do{ /* Filtro de la opci�n elegida por el usuario */
			printf("  ___________________________________________");
			printf("\n | Por favor no ingrese letras, solo numeros |");
			printf("\n  __________________________");
			printf("\n | Introduzca una option: ");
			fflush(stdin);
			scanf("%d", &option);
			scanf("%c", &letra);
		} while ((isalpha(letra)) || (option < 1 || option >10));

		switch (option){
			case 1:
				if (flagArchivo == 0)
				{
					if(controller_loadFromText("data.csv", listaPasajeros))
					{
						flagArchivo = 1;
						printf("\n\n		>> CARGA DE PASAJEROS EXITOSA!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
					else
					{
						printf("\n\n		>> ERROR DE CARGA DE PASAJEROS!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
				}
				else
				{
					printf("\n\n		>> LOS PASAJEROS YA ESTAN CARGADOS!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;

			case 2:
				if (flagArchivo == 0)
				{
					if (controller_loadFromBinary("dato.bin", listaPasajeros))
					{
						flagArchivo = 1;
						printf("\n\n		>> CARGA DE PASAJEROS EXITOSA!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
					else
					{
						printf("\n\n		>> ERROR DE CARGA DE PASAJEROS!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
				}
				else
				{
					printf("\n\n		>> LOS PASAJEROS YA ESTAN CARGADOS!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 3:
				if(flagArchivo == 1)
				{
					if (controller_addPassenger(listaPasajeros))
					{
						printf("\n\n		>> ALTA DE PASAJERO EXITOSA!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
					else
					{
						printf("\n\n		>> CARGA CANCELADA POR USUARIO!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
				}
				else{
					printf("\n\n		>> NECESITAS LEER EL ARCHIVO PRIMERO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 4:
				if (controller_editPassenger(listaPasajeros))
				{
					printf("\n\n		>> EDIT DE PASAJERO EXITOSO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				else
				{
					printf("\n\n		>> EDIT CANCELADO POR USUARIO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;

			case 5:
				if (controller_removePassenger(listaPasajeros))
				{
					printf("\n\n		>> BAJA DE PASAJERO EXITOSA!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				else
				{
					printf("\n\n		>> ELIMINACION CANCELADA POR USUARIO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 6:
				if(controller_ListPassenger(listaPasajeros))
				{
					printf("\n\n		>> SE IMPRIMIO LA LISTA CON EXITO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				else
				{
					printf("\n\n		>> NO SE PUEDO IMPRIMIR!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 7:
				if (controller_sortPassenger(listaPasajeros))
				{
					printf("\n\n		>> PASAJERO ORDENADO EXITOSAMENTE!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				else
				{
					printf("\n\n		>> ERROR DE ORDENAMIENTO DE PASAJERO!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 8:
				if (flagArchivo == 1)
				{
					if (controller_saveAsText("data.csv", listaPasajeros))
					{
						flagArchivo = 0;
						flagGuardado = 1;
						printf("\n\n		>> PASAJERO GUARDADO EXITOSAMENTE!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
					else
					{
						printf("\n\n		>> ERROR DE GUARDADO DE PASAJERO!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
				}
				else
				{
					printf("\n\n		>> PRIMERO CARGAR PASAJEROS!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
				break;
			case 9:
				if (flagArchivo == 1)
				{
					if (controller_saveAsBinary("dato.bin", listaPasajeros))
					{
						flagArchivo = 0;
						flagGuardado = 1;
						printf("\n\n		>> PASAJERO GUARDADO EXITOSAMENTE!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
					else
					{
						printf("\n\n		>> ERROR DE GUARDADO DE PASAJERO!!!\n");
						printf(" ________________________________________________________________\n\n");
					}
				}
				else
				{
					printf("\n\n		>> PRIMERO CARGAR PASAJEROS!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
			break;
			case 10:
				if (flagGuardado != 1)
				{
					option = -1;
					printf("\n\n		>> GUARDE PARA SALIR!!!\n");
					printf(" ________________________________________________________________\n\n");
				}
			break;
			}
		}while((isalpha(letra)) || (option !=10) );
}
