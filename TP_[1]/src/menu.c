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
	int flagError = 0;

	do{
		system("cls");
		printf("\n  _________________________________________________\n");
		printf(" |                * MENU AEROLINEAS *              |");
		printf("\n |-------------------------------------------------|");
		printf("\n | 1 | Ingresar Kilometros.                        |");
		printf("\n |---|---------------------------------------------|");
		printf("\n | 2 | Ingresar Precio de Vuelos:                  |");
		printf("\n |---|---------------------------------------------|");
		printf("\n |   | > Aerolineas                                |");
		printf("\n |   | >Latam                                      |");
		printf("\n |---|---------------------------------------------|");
		printf("\n | 3 |Calcular todos los costos:                   |");
		printf("\n |   | > Tarjeta de debito.                        |");
		printf("\n |   | > Tarjeta de credito.                       |");
		printf("\n |   | > Bitcoin.                                  |");
		printf("\n |   | > Mostrar precio por km.                    |");
		printf("\n |   | > Mostrar diferencia de precio ingresada.   |");
		printf("\n |---|---------------------------------------------|");
		printf("\n | 4 | Informar Resultados.                        |");
		printf("\n |---|---------------------------------------------|");
		printf("\n | 5 | Carga forzada de datos.                     |");
		printf("\n |---|---------------------------------------------|");
		printf("\n | 6 | Salir.                                      |");
		printf("\n |-------------------------------------------------|\n");

		do{ /* Filtro de la opci�n elegida por el usuario */
			printf("\n |> Por favor no ingrese letras, solo numeros");
			printf("\n |> Introduzca una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
			scanf("%c", &letra);
		} while ((isalpha(letra))||(opcion < 1 || opcion >6));

		switch (opcion){
		case 1:
			x = kilometrosDeVuelo();
			if(x <= 0){
				flagError =1;
			}
			flagOne = 1;
		break;
		case 2:
			if(flagOne == 1 && flagTwo == 0){
				y = valorAerolineas();
				z = valorLatam();
				flagTwo = 1;
			}else{
				printf(" |> Error, Introduzca una opcion valida\n");
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
				printf(" |> Se calculo todos los costos con Exito\n");
				system("pause");
			}else{
				system("cls");
				printf(" |> Error, Introduzca una opcion valida\n");
				system("pause");
			}
		break;
		case 4:
			if (flagOne == 1 && flagTwo == 1  && flagthree == 1){
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
				if(flagError == 1){
					printf("\n |> Mostrar precio por km : ERROR");
				}
				else{
					printf("\n |> Mostrar precio por km : $ %.2f", precioUnitarioAero);
				}
				printf("\n |________________________________________________________|");
				printf("\n\n > CARGA LATAM:");
				printf("\n  ________________________________________________________");
				printf("\n |> Precio Latam : $ %.2f", z);
				printf("\n |> Precio con Tarjeta de debito : $ %.1f", debitoLatam);
				printf("\n |> Precio con Tarjeta de credito : $ %.2f", creditoLatam);
				printf("\n |> Precio pagado con Bitcoin : %f BTC", bitcoinLatam);
				if(flagError == 1){
					printf("\n |> Mostrar precio por km : ERROR");
				}
				else{
					printf("\n |> Mostrar precio por km : $ %.2f", precioUnitarioLatam);
				}
				printf("\n |________________________________________________________|");
				printf("\n  ________________________________________________________");
				printf("\n |> Mostrar diferencia de precio ingresada : $ %.2f", diferenciaPrecio);
				printf("\n |________________________________________________________|\n");
				system("\n pause");
				flagOne = 0;
				flagTwo = 0;
				flagthree = 0;
			}else{
				system("cls");
				printf(" |> Error, Introduzca una opcion valida\n");
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
