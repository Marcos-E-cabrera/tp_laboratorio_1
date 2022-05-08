#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct{
	int typePassenger;
	char descripcion[20];
}eTypePassenger;

#endif /* TYPEPASSENGER_H_ */

int listarSectores(eTypePassenger sectores[], int tamSec);
int cargarDescripcionSector(eTypePassenger sectores[], int tam, int typePassenger, char descripcion[]);
int buscarSector(eTypePassenger sectores[], int tam, int typePassenger, int* pIndice);
