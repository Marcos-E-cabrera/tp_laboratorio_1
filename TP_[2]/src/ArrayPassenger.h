#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "typePassenger.h"
#include "statusFlight.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} ePassenger;

#endif /* ARRAYPASSENGER_H_ */

///2.1
int initPassengers(ePassenger list[], int len);
///2.2
int addPassenger(ePassenger list[], int len, char name[], char lastName[], float price, char flycode[], eTypePassenger sector[], int tamSector, eStatusFlight status[],int tamStatus, int* pId);
///2.3
int findPassengerById(ePassenger list[], int len, int *id);
///2.4
int removePassenger(ePassenger list[], int len, int id);
///2.5
int sortPassengers(ePassenger list[], int len, int order);
///2.6
//int printPassenger(ePassenger list, eTypePassenger sector[], eStatusFlight status[], int tamSector, int tamStatus);
int printPassenger(ePassenger l, eTypePassenger sector[], eStatusFlight status[], int len);
int cargarDescripcionSector(eTypePassenger sector[], int len, int typePassenger, char descripcion[]);
//int cargarDescripcionStatus(eStatusFlight status[], int len, int statusFlight, char descripcion[]);
int listarPasajeros(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[]);
///2.7
int sortPassengers(ePassenger list[], int len, int order);
