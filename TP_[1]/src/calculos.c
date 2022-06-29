#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"
#include "utn.h"

/* Kilometros del vuelo ingresado */
float kilometrosDeVuelo()
{
	float kilometros; // kms
	if(utn_getFloat(&kilometros,"\n |> Ingrese los Kilometros del vuelo: ", "\n |> El Kilometros tiene que ser mayor a 0", 1.00, 999999.99, 2) != 0)
	{
		kilometros = 0;
	}
    return kilometros;
}

/* Descuento */
float descuento(float importe){
	float porcentaje;
	float descuento;
	descuento = importe * 0.1;
	porcentaje = importe - descuento;
	return porcentaje;
}

/* Credito */
float credito(float importe){
	float porcentaje;
	float interes;
	interes = importe* 0.25;
	porcentaje = importe + interes;
	return porcentaje;
}

/* Bitcoin */
float bitcoin(float importe){
	float equivalente;
	equivalente = (importe * 1) / 4606954.55;
	return equivalente;
}

/* Precio Unitario */
float precioUnitario(float importe, float kms){
	int todoOk = 1;
	if(kms > 0){
		return (importe/kms);
		todoOk = 0;
	}
	return todoOk;
}

/* Diferencia de precio */
float difPrecio(float y , float z){
	if (y <= 0){
		return printf("$0");
	}else if(z <= 0){
		return printf("$0");
	}
	if(y > z){
		return y-z;
	}else{
		return z-y;
	}
}
