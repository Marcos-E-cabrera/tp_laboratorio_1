#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

// >>> Archivo.txt
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r"); // leo archivo
		if (pFile != NULL)
		{
			parser_PassengerFromText(pFile, pArrayListPassenger);
			todoOk = 1;
		}
		else{
			printf(" |> No se puedo abrir el Archivo %s.", path);
		}
	}
	fclose (pFile);
    return todoOk;
}

// >>> Controller Archivo ID
int controller_passengerId(char* path, LinkedList* list)
{
	int todoOk = 0;
	FILE* pFile;

	if (path != NULL)
	{
		pFile = fopen(path, "rb");
		if (pFile != NULL)
		{
			parser_passengerId(pFile, list);
			todoOk = 1;
		}
		else{
			printf(" |> No se puedo abrir el Archivo %s.", path);
		}
	}
	fclose (pFile);
    return todoOk;
}
int controller_BuscarId(LinkedList* pArrayListPassenger, int id)
{
	int todoOk = -1;
	int i;
	int auxId;
	int lenLista;
	Passenger* auxPassenger;

	if (pArrayListPassenger != NULL && id > 0)
	{
		lenLista = ll_len(pArrayListPassenger);

		if (lenLista > 0)
		{
			for (i = 0; i < lenLista; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPassenger, &auxId);
				if (auxPassenger != NULL && auxId == id)
				{
					todoOk = i;
					break;
				}
			}
		}
	}
    return todoOk;
}

// >>> BINARIO

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb"); // leo archivo
		if (pFile != NULL)
		{
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			todoOk = 1;
		}
		else{
			printf(" |> No se puedo abrir el Archivo %s.", path);
		}
	}
	fclose (pFile);
    return todoOk;
}

