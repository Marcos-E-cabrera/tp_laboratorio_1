#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "typePassenger.h"
#include "statusFlight.h"

/// 2.1
/**
* Para indicar que todas las posiciones del array están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todas posición del array
* \param list Pasajero* Puntero al array de pasajeros
* \param len int Longitud del array
* \return int Devuelve (-1) si Error [Longitud inválida o puntero NULL] - (0) si Ok.
*
*/
int initPassengers(ePassenger list[], int len) /// LISTO
{
    int todoOk = 0;
    if(list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

/// 2.2
/**
* añadir en una lista de pasajeros existente los valores recibidos como parámetros en la primera posición vacía
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL o sin espacio libre] - (0) si está bien
*/
int addPassenger(ePassenger list[], int len, char name[], char lastName[], float price, char flycode[], eTypePassenger sector[], int tamSector, eStatusFlight status[],int tamStatus, int* pId)
{
	int todoOk = 0;
	int indice;
	char auxName[51];
	char auxLastName[51];
	char auxflycode[51];
	ePassenger newPassenger;

	if(list != NULL && len > 0 && pId != NULL && name!=NULL && lastName!=NULL  && flycode!=NULL)
	{
		if( findPassengerByIdFree(list, len, &indice) )
		{
			if(indice == - 1)
			{
				printf(" | * No hay lugar en el sistema * |\n");
	        }
			else
			{
				printf(" |Ingrese el nombre del pasajero: ");
				fflush(stdin);
				gets(auxName);

				while(strlen(auxName) >= 50)
				{
					printf(" |Nombre demasiado largo. Reingrese nombre: ");
					fflush(stdin);
					gets(auxName);
				}

				strcpy(newPassenger.name, auxName);

				printf(" |Ingrese el apellido del pasajero: ");
				fflush(stdin);
				gets(auxLastName);

				while(strlen(auxLastName) >= 50)
				{
					printf(" |Apellido demasiado largo. Reingrese apellido: ");
					fflush(stdin);
					gets(auxLastName);
				}

				strcpy(newPassenger.lastName, auxLastName);

				printf(" |Ingrese precio: ");
				fflush(stdin);
				scanf("%f", &newPassenger.price);

				while( newPassenger.price <= 9000 || newPassenger.price >= 90000)
				{
					printf(" |Precio invalido. Reingrese precio: ");
					fflush(stdin);
					scanf("%f", &newPassenger.price);
				}

				printf(" |Ingrese el fly code: ");
				fflush(stdin);
				gets(auxflycode);

				while(strlen(auxflycode) >= 11)
				{
					printf(" |fly code demasiado largo. Reingrese fly code: ");
					fflush(stdin);
					gets(auxflycode);
				}

				strcpy(newPassenger.flycode, auxflycode);

				listarSectores(sector, tamSector);

				printf(" |Ingrese Type passenger: ");
				fflush(stdin);
				scanf("%d", &newPassenger.typePassenger);

				while( (newPassenger.typePassenger) < 1 || (newPassenger.typePassenger) > 4){
					printf("type passenger invalido. Reingrese type passenger: ");
					scanf("%d", &newPassenger.typePassenger);
				}

				listarstatus(status, tamStatus);

				printf(" |Ingrese Status Flight: ");
				fflush(stdin);
				scanf("%d", &newPassenger.statusFlight);

				while( (newPassenger.statusFlight) < 1 || (newPassenger.statusFlight) > 3){
					printf(" Status Flight invalido. Reingrese Status Flight: ");
					scanf("%d", &newPassenger.statusFlight);
				}

				newPassenger.isEmpty = 0;
				newPassenger.id = *pId;
				*pId = *pId + 1;
				list[indice] = newPassenger;
				todoOk = 1;
			}
		}
		else
		{
			printf(" | * Ocurrio un problema con los parametros * |\n");
		}
	}
	return todoOk;
}

/**
* Buscar un espacio vacio por Id y devuelve la posición del índice en el array.
* \param list Pasajero*
* \param len int
* \param id int
* \return Devuelve la posición del índice del pasajero o (1) si [Longitud inválida o puntero NULL recibido o pasajero no encontrado]
*/
int findPassengerByIdFree(ePassenger list[], int len, int *pIndex)
{
	int indice = 0;
    if(list != NULL && len > 0 && pIndex != NULL )
    {
    	*pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty ) // isEmpty == 1
            {
            	*pIndex = i;
                break;
            }
        }
        indice = 1;
    }
    return indice;
}

