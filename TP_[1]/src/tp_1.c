/*
 ============================================================================
 Name        : tp_[1]
 Author      : marcos cabrera - 1 A
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Trabajo práctico #1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "menu.h"

int main(void){
	setbuf(stdout, NULL);
	int opcion;

	// Programa: Menú de opciones
	do{
		opcion = mainMenu (opcion);
	}while(opcion !=6 );

	return EXIT_SUCCESS;
}
