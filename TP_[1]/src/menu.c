#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
#include "menu.h"
#include "opcion_dos.h"
#include "cargaForzada.h"

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
	char letra;

	do{
		system("cls");
		printf("\n                    MENU DE OPCIONES                   ");
		printf("\n                    ----------------                   ");
		printf("\n\n | 1) Ingresar Kilometros.                          ");
		printf("\n | 2) Ingresar Precio de Vuelos:                    ");
		printf("\n |    - Aerolineas                                  ");
		printf("\n |    - Latam                                       ");
		printf("\n | 3) Calcular todos los costos:                    ");
		printf("\n |    a) Tarjeta de debito.                         ");
		printf("\n |    b) Tarjeta de credito.                        ");
		printf("\n |    c) Bitcoin.                                   ");
		printf("\n |    d) Mostrar precio por km.                     ");
		printf("\n |    e) Mostrar diferencia de precio ingresada.    ");
		printf("\n | 4) Informar Resultados.                          ");
		printf("\n | 5) Carga forzada de datos.                       ");
		printf("\n | 6) Salir.                                        ");
		printf("\n | = = = = = = = = = = = = = = = = = = = = = = = = =\n");

		do{ /* Filtro de la opción elegida por el usuario */
			printf("\n | Por favor no ingrese letras, solo numeros");
			printf("\n | Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
			scanf("%c", &letra);
		} while ((isalpha(letra))||(opcion < 1 || opcion >6));

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
				printf(" | Error, Introduzca una opcion valida\n");
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
				printf(" | Se calculo todos los costos con Exito\n");
				system("pause");
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 4:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 1){
			printf("\n               LISTA TOTAL DE COSTOS                ");
			printf("\n               ---------------------                ");
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
				system("pause");
				flagOne = 0;
				flagTwo = 0;
				flagthree = 0;
			}else{
				system("cls");
				printf(" | Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 5:
			cargaForzada();
		break;
		}
	}while((isalpha(letra)) || (opcion !=6) );
	return opcion;
}