/// 2.3
/**
* Buscar un pasajero por Id y devuelve la posición del índice en el array.
* \param list Pasajero*
* \param len int
* \param id int
* \return Devuelve la posición del índice del pasajero o (-1) si [Longitud inválida o puntero NULL recibido o pasajero no encontrado]
*/
int findPassengerById(ePassenger list[], int len, int id, int* pIndex) /// 1 - error , 0 - ocupado
{
	int indice = 0;
    if(list != NULL && len > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 0 &&  list[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        indice = 1;
    }
    return indice;
}

/// 2.4
/**
* Eliminar un pasajero por Id (poner la bandera isEmpty en 1)
* \param list Pasajero*
* \param len int
* \param id int
* \return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o si no puede encontrar un pasajero] - (0) si Ok
*
*/
int removePassenger(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[])
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(list != NULL && len > 0)
    {
    	listarPasajeros(list, len, sector, status);
        printf(" |Ingrese ID: ");
        scanf("%d", &id);
        if( findPassengerById(list, len, id, &indice))
        {
            if(indice == -1)
            {
                printf(" |No hay un pasajero con id %d\n", id);
            }
            else
            {
            	printPassenger(list[indice], sector, status, len);
                printf(" |Confirma baja (s o n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf(" | * Baja cancelada por el usuario * |\n");
                }
                else
                {
                    list[indice].isEmpty = 1;
                    printf(" | * Baja realizada con el exito!!! *|\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf(" | * Ocurrio un problema al buscar pasajero *|\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/// 2.5
/**
* Ordenar los elementos del array de pasajeros, el orden de los argumentos indican el orden ARRIBA o ABAJO
* \param list Pasajero*
* \param len int
* \param order int [1] indica UP - [0] indica DOWN
* \return int Devuelve (-1) si hay error [longitud inválida o puntero NULL] - (0) si está bien
*
*/
int sortPassengers(ePassenger* list, int len,int order)
{
    int todoOk = 0;
    ePassenger auxPassenger;
    if(list != NULL && len > 0  && order >= 0 && order <= 1)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
            	if(	( (list[i].typePassenger == list[j].typePassenger) && (strcmp(list[i].lastName, list[j].lastName) > 0 && order) )
                	|| ( (list[i].typePassenger != list[j].typePassenger) && (list[i].typePassenger > list[j].typePassenger)  && order)
					|| ( (list[i].typePassenger == list[j].typePassenger) && (strcmp(list[i].lastName, list[j].lastName) < 0 && !order))
					|| ( (list[i].typePassenger != list[j].typePassenger) && (list[i].typePassenger < list[j].typePassenger)  && !order)
            	)
                {
                	auxPassenger = list[i];
                	list[i] = list[j];
                	list[j] = auxPassenger;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

/**
* Ordenar los elementos del array de pasajeros, el orden de los argumentos indican el orden ARRIBA o ABAJO
* \param list Pasajero*
* \param len int
* \param order int [1] indica UP - [0] indica DOWN
* \return int Devuelve (-1) si hay error [longitud inválida o puntero NULL] - (0) si está bien
*
*/
int sortPassengersByCode(ePassenger* list, int len, eStatusFlight* status, int order)
{
    int todoOk = 0;
    ePassenger auxPassenger;
    if(list != NULL && len > 0)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
            	if(!list[i].isEmpty && !list[j].isEmpty )
            	{
            		if( ( (strcmp(list[i].flycode, list[j].flycode) > 0 && order) ) || ((strcmp(list[i].flycode, list[j].flycode) < 0 && !order)))
            		{
            			auxPassenger = list[i];
            			list[i] = list[j];
            			list[j] = auxPassenger;
            		}
            	}
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarPasajerosByStatus(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[])
{
    int todoOk = 0;
    int flag = 0;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\n  _______________________________________________________________________________________________________\n");
        printf(" |                                          *** PASSENGER LIST  ***                                      |\n");
        printf(" |_______________________________________________________________________________________________________|\n");
        printf(" |  ID |       NAME        |     LAST NAME     |   PRICE  |  FLY CODE  | TYPE PASSENGER  | STATUS FLIGHT |\n");
        printf(" |-------------------------------------------------------------------------------------------------------|\n");
        for(int i=0; i < len; i++)
        {
            if( !list[i].isEmpty && list[i].statusFlight == 1)
            {
            	printPassenger(list[i], sector, status, len);
                flag++;
            }
        }
        printf(" |-------------------------------------------------------------------------------------------------------|");
        if(flag == 0)
        {
            printf(" | * No hay empleados en el sistema * |");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int listadoDeCuentas(ePassenger list[], int len, float* acumPrecio, int* cantPassengers, int* contMax,float* promedio)
{
	int todoOk =0;
	int cantPassengers2 = 0;
	float acumPrecio2 = 0;
	float promedio2;

	int contMax2=0;

	if(list!=NULL && len>0 && acumPrecio!=NULL && cantPassengers!=NULL && promedio!=NULL)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].price>0 && list[i].isEmpty==0)
			{
				cantPassengers2++;
				acumPrecio2 = list[i].price  + acumPrecio2;
			}
		}

		promedio2=(float)( acumPrecio2 / cantPassengers2 );
		for(int i=0; i<len;i++)
		{
			if(list[i].price > promedio2 && !list[i].isEmpty)
			{
				contMax2++;
			}
		}

		*cantPassengers = cantPassengers2;
		*acumPrecio= acumPrecio2;
		*contMax = contMax2;
		*promedio = promedio2;

		todoOk =0;
	}

	return todoOk;
}

int subMenuInformes(ePassenger list[], int len, eTypePassenger sector[],int tamSector, eStatusFlight status[], int tamStatus){
	int todoOK = 0;
	int opcion;
	int orden;
	char letra;
	int cantPassengers=0;
	int contMax = 0;
	float acumPrecio = 0;
	float promedio = 0;

	system("cls");
	printf("\n  __________________________\n");
	printf(" |     * MENU DE LISTA *    |\n");
	printf(" |__________________________|\n");
	printf(" | 1  | PASAJEROS           |\n");
	printf(" | 2  | TOTAL Y PROMEDIO    |\n");
	printf(" | 3  | CODIGO Y ESTADO     |\n");
	printf(" | 4  | SALIR               |\n");
	printf(" |--------------------------|\n");

	do{
		printf("  ___________________________________________");
		printf("\n | Por favor no ingrese letras, solo numeros |");
		printf("\n  __________________________");
		printf("\n | Introduzca una opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		scanf("%c", &letra);
	} while ((isalpha(letra)) || (opcion < 1 || opcion >4));


	switch(opcion){
	case 1:
		system("cls");
		printf("\n  ___________________________\n");
		printf(" | 1  | ASCENDENTE           |\n");
		printf(" | 0  | DECENDENTE           |\n");
		printf(" |---------------------------| \n");

		do{
			printf("  ___________________________________________");
			printf("\n | Por favor no ingrese letras, solo numeros |");
			printf("\n  __________________________");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &orden);
			scanf("%c", &letra);
		} while ((isalpha(letra)) || (orden < 0 || orden >1));

		sortPassengers(list, len, orden );
		listarPasajeros(list, len, sector, status);

		break;
	case 2:
		listarPasajeros(list, len, sector, status);
		listadoDeCuentas(list, len, &acumPrecio, &cantPassengers,&contMax, &promedio);

        printf("  ___________________________________________________\n");
        printf(" |               *** LISTA DE CUENTAS ***            |\n");
        printf(" |___________________________________________________|\n");
        printf(" |  TOTAL DE   |  PROMEDIO   | PASAJEROS QUE SUPERAN |\n");
        printf(" |   VUELOS    |             | EL PROMEDIO           |\n");
        printf(" |---------------------------------------------------|\n");
        printf(" | $%-10.2f | $%-10.2f |           %-d           |\n",acumPrecio, promedio, contMax);
        printf(" |---------------------------------------------------|\n");
		break;
	case 3:
		system("cls");
		printf("\n  ___________________________\n");
		printf(" | 1  | ASCENDENTE           |\n");
		printf(" | 0  | DECENDENTE           |\n");
		printf(" |---------------------------| \n");

		do{
			printf("  ___________________________________________");
			printf("\n | Por favor no ingrese letras, solo numeros |");
			printf("\n  __________________________");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &orden);
			scanf("%c", &letra);
		} while ((isalpha(letra)) || (orden < 0 || orden >1));

		sortPassengersByCode(list, len, status, orden );
		listarPasajerosByStatus(list, len, sector, status);
		break;
	}
	return todoOK;
}

/// 2.6
/**
* imprimir el contenido de la matriz de pasajeros
* \param list Pasajero*
* \param length int
* \return int
*
*/
int printPassenger(ePassenger l, eTypePassenger sector[], eStatusFlight status[], int len)
{
    int todoOk = 0;
    char descSector[20];
    char descStatus[20];

    if(sector != NULL && len > 0){
    	cargarDescripcionSector( sector, len, l.typePassenger, descSector);
    	cargarDescripcionStatus( status, len, l.typePassenger, descStatus);
        printf(" | %-3d | %-17s | %-17s | %-8.2f | %-10s | %-15s | %-12s  |\n",
        	l.id,
			l.name,
			l.lastName,
			l.price,
			l.flycode,
			descSector,
			descStatus
          );
        todoOk = 1;
    }
    return todoOk;
}

int listarPasajeros(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[])
{
    int todoOk = 0;
    int flag = 0;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\n  _______________________________________________________________________________________________________\n");
        printf(" |                                          *** PASSENGER LIST  ***                                      |\n");
        printf(" |_______________________________________________________________________________________________________|\n");
        printf(" |  ID |       NAME        |     LAST NAME     |   PRICE  |  FLY CODE  | TYPE PASSENGER  | STATUS FLIGHT |\n");
        printf(" |-------------------------------------------------------------------------------------------------------|\n");
        for(int i=0; i < len; i++)
        {
            if( !list[i].isEmpty )
            {
            	printPassenger(list[i], sector, status, len);
                flag++;
            }
        }
        printf(" |-------------------------------------------------------------------------------------------------------|");
        if(flag == 0)
        {
            printf(" | * No hay empleados en el sistema * |");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

///2.7
int modifyPassenger(ePassenger list[], int len, eTypePassenger sectores[], eStatusFlight status[], int tamSector, int tamStatus)
{
	int todoOk = 0;
	int indice;
	int id;
	char salir = 'n';
	char auxName[51];
	char auxLastName[51];
	char auxflycode[51];
	if(list != NULL && len > 0)
	{
		listarPasajeros(list, len, sectores, status);
		printf("Ingrese id: ");
		scanf("%d", &id);
		if( findPassengerById(list, len, id, &indice))
		{
			if(indice == -1)
			{
				printf(" |No hay un pasajero con id %d\n", id);
			}
			else
			{
				printPassenger(list[indice], sectores, status, len);
				do
				{
					system("pause");
					switch(menuModifyPassenger()){
					case 1:
						printf(" |Ingrese el nombre del pasajero: ");
						fflush(stdin);
						gets(auxName);
						while(strlen(auxName) >= 50)
						{
							printf(" |Nombre demasiado largo. Reingrese nombre: ");
							fflush(stdin);
							gets(auxName);
						}
						strcpy(list[indice].name, auxName);
						printf(" | * Se ha modificado el nombre * |\n");
						break;
					case 2:
						printf(" |Ingrese el apellido del pasajero: ");
						fflush(stdin);
						gets(auxLastName);

						while(strlen(auxLastName) >= 50)
						{
							printf(" |apellido demasiado largo. Reingrese apellido: ");
							fflush(stdin);
							gets(auxLastName);
						}

						strcpy(list[indice].lastName, auxLastName);
						printf(" | * Se ha modificado el Apellido  * |\n");
						break;

					case 3:
						printf(" |Ingrese nuevo precio: ");
						fflush(stdin);
						scanf("%f", &list[indice].price);

						while( list[indice].price <= 9000 || list[indice].price >= 90000)
						{
							printf(" |Precio invalido. Reingrese precio: ");
							fflush(stdin);
							scanf("%f", &list[indice].price);
						}

						printf(" | * Se ha modificado el precio * |\n");
						break;
					case 4:
						printf(" |Ingrese el fly code: ");
						fflush(stdin);
						gets(auxflycode);

						while(strlen(auxflycode) >= 11)
						{
							printf(" |fly code demasiado largo. Reingrese fly code: ");
							fflush(stdin);
							gets(auxflycode);
						}

						strcpy(list[indice].flycode, auxflycode);
						printf(" | * Se ha modificado el codigo de vuelo * |\n");
						break;
					case 5:
						listarSectores(sectores, tamSector);
						printf(" |Ingrese Type passenger: ");
						fflush(stdin);
						scanf("%d", &list[indice].typePassenger);

						while( (list[indice].typePassenger) < 1 || (list[indice].typePassenger) > 4){
							printf(" |type passenger invalido. Reingrese type passenger: ");
							scanf("%d", &list[indice].typePassenger);
						}
						printf(" | * Se ha modificado el tipo de pasajero * |\n");
						break;
					case 6:
						listarstatus(status, tamStatus);
						printf(" |Ingrese Status Flight: ");
						fflush(stdin);
						scanf("%d", &list[indice].statusFlight);

						while( (list[indice].statusFlight) < 1 || (list[indice].statusFlight) > 3){
							printf(" |Status Flight invalido. Reingrese Status Flight: ");
							scanf("%d", &list[indice].statusFlight);
						}

						printf(" | * Se ha modificado el status * |\n");
						break;

					case 7:
						salir = 's';
						break;
					}
				}
				while(salir != 's');
			}
		}
		else
		{
			printf(" | * Ocurrio un problema al buscar empleado * |\n");
		}
		todoOk = 1;
	    }
	return todoOk;
}

int menuModifyPassenger()
{
    int opcion;
    char letra;

    system("cls");
	printf("\n  __________________________\n");
	printf(" |  * CAMPOS A MODIFICAR *  |\n");
	printf(" |__________________________|\n");
	printf(" | 1  | NAME                |\n");
	printf(" | 2  | LAST NAME           |\n");
	printf(" | 3  | PRICE               |\n");
	printf(" | 4  | FLY CODE            |\n");
	printf(" | 5  | TYPE PASSENGER      |\n");
	printf(" | 6  | STATUS FLIGHT       |\n");
	printf(" | 7  | Salir               |\n");
	printf(" |--------------------------|\n");

	do{
		printf("  ___________________________________________");
		printf("\n | Por favor no ingrese letras, solo numeros |");
		printf("\n  __________________________");
		printf("\n | Introduzca una opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
		scanf("%c", &letra);
	} while ((isalpha(letra))||(opcion < 1 || opcion >7));
    return opcion;
}

/// 2-8
int hardcodearPasajeros(ePassenger list[], int len, int cant, int* id)
{
    int todoOk = 0;
    ePassenger passenger[]=
    {
    	{0, "Juan Lorenzo", "Dellapa", 18230, "BHI9176",4,3,0},
		{0, "Valentina Aicha", "Navarrete", 11789, "AEP7377",2,1,0},
		{0, "Marcos Elias", "Cabrera", 85176, "AC2324",1,1,0},
		{0, "Mauro Ezequiel", "Palazzo", 85180, "AC2124",1,1,0},
		{0, "Roser", "Santos", 40523, "MDQ1980",3,1,0},
		{0, "Matilde Ester", "Campo", 66920, "MDQ8281",2,1,0},
		{0, "Clotilde Maria", "Morales", 90000, "EZE6482",1,2,0},
		{0, "Juan Francisco", "Bilbao", 50238, "CTC4683",3,1,0},
		{0, "Marta Rene", "Morales", 90000, "EZE6482",2,2,0},
		{0, "Mike Francisco", "Bilbao", 50238, "CTC4683",4,3,0},
    };

    if(list != NULL && len > 0 && id != NULL && cant > 0 && cant <= len)
    {
        for(int i=0; i < cant; i++)
        {
        	list[i] = passenger[i];
        	list[i].id = *id;
            *id = *id +1;
        }
        todoOk = 1;
    }
    return todoOk;
}
