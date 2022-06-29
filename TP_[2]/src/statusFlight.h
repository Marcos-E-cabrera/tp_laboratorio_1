#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct{
	int statusFlight;
	char descripcion[20];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */

int listarstatus(eStatusFlight status[], int tamStatus);
int cargarDescripcionStatus(eStatusFlight status[], int tam, int statusFlight, char descripcion[]);
int buscarStatus(eStatusFlight status[], int tam, int statusFlight, int* pIndice);
int validarStatus(eStatusFlight status[], int tam, int id);
