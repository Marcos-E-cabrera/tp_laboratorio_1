#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define ASC 1
#define DESC 0

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
int findPassengerByIdFree(ePassenger list[], int len, int *id);
///2.3
int findPassengerById(ePassenger list[], int len, int id, int* pIndex);
///2.4
int removePassenger(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[]);
///2.5
int sortPassengers(ePassenger* list, int len,int order);
int sortPassengersByCode(ePassenger* list, int len,eStatusFlight* status, int order);
int listarPasajerosByStatus(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[]);
int listadoDeCuentas(ePassenger list[], int len, float* acumPrecio, int* cantPassengers, int* contMaximo,float* promedio);
int subMenuInformes(ePassenger list[], int len, eTypePassenger sector[],int tamSector, eStatusFlight status[], int tamStatus);
///2.6
int printPassenger(ePassenger l, eTypePassenger sector[], eStatusFlight status[], int len);
int listarPasajeros(ePassenger list[], int len, eTypePassenger sector[], eStatusFlight status[]);
///2.7
int modifyPassenger(ePassenger list[], int len, eTypePassenger sectores[], eStatusFlight status[], int tamSector, int tamStatus);
int menuModifyPassenger();
///2-8
/**
 * hardcodea pasajeros
 * @param list ePassenger
 * @param len longuitud de array
 * @param cant cantidad de pasajeros
 * @param id puntero de id.
 * @return
 */
int hardcodearPasajeros(ePassenger list[], int len, int cant, int* id);



















