#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "typePassenger.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
} ePassenger;

#endif /* ARRAYPASSENGER_H_ */

// abm Passengers
/**
 * addPassengers aniade pasajeros atraves de los parametros de la estructura ePassenger
 * @param vec aniade la estructura ePassenger con los siguientes parametros (id, name, lastName, price, flyCode, typePassenger, isEmpty)
 * isEmpty es el validador de los pasajeros funcion (initPassengers)
 * @param tam Longitud del array
 * @param sectores estructura array de clase de vuelo
 * @param tamSec Longitud del array de sectores
 * @param pId puntero del ID del pasajero, suma 1 cada vez que se ingrese un nuevo pasajero
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int addPassengers(ePassenger vec[], int tam, eTypePassenger sectores [], int tamSec, int* pId);
/**
 * removePassenger Eliminar un pasajero por Id (poner la bandera isEmpty en 1)
 * @param vec estructura array de pasajeros
 * @param tam Longitud del array
 * @param sectores estructura array de clase de vuelo
 * @param tamSec Longitud del array de sectores
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int removePassenger(ePassenger vec[], int tam, eTypePassenger sectores[], int tamSec);
int modificarEmpleado(ePassenger vec[], int tam, eTypePassenger sectores[], int tamSec);

// Mostrar Passengers
/**
 * imprimir el contenido de la matriz de pasajeros y sectores
 * @param e esctrucutra array de pasajeros
 * @param sectores estructura array de clase de vuelo
 * @param tam longuitud del array
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int printPassengers(ePassenger e, eTypePassenger sectores[], int tam);
int listarPasajeros(ePassenger vec[], int tam, eTypePassenger sectores[], int tamSec);

/**
 * inicializarEmpleados inicializa a los pasajeros indica que todas las posiciones del array esten vacías,
 * esta función pone la bandera (isEmpty) en TRUE en todas las posición del array
 * @param vec estructura array de los pasajeros
 * @param tam Longitud del array
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int inicializarPasajeros(ePassenger vec[], int tam);
int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId); // carga rapida de pasajeros

/**
 * findPassengerById Busca un pasajero por su Id en devuelve la posición del índice en el array
 * @param vec aniade la estructura ePassenger
 * @param tam Longitud del array
 * @param id pasajero cargado
 * @param pIndex corredor del array
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex);
/**
 * initPassengers recorro el array hasta encontrar (isEmpty) y el puntero se pone en (-1) para marcar que esta ocupado.
 * @param vec esctrucutra array de pasajeros
 * @param tam longuitud del array
 * @param pIndex puntero del indice
 * @return Devuelve (0) si hay error - (1) si está bien
 */
int initPassengers(ePassenger vec[], int tam, int* pIndex);

// sub menu
int menuModificarPasajero();














