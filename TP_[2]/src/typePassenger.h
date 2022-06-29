#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct{
	int typePassenger;
	char descripcion[20];
}eTypePassenger;

#endif /* TYPEPASSENGER_H_ */

int listarType(eTypePassenger type[], int tam);
int cargarDescripcionType(eTypePassenger type[], int tam, int typePassenger, char descripcion[]);
int buscarType(eTypePassenger type[], int tam, int typePassenger, int* pIndice);
int validarType(eTypePassenger type[], int tam, int id);