// >>> ABM
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int auxId;
	char auxNombre[50];
	char auxApellido [50];
	float precio;
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	char descTipo[20];
	char descEstado[20];
	char validacion;

	Passenger* auxPasajero = Passenger_new();

	if (pArrayListPassenger != NULL)
	{
		printf("\n	                  >> PASSENGER ADD\n");
		printf(" ________________________________________________________________\n\n");

		if (utn_getNombre(auxNombre, 50, " |> Ingrese su nombre: ", " |>Ingrese un nombre valido.", 10) == 0 &&
			utn_getNombre(auxApellido, 50, " |> Ingrese su apellido: ", " |>Ingrese un apellido valido.", 10) == 0 &&
			utn_getFloat(&precio, " |> Ingrese el precio: ", " |> Error ingrese algo valido.", 9999, 100000, 10) == 0 &&
			utn_getCode( auxCodigoVuelo," |> Ingrese el codigo de vuelo: ", " |> Ingrese un codigo valido", 7, 10) == 0 &&
			utn_getNumero(&auxTipoPasajero," |> Ingrese el tipo de pasajero: \n"
										   "  >(1)| First Class\n"
										   "  >(2)| Executive Class\n"
										   "  >(3)| Economy Class \n"
										   " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 3, 10) ==0 &&
			utn_getNumero(&auxEstadoVuelo, " |> Ingrese el estado del vuelo: \n"
										   "  >(1)| Aterrizado\n"
										   "  >(2)| En Horario\n"
										   "  >(3)| En Vuelo\n"
										   "  >(4)| Demorado\n"
										   " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 4, 10) ==0)
		{

			switch(auxTipoPasajero)
			{
				case 1:
					strcpy(descTipo,"First Class");
				break;
				case 2:
					strcpy(descTipo,"Executive Class");
				break;
				case 3:
					strcpy(descTipo,"Economy Class");
				break;
			}

			switch(auxEstadoVuelo)
			{
				case 1:
					strcpy(descEstado,"Aterrizado");
				break;
				case 2:
					strcpy(descEstado,"En Horario");
				break;
				case 3:
					strcpy(descEstado,"En Vuelo");
				break;
				case 4:
					strcpy(descEstado,"Demorado");
				break;
			}
			buscarMayorId(pArrayListPassenger, &auxId);
			printf("\n	               	   >> NOW PASSENGER %d\n"
				   " ________________________________________________________________\n\n"
				   " |> Nombre: %-50s\n"
				   " |> Apellido: %-50s\n"
				   " |> Precio: $%-10.2f\n"
				   " |> Codigo Vuelo: %-8s\n"
				   " |> Tipo Pasajero: %-15s\n"
				   " |> Estado Vuelo: %-10s\n",auxId,auxNombre,auxApellido,precio,auxCodigoVuelo,descTipo,descEstado);

			printf(" |> Ingresar nuevo Pasajero (s/n) ?: ");
			fflush(stdin);
			scanf("%c",&validacion);
			validacion = tolower(validacion);
			while( validacion != 's' && validacion != 'n')
			{
				printf(" |> Error, Ingresar nuevo Pasajero (s/n) ?: ");
				fflush(stdin);
				scanf("%c",&validacion);
				validacion = tolower(validacion);
			}

			if ( validacion == 's' && auxPasajero != NULL)
			{

				ll_add(pArrayListPassenger, auxPasajero);
				Passenger_setId(auxPasajero, auxId);
				Passenger_setNombre(auxPasajero, auxNombre);
				Passenger_setApellido(auxPasajero, auxApellido);
				Passenger_setPrecio(auxPasajero, precio);
				Passenger_setCodigoVuelo(auxPasajero, auxCodigoVuelo);
				Passenger_setTipoPasajero(auxPasajero, auxTipoPasajero);
				Passenger_setEstadoVuelo(auxPasajero, auxEstadoVuelo);

				Passenger_getId(auxPasajero, &auxId);
				todoOk =1;
			}
		}
	}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int auxId;
	int busquedaId;

	int opcion;
	char salir;
	Passenger* auxPasajero = Passenger_new();

	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		printf("\n	                  >> PASSENGER EDIT\n");
		printf(" ________________________________________________________________\n\n");

		if(utn_getNumero(&auxId," |> Ingrese ID a Editar: ", " \n|> Ingrese un ID valido\n", 1, ll_len(pArrayListPassenger), 10) ==0)
		{
			busquedaId = controller_BuscarId(pArrayListPassenger, auxId);
			if(busquedaId != -1)
			{
				do{
					auxPasajero = ll_get(pArrayListPassenger, busquedaId);
					printf("\n                                                                   		>>> LISTADO PASAJEROS\n");
					printf("  ______________________________________________________________________________________________________________________________________________________________________________\n");
					printf(" |  ID  |                     NOMBRE                         |                    APELLIDO                        |     PRECIO    | CODIGO VUELO | TIPO PASAJERO | ESTADO VUELO |\n");
					printf(" |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
					Passenger_ImprimirDatos(auxPasajero);
					fflush(stdin);
					utn_getNumero(&opcion," \n    >>> MENU DE EDIT\n"
										  "  __________________________\n"
										  " | 1  | Nombre.             |\n"
										  " | 2  | Apellido.           |\n"
										  " | 3  | Precio.             |\n"
									 	  " | 4  | Code.               |\n"
										  " | 5  | Tipo de Pasajero.   |\n"
										  " | 6  | Estado de Vuelo.    |\n"
										  " | 7  | Salir.              |\n"
										  " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 7, 10);
					switch(opcion){
					case 1:
						if(utn_getNombre(auxPasajero->nombre, 50, " |> Ingrese su nombre: ", " |>Ingrese un nombre valido.", 10)==0){
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 2:
						if(utn_getNombre(auxPasajero->apellido, 50, " |> Ingrese su apellido: ", " |>Ingrese un apellido valido.", 10)==0){
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 3:
						if(utn_getFloat(&auxPasajero->precio, " |> Ingrese el precio: ", " |> Error ingrese algo valido.", 9999, 100000, 10)==0){
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 4:
						if(utn_getCode(auxPasajero->codigoVuelo," |> Ingrese el codigo de vuelo: ", " |> Ingrese un codigo valido", 7, 10)==0){
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 5:
						if(utn_getNumero(&auxPasajero->tipoPasajero," |> Ingrese el tipo de pasajero: \n"
																   "  >(1)| First Class\n"
																   "  >(2)| Executive Class\n"
																   "  >(3)| Economy Class \n"
																   " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 3, 10)==0)
						{
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 6:
						if(utn_getNumero(&auxPasajero->estadoVuelo, " |> Ingrese el estado del vuelo: \n"
																   "  >(1)| Aterrizado\n"
																   "  >(2)| En Horario\n"
																   "  >(3)| En Vuelo\n"
																   "  >(4)| Demorado\n"
																   " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 4, 10)==0)
						{
							printf(" |> Cargado con exito.");
						}
						else{
							printf(" |> Error en la Carga!!!");
						}
					break;
					case 7:
						salir = 's';
					break;
					}
				}while(salir!='s');
			}
			else
			{
				printf(" |> Pasajero no encontrado.");
			}
			if (ll_set(pArrayListPassenger, busquedaId, auxPasajero) == 0)
			{
				todoOk =1;
			}
		}
	}
	return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int auxId;
	int busquedaId;
	char validacion;
	char descTipo[20];
	char descEstado[20];
	Passenger* auxPasajero;

	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		printf("\n	                 >> PASSENGER REMOVE\n");
		printf(" ________________________________________________________________\n\n");

		if(utn_getNumero(&auxId," |> Ingrese ID a Eliminar: ", " \n|> Ingrese un ID valido\n", 1, ll_len(pArrayListPassenger), 10) ==0)
		{
			busquedaId = controller_BuscarId(pArrayListPassenger, auxId);

			if(busquedaId != -1)
			{
				auxPasajero = ll_get(pArrayListPassenger, busquedaId);
				switch(auxPasajero->tipoPasajero)
				{
					case 1:
						strcpy(descTipo,"First Class");
					break;
					case 2:
						strcpy(descTipo,"Executive Class");
					break;
					case 3:
						strcpy(descTipo,"Economy Class");
					break;
				}

				switch(auxPasajero->estadoVuelo)
				{
					case 1:
						strcpy(descEstado,"Aterrizado");
					break;
					case 2:
						strcpy(descEstado,"En Horario");
					break;
					case 3:
						strcpy(descEstado,"En Vuelo");
					break;
					case 4:
						strcpy(descEstado,"Demorado");
					break;
				}
				printf("\n		       	   >> PASSENGER %d\n"
					   " ________________________________________________________________\n\n"
					   " |> Nombre: %-50s\n"
					   " |> Apellido: %-50s\n"
			      	   " |> Precio: $%-10.2f\n"
					   " |> Codigo Vuelo: %-8s\n"
					   " |> Tipo Pasajero: %-15s\n"
					   " |> Estado Vuelo: %-10s\n",auxId,auxPasajero->nombre,auxPasajero->apellido,auxPasajero->precio,auxPasajero->codigoVuelo,descTipo,descEstado);

				printf(" |> Desea eliminar al Pasajero (s/n) ?: ");
				fflush(stdin);
				scanf("%c",&validacion);
				validacion = tolower(validacion);
				while( validacion != 's' && validacion != 'n')
				{
					printf(" |> Error, Desea eliminar al Pasajero (s/n) ?: ");
					fflush(stdin);
					scanf("%c",&validacion);
					validacion = tolower(validacion);
				}

				if ( validacion == 's' && auxPasajero != NULL)
				{
					ll_remove(pArrayListPassenger, busquedaId);
					todoOk =1;
				}
			}
			else
			{
				puts ("Pasajero no encontrado.");
			}
		}
	}
	return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int lenPasajeros;
	Passenger* auxPasajero;

	if (pArrayListPassenger != NULL)
	{
		lenPasajeros = ll_len(pArrayListPassenger);
		if (lenPasajeros > 0 && lenPasajeros < 2000)
		{
			printf("\n                                                                   		>>> LISTADO PASAJEROS\n");
			printf("  ______________________________________________________________________________________________________________________________________________________________________________\n");
			printf(" |  ID  |                     NOMBRE                         |                    APELLIDO                        |     PRECIO    | CODIGO VUELO | TIPO PASAJERO | ESTADO VUELO |\n");
			printf(" |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
			for (int i = 0; i < lenPasajeros; i++)
			{
				auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				if (auxPasajero != NULL)
				{
					if (Passenger_ImprimirDatos(auxPasajero))
					{
						todoOk = 1;
					}
				}
			}
			printf(" |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		}
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int opcion;
	int opcion2;

	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		utn_getNumero(&opcion," \n    >>> MENU DE ORDENAMIENTO\n"
							  "  __________________________\n"
							  " | 1  | Nombre.             |\n"
							  " | 2  | Apellido.           |\n"
							  " | 3  | Precio.             |\n"
							  " | 4  | Code.               |\n"
							  " | 5  | Tipo de Pasajero.   |\n"
							  " | 6  | Estado de Vuelo.    |\n"
							  " | 7  | Salir.              |\n"
							  " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 1, 7, 10);

		utn_getNumero(&opcion2," \n|> Ingrese con que orden quiere ordenar: (1 / 0)\n"
							   "  __________________________\n"
							   " | 1  | Descendente.        |\n"
							   " | 0  | Ascendente.         |\n"
							   " |> Ingrese su opcion: " , " |> Ingrese un tipo de vuelo valido\n", 0,1, 10);

		printf(" \n|> CARGANDO [///////////////	   ]\n");

		switch (opcion){
		case 1:
			if (ll_sort(pArrayListPassenger, passenger_orderById, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 2:
			if (ll_sort(pArrayListPassenger, passenger_orderByNombre, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 3:
			if (ll_sort(pArrayListPassenger, passenger_orderByApellido, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 4:
			if (ll_sort(pArrayListPassenger, passenger_orderByPrecio, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 5:
			if (ll_sort(pArrayListPassenger, passenger_orderByCode, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 6:
			if (ll_sort(pArrayListPassenger, passenger_orderByTipoPasajero, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		case 7:
			if (ll_sort(pArrayListPassenger, passenger_orderByEstadoVuelo, opcion2))
			{
				printf(" \n|> ORDENAMIENTO EXITOSO!!!");
			}
			break;
		}
		todoOk = 1;
	}
    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int i;

	FILE* fpArchivo;

	Passenger *pPassenger;
	int id;
	char name[50];
	char lastName[50];
	char flightCode[8];
	int typePassenger;
	float flightPrice;
	int statusFlight;
	int sizeOfList;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		fpArchivo = fopen(path,"w");
		if(fpArchivo!=NULL)
		{
			todoOk=1;
			sizeOfList = ll_len(pArrayListPassenger);
			for(i=0;i<sizeOfList;i++)
			{
            	pPassenger=(Passenger*)ll_get(pArrayListPassenger,i);
            	if(pPassenger!=NULL)
            	{
                    Passenger_getId(pPassenger, &id);
                    Passenger_getNombre(pPassenger, name);
                    Passenger_getApellido(pPassenger, lastName);
                    Passenger_getPrecio(pPassenger, &flightPrice);
                    Passenger_getCodigoVuelo(pPassenger, flightCode);
                    Passenger_getTipoPasajero(pPassenger, &typePassenger);
                    Passenger_getEstadoVuelo(pPassenger, &statusFlight);
    				fprintf(fpArchivo,"%d,%s,%s,%f,%s,%d,%d\n",id,name,lastName,flightPrice,flightCode,typePassenger,statusFlight);

            	}
			}
		}
		fclose(fpArchivo);
	}
	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	FILE* pFile;
	Passenger *pAuxPassenger;
	int sizeOfList;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"wb");//OPEN FILE AS BINARY
		sizeOfList = ll_len(pArrayListPassenger);
		for(int i=0;i<sizeOfList;i++)
		{
			pAuxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);//CAST IF ERROR
			if(pAuxPassenger!=NULL)
			{
				fwrite(pAuxPassenger,sizeof(Passenger),1,pFile);//WRITE ON THE FILE
			}
		}
		fclose(pFile);//CLOSE FILE
		ll_clear(pArrayListPassenger);//CLEAR LIST
		todoOk=1;
	}
    return todoOk;
}
