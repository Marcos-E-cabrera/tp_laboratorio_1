#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typePassenger.h"

int listarSectores(eTypePassenger sectores [], int tamSec){
int todoOk = 0;

    if(sectores != NULL && tamSec > 0){
        system("cls");
        printf("\n     *** class list ***\n\n");
        printf("  Type    |     Descripcion\n");
        printf("------------------------------\n");
        for(int i=0; i < tamSec; i++){
            printf("   %d    %20s\n", sectores[i].typePassenger, sectores[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionSector(eTypePassenger sectores[], int tam, int typePassenger, char descripcion[]){
int todoOk = 0;
int indice;

	buscarSector(sectores, tam, typePassenger, &indice);

    if(descripcion != NULL && indice != -1){
    	strcpy(descripcion, sectores[indice].descripcion);
     todoOk = 1;
    }
  return todoOk;
}

int buscarSector(eTypePassenger sectores[], int tam, int typePassenger, int* pIndice){
	int todoOk = 0;
	if(sectores != NULL && tam > 0 && pIndice != NULL){
		*pIndice = 1;
		for(int i=0; i < tam; i++){
			if(sectores[i].typePassenger == typePassenger){
				*pIndice = i;
					break;
	        }
		}
		todoOk = 1;
	 }
   return todoOk;
}