#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statusFlight.h"

int listarstatus(eStatusFlight status[], int tamStatus){
int todoOk = -1;

    if(status != NULL && tamStatus > 0){
        printf("  ______________________________\n");
        printf(" |  *** STATUS FLIGHT LIST ***  |\n");
        printf(" |------------------------------|\n");
        printf(" |  ID  |      Descripcion      |\n");
        printf(" |------------------------------|\n");
        for(int i=0; i < tamStatus; i++){
        printf(" |   %d  |      %-12s     |\n", status[i].statusFlight, status[i].descripcion);
        }
        printf(" |------------------------------|\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionStatus(eStatusFlight status[], int tam, int statusFlight, char descripcion[]){
int todoOk = -1;
int indice;

	buscarStatus(status, tam, statusFlight, &indice);

    if(descripcion != NULL && indice != -1){
    	strcpy(descripcion, status[indice].descripcion);
     todoOk = 1;
    }
  return todoOk;
}

int buscarStatus(eStatusFlight status[], int tam, int statusFlight, int* pIndice)
{
	int todoOk = -1;
	if(status != NULL && tam > 0 && pIndice != NULL){
		*pIndice = 1;
		for(int i=0; i < tam; i++){
			if(status[i].statusFlight == statusFlight){
				*pIndice = i;
					break;
	        }
		}
		todoOk = 1;
	 }
   return todoOk;
}

int validarStatus(eStatusFlight status[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarStatus(status, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}
