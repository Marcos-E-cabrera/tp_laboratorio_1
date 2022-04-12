#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "cargaForzada.h"

void cargaForzada (){
	int x = 7090;
	float y = 162965;
	float z = 159339;
	float debitoAero;
	float debitoLatam;
	float creditoAero;
	float creditoLatam;
	float bitcoinAero;
	float bitcoinLatam;
	float precioUnitarioAero;
	float precioUnitarioLatam;
	float diferenciaPrecio;

	debitoAero = descuento(y);
	debitoLatam = descuento(z);
	creditoAero = credito(y);
	creditoLatam = credito(z);
	bitcoinAero = bitcoin(y);
	bitcoinLatam = bitcoin(z);
	precioUnitarioAero = precioUnitario(y, x);
	precioUnitarioLatam = precioUnitario(z, x);
	diferenciaPrecio = difPrecio(y, z);
	printf("\n                CARGA FORZADA DE DATOS              ");
	printf("\n                ----------------------              ");
	printf("\n\n | KMs Ingresados : %d Km\n", x);
	printf("\n | Precio Aerolineas : $ %.2f", y);
	printf("\n | a) Precio con Tarjeta de debito : $ %.2f", debitoAero);
	printf("\n | b) Precio con Tarjeta de credito : $ %.2f", creditoAero);
	printf("\n | c) Precio pagado con Bitcoin : %f BTC", bitcoinAero);
	printf("\n | d) Mostrar precio por km : $ %.2f", precioUnitarioAero);

	printf("\n\n | Precio Latam : $ %.2f", z);
	printf("\n | a) Precio con Tarjeta de debito : $ %.2f", debitoLatam);
	printf("\n | b) Precio con Tarjeta de credito : $ %.2f", creditoLatam);
	printf("\n | c) Precio pagado con Bitcoin : %f BTC", bitcoinLatam);
	printf("\n | d) Mostrar precio por km : $ %.2f", precioUnitarioLatam);
	printf("\n\n | e) Mostrar diferencia de precio ingresada : $ %.2f\n\n", diferenciaPrecio);
	system("\n pause");
}
