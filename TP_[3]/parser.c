#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include "parser.h"

int parser_passengerId(FILE* pFile, LinkedList* list)
{
	int todoOk = 0;
    int newId;
	if (pFile != NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile, "%d\n", &newId);//LEO LA ID
			buscarMayorId(list, &newId);
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarMayorId(LinkedList* list, int*id)
{
	int todoOk =0;
	int maxId;
	Passenger* auxPassenger =NULL;

	if( list !=NULL){
		for(int i=0; i < ll_len(list); i++)
		{
			auxPassenger=(Passenger*) ll_get(list, i);
			if( i==0 || auxPassenger->id > maxId)
			{
				maxId = auxPassenger->id;
			}
		}
		*id = maxId+= 1;
		todoOk =1;
	}
	return todoOk;
}

/* \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return todoOk - 1 ok y 0 Error
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
    int aux;

	int id;
	int ultimoId;

	int cantidadPasajeros =0;
	char auxId[4];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[20];
	char auxCodigoVuelo[8];
	char auxTipoPasajero[20];
	char auxEstadoVuelo[20];

	Passenger* auxPassenger = NULL;
	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			aux = fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
			if( aux == 7)
			{
				auxPassenger = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero,auxEstadoVuelo);
			}
			if(auxPassenger != NULL && !(ll_add(pArrayListPassenger, auxPassenger)))
			{
				Passenger_getId(auxPassenger, &id);
				if (cantidadPasajeros == 0 || (id > ultimoId && ll_len(pArrayListPassenger) < 2000))
				{
					Passenger_getId(auxPassenger, &ultimoId);
				}
				cantidadPasajeros++;
			}
		}
		printf(" |> Se ingresaron: %d pasajeros\n"
			   " |> ultimo ID: %d\n", cantidadPasajeros, ultimoId);
		todoOk = 1;
	}
	return todoOk;
}

/* \brief Parsea los datos los datos de los pasajeros desde el archivo doto.bin (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
* \return todoOk - 0 ok y 1 Error
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	int ultimoId;
	Passenger* auxPassenger;

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while (feof(pFile) == 0)
		{
			auxPassenger = Passenger_new();
			if (fread(auxPassenger, sizeof(Passenger),1,pFile) == 1)
			{
				if (auxPassenger != NULL && ll_add(pArrayListPassenger, auxPassenger) == 0 && ll_len(pArrayListPassenger) < 2000)
				{
					Passenger_getId(auxPassenger, &id);
					if (id > ultimoId)
					{
						Passenger_getId(auxPassenger, &ultimoId);
					}
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


