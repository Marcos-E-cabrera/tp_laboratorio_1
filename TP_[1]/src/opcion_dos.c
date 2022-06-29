#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"
#include "utn.h"

/* Valor del vuelo de Aerolineas */
float valorAerolineas(){
	float y; //Aerolineas
	utn_getFloat(&y,"\n |> Ingrese Precio vuelo Aerolineas: ", " |> Error, Reingrese Valor de Aerlineas", 1.00,999999.00,2);
	return y;
}

/* Valor del vuelo de Aerolineas */
float valorLatam(){
	float z; //Latam
	utn_getFloat(&z,"\n |> Ingrese Precio vuelo Latam: ", " |> Error, Reingrese Valor de Latam", 1.00,999999.00,2);
	return z;
}

