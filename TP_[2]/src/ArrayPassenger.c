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
		if( findPassengerById(list, len, &indice) )
		{
			if(indice == - 1)
			{
				printf("No hay lugar en el sistema\n");
	        }
			else
			{
				printf("|Ingrese el nombre del pasajero: ");
				fflush(stdin);
				gets(auxName);

				while(strlen(auxName) >= 50)
	                {
					printf("|Nombre demasiado largo. Reingrese nombre: ");
					fflush(stdin);
					gets(auxName);
	                }

	                strcpy(newPassenger.name, auxName);

	                printf("|Ingrese el apellido del pasajero: ");
	                fflush(stdin);
	                gets(auxLastName);

	                while(strlen(auxLastName) >= 50)
	                {
	                	printf("|apellido demasiado largo. Reingrese apellido: ");
	                	fflush(stdin);
	                	gets(auxLastName);
	                }

	                strcpy(newPassenger.lastName, auxLastName);

	                printf("|Ingrese precio: ");
	                fflush(stdin);
	                scanf("%f", &newPassenger.price);

	                while( newPassenger.price <= 9000 || newPassenger.price >= 90000)
	                {
	                	printf("|Precio invalido. Reingrese precio: ");
	                	fflush(stdin);
	                	scanf("%f", &newPassenger.price);
	                }

	                printf("|Ingrese el fly code: ");
	                fflush(stdin);
	                gets(auxflycode);

	                while(strlen(auxflycode) >= 11)
	                {
	                	printf("|fly code demasiado largo. Reingrese fly code: ");
	                	fflush(stdin);
	                	gets(auxflycode);
	                }

	                strcpy(newPassenger.flycode, auxflycode);

	                listarSectores(sector, tamSector);

	                printf("|Ingrese Type passenger: ");
	                fflush(stdin);
	                scanf("%d", &newPassenger.typePassenger);

	                while( (newPassenger.typePassenger) < 1 || (newPassenger.typePassenger) > 4){
	                	printf("type passenger invalido. Reingrese type passenger: ");
	                	scanf("%d", &newPassenger.typePassenger);
	                }

	                listarstatus(status, tamStatus);

	                printf("|Ingrese Status Flight: ");
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
	            printf("Ocurrio un problema con los parametros\n");
	        }
	    }
	    return todoOk;
	}

/// 2.3
/**
* Buscar un pasajero por Id y devuelve la posición del índice en el array.
* \param list Pasajero*
* \param len int
* \param id int
* \return Devuelve la posición del índice del pasajero o (-1) si [Longitud inválida o puntero NULL recibido o pasajero no encontrado]
*/
int findPassengerById(ePassenger list[], int len, int *id) /// -1 - error , 0 - ocupado
{
	int indice = 0;
    if(list != NULL && len > 0 && id != NULL )
    {
    	*id = -1;
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty ) // isEmpty == 1
            {
            	*id = i;
                break;
            }
        }
        indice = 1;
    }
    return indice;
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
        printf("   %3d  %20s  %20s      %9.2f       %10s       %20s        %20s\n",
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
        printf("                                             *** Passenger List ***\n\n");
        printf("    Id     |         Name         |     Last Name     |     Price     |     Fly code     |     Type Passenger     |     Status Flight\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < len; i++)
        {
            if( !list[i].isEmpty )
            {
            	printPassenger(list[i], sector, status, len);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay empleados en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


/**
* Eliminar un pasajero por Id (poner la bandera isEmpty en 1)
* \param list Pasajero*
* \param len int
* \param id int
* \return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o si no puede encontrar un pasajero] - (0) si Ok
*
*/
//int removePassenger(ePassenger list[], int len, int id)
//{
//	int todoOk = 0;
//	return todoOk;
//}

/**
* Ordenar los elementos del array de pasajeros, el orden de los argumentos indican el orden ARRIBA o ABAJO
* \param list Pasajero*
* \param len int
* \param order int [1] indica UP - [0] indica DOWN
* \return int Devuelve (-1) si hay error [longitud inválida o puntero NULL] - (0) si está bien
*
*/
//int sortPassengers(ePassenger list[], int len, int order)
//{
//	int todoOk = 0;
//	return todoOk;
//}


/**
* Ordenar los elementos del array de pasajeros, el orden de los argumentos indican el orden ARRIBA o ABAJO
* \param list Pasajero*
* \param len int
* \param order int [1] indica UP - [0] indica DOWN.
*/
//int sortPassengers(ePassenger list[], int len, int order)
//{
//	int todoOk = 0;
//	return todoOk;
//}


