#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typePassenger.h"

int listarType(eTypePassenger type [], int tam){
int todoOk = -1;

    if(type != NULL && tam > 0){
        printf("  ______________________________\n");
        printf(" |      *** CLASS LIST ***      |\n");
        printf(" |------------------------------|\n");
        printf(" |  TYPE  |     Descripcion     |\n");
        printf(" |------------------------------|\n");
        for(int i=0; i < tam; i++){
            printf(" |   %d    |   %-15s   |\n", type[i].typePassenger, type[i].descripcion);
        }
        printf(" |------------------------------|\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionType(eTypePassenger type[], int tam, int typePassenger, char descripcion[]){
int todoOk = -1;
int indice;

	buscarType(type, tam, typePassenger, &indice);

    if(descripcion != NULL && indice != -1){
    	strcpy(descripcion, type[indice].descripcion);
     todoOk = 1;
    }
  return todoOk;
}

int buscarType(eTypePassenger type[], int tam, int typePassenger, int* pIndice){
	int todoOk = -1;
	if(type != NULL && tam > 0 && pIndice != NULL){
		*pIndice = 1;
		for(int i=0; i < tam; i++){
			if(type[i].typePassenger == typePassenger){
				*pIndice = i;
					break;
	        }
		}
		todoOk = 1;
	 }
   return todoOk;
}


int validarType(eTypePassenger type[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarType(type, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}
