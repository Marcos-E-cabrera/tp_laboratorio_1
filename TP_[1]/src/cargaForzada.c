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

	printf("\n              >>> CARGA FORZADA DE DATOS");
	printf("\n  ________________________________________________________");
	printf("\n\n > CARGA AEROLINEAS");
	printf("\n  ________________________________________________________");
	printf("\n |> KMs Ingresados : %d Km", x);
	printf("\n  ________________________________________________________");
	printf("\n |> Precio Aerolineas : $ %.1f", y);
	printf("\n |> Precio con Tarjeta de debito : $ %.1f", debitoAero);
	printf("\n |> Precio con Tarjeta de credito : $ %.2f", creditoAero);
	printf("\n |> Precio pagado con Bitcoin : %f BTC", bitcoinAero);
	printf("\n |> Mostrar precio por km : $ %.4f", precioUnitarioAero);
	printf("\n |________________________________________________________|");
	printf("\n\n > CARGA LATAM:");
	printf("\n  ________________________________________________________");
	printf("\n |> Precio Latam : $ %.2f", z);
	printf("\n |> Precio con Tarjeta de debito : $ %.1f", debitoLatam);
	printf("\n |> Precio con Tarjeta de credito : $ %.2f", creditoLatam);
	printf("\n |> Precio pagado con Bitcoin : %f BTC", bitcoinLatam);
	printf("\n |> Mostrar precio por km : $ %.4f", precioUnitarioLatam);
	printf("\n |________________________________________________________|");
	printf("\n  ________________________________________________________");
	printf("\n |> Mostrar diferencia de precio ingresada : $ %.2f", diferenciaPrecio);
	printf("\n |________________________________________________________|\n");
	system("\n pause");
}
