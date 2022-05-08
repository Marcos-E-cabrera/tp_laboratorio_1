/*
 ============================================================================
 Name        : tp_[1]
 Author      : marcos cabrera - 1 A
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Trabajo práctico #2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "main_Menu.h"

#define TAM 10
#define TAMS 5

int main(void){
	setbuf(stdout, NULL);
	int opcion;

	// Programa: Menú de opciones
	do{
		opcion = main_Menu(opcion);
	}while(opcion !=6 );

	return EXIT_SUCCESS;
}
