#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "prototipado.h"

int mainMenu (int opcion){
	int x;
	float y;
	float z;
	float debitoAero;
	float debitoLatam;
	float creditoAero;
	float creditoLatam;
	float bitcoinAero;
	float bitcoinLatam;
	float precioUnitarioAero;
	float precioUnitarioLatam;
	float diferenciaPrecio;
	int flagOne = 0;
	int flagTwo = 0;
	int flagthree = 0;
	int flagFour = 0;

	do{
		system("cls");
		printf("\n ||================ MENU DE OPCIONES ================||");
		printf("\n || 1) Ingresar Kilometros.                          ||");
		printf("\n || 2) Ingresar Precio de Vuelos:                    ||");
		printf("\n ||    - Aerolineas                                  ||");
		printf("\n ||    - Latam                                       ||");
		printf("\n || 3) Calcular todos los costos:                    ||");
		printf("\n ||    a) Tarjeta de debito.                         ||");
		printf("\n ||    b) Tarjeta de credito.                        ||");
		printf("\n ||    c) Bitcoin.                                   ||");
		printf("\n ||    d) Mostrar precio por km.                     ||");
		printf("\n ||    e) Mostrar diferencia de precio ingresada.    ||");
		printf("\n || 4) Informar Resultados.                          ||");
		printf("\n || 5) Carga forzada de datos.                       ||");
		printf("\n || 6) Salir.                                        ||");
		printf("\n ||==================================================||");

		do{ /* Filtro de la opción elegida por el usuario */
			printf("\n\n| Por favor no ingrese letras, solo numeros");
			printf("\n| Introduzca una opcion: ");
			scanf("%d", &opcion);

			do{ /* No se permiten negativos ni numeros mas grandes que 6 */
				if ( opcion < 1 || opcion > 6 ){
					system("cls");
					printf("| Error, Introduzca una opcion valida: ");
					fflush(stdin);
					scanf("%d", &opcion );
				}
			}while ( opcion < 1 || opcion > 6 );
		} while ( opcion < 1 || opcion > 6 );

		system("cls");
		/* La opción sólo puede ser 1, 2, 3, 4, 5 ó 6 */
		switch ( opcion ){
		case 1:
			x = kilometrosDeVuelo();
			flagOne = 1;
		break;
		case 2:
			if(flagOne == 1 && flagTwo == 0){
				y = valorAerolineas();
				z = valorLatam();
				flagTwo = 1;
			}else{
				system("cls");
				printf("| Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 3:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 0){
				debitoAero = descuento(y);
				debitoLatam = descuento(z);
				creditoAero = credito(y);
				creditoLatam = credito(z);
				bitcoinAero = bitcoin(y);
				bitcoinLatam = bitcoin(z);
				precioUnitarioAero = precioUnitario(y, x);
				precioUnitarioLatam = precioUnitario(z, x);
				diferenciaPrecio = difPrecio(y, z);
				flagthree = 1;
			}else{
				system("cls");
				printf("| Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 4:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 1 && flagFour == 0){
				printf("| KMs Ingresados : %d Km\n", x);
				printf("\n| Precio Aerolineas : $ %.2f", y);
				printf("\n| a) Precio con Tarjeta de debito : $ %.2f", debitoAero);
				printf("\n| b) Precio con Tarjeta de credito : $ %.2f", creditoAero);
				printf("\n| c) Precio pagado con Bitcoin : %f BTC", bitcoinAero);
				printf("\n| d) Mostrar precio por km : $ %.2f", precioUnitarioAero);

				printf("\n\n| Precio Latam : $ %.2f", z);
				printf("\n| a) Precio con Tarjeta de debito : $ %.2f", debitoLatam);
				printf("\n| b) Precio con Tarjeta de credito : $ %.2f", creditoLatam);
				printf("\n| c) Precio pagado con Bitcoin : %f BTC", bitcoinLatam);
				printf("\n| d) Mostrar precio por km : $ %.2f", precioUnitarioLatam);
				printf("\n\n| e) Mostrar diferencia de precio ingresada : $ %.2f\n\n", diferenciaPrecio);
				system("pause");
				flagFour = 1;
			}else{
				system("cls");
				printf("| Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 5:
			x = 7090;
			y = 162965;
			z = 159339;
			debitoAero = descuento(y);
			debitoLatam = descuento(z);
			creditoAero = credito(y);
			creditoLatam = credito(z);
			bitcoinAero = bitcoin(y);
			bitcoinLatam = bitcoin(z);
			precioUnitarioAero = precioUnitario(y, x);
			precioUnitarioLatam = precioUnitario(z, x);
			diferenciaPrecio = difPrecio(y, z);
			printf("| ============= Carga forzada de datos =============");
			printf("\n| KMs Ingresados : %d Km\n", x);
			printf("\n| Precio Aerolineas : $ %.2f", y);
			printf("\n| a) Precio con Tarjeta de debito : $ %.2f", debitoAero);
			printf("\n| b) Precio con Tarjeta de credito : $ %.2f", creditoAero);
			printf("\n| c) Precio pagado con Bitcoin : %f BTC", bitcoinAero);
			printf("\n| d) Mostrar precio por km : $ %.2f", precioUnitarioAero);

			printf("\n\n| Precio Latam : $ %.2f", z);
			printf("\n| a) Precio con Tarjeta de debito : $ %.2f", debitoLatam);
			printf("\n| b) Precio con Tarjeta de credito : $ %.2f", creditoLatam);
			printf("\n| c) Precio pagado con Bitcoin : %f BTC", bitcoinLatam);
			printf("\n| d) Mostrar precio por km : $ %.2f", precioUnitarioLatam);
			printf("\n\n| e) Mostrar diferencia de precio ingresada : $ %.2f\n\n", diferenciaPrecio);
			system("pause");
		break;
		}
	}while(opcion !=6 );
	return opcion;
}

/* Kilometros del vuelo ingresado */
float kilometrosDeVuelo(){
	system("cls");
	int kilometros; // kms
	do
	{
		printf("| Ingrese los kilometros del vuelo: ");
		scanf("%d", &kilometros);
		if(kilometros < 1){
			printf("| Error, Reingrese los kilometros del vuelo: ");
			scanf("%d", &kilometros);
		}
	}while( kilometros < 1 );
    return kilometros;
}

/* Valor del vuelo de Aerolineas */
float valorAerolineas(){
	system("cls");
	float y; //Aerolineas
	do{
		printf("| Ingrese Precio vuelo Aerolíneas : ");
		fflush(stdin);
		scanf("%f", &y);
		do{
			if(y < 1){
				printf("| Error, Reingrese Precio vuelo Aerolíneas : ");
				fflush(stdin);
				scanf("%f", &y);
			}
		}while(y < 1);
	}while(y < 1);
	return y;
}

/* Valor del vuelo de Aerolineas */
float valorLatam(){
	system("cls");
	float z; //Latam
	do{
		printf("| Ingrese el valor de Latam : ");
		fflush(stdin);
		scanf("%f", &z);
		do{
			if(z < 1){
				printf("| Error, Reingrese el valor de Latam : ");
				fflush(stdin);
				scanf("%f", &z);
			}
		}while(z < 1);
	}while(z < 1);
	return z;
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
	porcentaje = importe - interes;
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
	return (importe/kms);
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

