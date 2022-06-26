#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "utn.h"
#include "LinkedList.h"
#include "Passenger.h"

// > Mostrar

/* \brief Muestra el pasajero
 * \return pasajero
 */
int Passenger_ImprimirDatos(Passenger* auxPassenger)
{
	int todoOk = 0;
	char descTipo[20];
	char descEstado[25];

	if(auxPassenger!=NULL)
	{
		Passenger_getId(auxPassenger, &auxPassenger->id);
		Passenger_setNombre(auxPassenger, auxPassenger->nombre);
		Passenger_setApellido(auxPassenger, auxPassenger->apellido);
		Passenger_getPrecio(auxPassenger, &auxPassenger->precio);
		Passenger_getCodigoVuelo(auxPassenger, auxPassenger->codigoVuelo);
		Passenger_getTipoPasajero(auxPassenger,&auxPassenger->tipoPasajero);
		Passenger_getEstadoVuelo(auxPassenger, &auxPassenger->estadoVuelo);
		Passenger_getDescripcionTipoPasajero(auxPassenger->tipoPasajero, descTipo);
		Passenger_getDescripcionStatusFlight(auxPassenger->estadoVuelo, descEstado);

		printf(" | %-4d | %-50s | %-50s |   $%-10.2f |    %-8s  | %-15s | %-10s |\n",
				auxPassenger->id,auxPassenger->nombre,auxPassenger->apellido,auxPassenger->precio,auxPassenger->codigoVuelo,descTipo,descEstado);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getDescripcionTipoPasajero(int typePassenger,char* desc)
{
	int todoOk=-1;

	if(desc!=NULL && typePassenger>0)
	{
		if(typePassenger==1)
		{
			strcpy(desc,"First Class");
		}
		else if(typePassenger==2)
		{
			strcpy(desc,"Executive Class");
		}
		else
		{
			strcpy(desc,"Economy Class");
		}
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getDescripcionStatusFlight(int statusFlight,char* desc)
{
	int todoOk=-1;

	if(desc!=NULL && statusFlight>0)
	{
		if(statusFlight==1)
		{
			strcpy(desc,"Aterrizado");
		}
		else if(statusFlight==2)
		{
			strcpy(desc,"En Horario");
		}
		else if(statusFlight==3)
		{
			strcpy(desc,"En Vuelo");
		}
		else
		{
			strcpy(desc,"Demorado");
		}
		todoOk=1;
	}
	return todoOk;
}

// > Constructores
Passenger* Passenger_new()
{
	Passenger* auxPassenger=(Passenger*) malloc(sizeof(Passenger));
	return auxPassenger;
}

/* \brief Le pasamos los datos del pasajero a la ePassenger y lo seteamos.
 * \params char* son todos los paramentros de la estructura (Id, Nombre , Apellido, Precio, CodigoVuelo, TipoDeVuelo, EstadoVuelo).
 * \return Todos los parametros validados.
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* newPassenger;
	newPassenger= Passenger_new();

    if(newPassenger!=NULL)
    {
    	Passenger_setId(newPassenger, atoi(idStr));
    	Passenger_setNombre(newPassenger, nombreStr);
    	Passenger_setApellido(newPassenger, apellidoStr);
    	Passenger_setPrecio(newPassenger, atof(precioStr));
    	Passenger_setCodigoVuelo(newPassenger, codigoVueloStr);
    	Passenger_setTipoPasajero(newPassenger,  atoi(tipoPasajeroStr));
    	Passenger_setEstadoVuelo(newPassenger, atoi(estadoVueloStr));
    }
	return newPassenger;
}

// > Destucor

void Passenger_delete(Passenger* this)
{
	free (this);
}

// > Setters and Getters

int Passenger_setId(Passenger* this,int id)
{
    int todoOk = 0;
    if(this != NULL && id > 0 && id < 20000)
    {
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk = -1;
	if (this != NULL)
	{
		*id = this -> id;
		todoOk = 0;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 50 && strlen(nombre) > 2)
    {
        strcpy(this->nombre, nombre);
        strlwr(this->nombre);
        (this->nombre)[0] = toupper((this->nombre)[0]);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;
    if(this != NULL && apellido != NULL && strlen(apellido) < 50 && strlen(apellido) > 2)
    {
        strcpy(this->apellido, apellido);
        strlwr(this->apellido);
        (this->apellido)[0] = toupper((this->apellido[0]));
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;
    if(this != NULL && apellido != NULL )
    {
        strcpy(apellido, this->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;
	if (this != NULL && precio > 9999 && precio < 999999)
	{
		this->precio = precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;
	if (this != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;
	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy (this -> codigoVuelo, codigoVuelo);
		todoOk = 0;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		todoOk=1;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = 0;

	if (this != NULL && tipoPasajero > 0 && tipoPasajero <= 3)
	{
		this->tipoPasajero = tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = 0;
	if (this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int todoOk = 0;
	if (this != NULL && estadoVuelo > 0 && estadoVuelo <= 4)
	{
		this->estadoVuelo = estadoVuelo;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int todoOk = 0;
	if (this != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		todoOk = 1;
	}
	return todoOk;
}

int passenger_orderById(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		if(passA -> id > passB -> id)
	    {
			retorno = 1;
	    }
		else if(passA ->id < passB ->id)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int passenger_orderByNombre(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		retorno = strcmp(passA ->nombre, passB ->nombre);
	}
	return retorno;
}

int passenger_orderByApellido(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		retorno = strcmp(passA ->apellido, passB ->apellido);
	}
	return retorno;
}

int passenger_orderByPrecio(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		if(passA ->precio > passB ->precio)
		{
			retorno = 1;
		}
		else if(passA ->precio < passB ->precio)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int passenger_orderByCode(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		retorno = strcmp(passA ->codigoVuelo, passB ->codigoVuelo);
	}
	return retorno;
}

int passenger_orderByTipoPasajero(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		if(passA -> tipoPasajero > passB -> tipoPasajero)
	    {
			retorno = 1;
	    }
		else if(passA ->tipoPasajero < passB ->tipoPasajero)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int passenger_orderByEstadoVuelo(void* a, void* b)
{
	int retorno = 0;
	Passenger* passA;
	Passenger* passB;

	if( a != NULL && b != NULL)
	{
		passA = (Passenger*) a;
		passB = (Passenger*) b;
		if(passA -> estadoVuelo > passB -> estadoVuelo)
	    {
			retorno = 1;
	    }
		else if(passA ->estadoVuelo < passB ->estadoVuelo)
		{
			retorno = -1;
		}
	}
	return retorno;
}
