#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "typePassenger.h"

// abm Passengers
int addPassengers(ePassenger vec[], int tam, eTypePassenger sectores [], int tamSec, int* pId){
    int todoOk = 0;
    int indice;
    char auxName[100];
    char auxLastName[100];
    char auxflycode[100];
    ePassenger newPassenger;

    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( initPassengers(vec, tam, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                printf("|Ingrese el nombre del pasajero: ");
                fflush(stdin);
                gets(auxName);

                while(strlen(auxName) >= 50)
                {
                    printf("|Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxName);
                }

                strcpy(newPassenger.name, auxName);

                printf("|Ingrese el apellido del pasajero: ");
                fflush(stdin);
                gets(auxLastName);

                while(strlen(auxLastName) >= 50)
                {
                	printf("|apellido demasiado largo. Reingrese apellido: ");
                	fflush(stdin);
                	gets(auxLastName);
                }

                strcpy(newPassenger.lastName, auxLastName);

                printf("|Ingrese precio: ");
                fflush(stdin);
                scanf("%f", &newPassenger.price);

                while( newPassenger.price <= 9000 || newPassenger.price >= 90000)
                {
                	printf("|Precio invalido. Reingrese precio: ");
                	fflush(stdin);
                	scanf("%f", &newPassenger.price);
                }

                printf("|Ingrese el fly code: ");
                fflush(stdin);
                gets(auxflycode);

                while(strlen(auxflycode) >= 11)
                {
                	printf("|fly code demasiado largo. Reingrese fly code: ");
                	fflush(stdin);
                	gets(auxflycode);
                }

                strcpy(newPassenger.flycode, auxflycode);

                listarSectores(sectores, tamSec);

                printf("|Ingrese Ttpe passenger: ");
                fflush(stdin);
                scanf("%d", &newPassenger.typePassenger);

                while( (newPassenger.typePassenger) < 1 || (newPassenger.typePassenger) > 4){
                	printf("type passenger invalido. Reingrese type passenger: ");
                	scanf("%d", &newPassenger.typePassenger);
                }

                newPassenger.isEmpty = 0;
                newPassenger.id = *pId;
                *pId = *pId + 1;
                vec[indice] = newPassenger;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}
int removePassenger(ePassenger vec[], int tam, eTypePassenger sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarPasajeros(vec, tam, sectores, tamSec);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( findPassengerById(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                printPassengers(vec[indice], sectores, tamSec);
                printf("\nConfirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar Pasajero\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int initPassengers(ePassenger vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

// Mostrar Passengers
int printPassengers(ePassenger e, eTypePassenger sectores[], int tam)
{
    int todoOk = 0;
    char descSector[20];
    if(sectores != NULL && tam > 0){
    	cargarDescripcionSector( sectores, tam, e.typePassenger, descSector);
        printf("   %3d  %20s  %20s      %9.2f       %10s       %20s\n",
        	e.id,
			e.name,
			e.lastName,
			e.price,
			e.flycode,
			descSector
          );
        todoOk = 1;
    }
    return todoOk;
}

int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}








int listarPasajeros(ePassenger vec[], int tam, eTypePassenger sectores[], int tamSec)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("                                             *** Passenger List ***\n\n");
        printf("    Id     |         Name         |     Last Name     |     Price     |     Fly code     |     Type Passenger\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                printPassengers(vec[i], sectores, tamSec);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay empleados en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int inicializarPasajeros(ePassenger vec[], int tam){
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    ePassenger impostores[] =
    {
        {0, "Juan Lorenzo", "Dellapa", 18230, "BHI9176",4,0},
        {0, "Valentina Aicha", "Navarrete", 11789, "AEP7377",2,0},
        {0, "Marcos Elias", "Cabrera", 85176, "AC2324",1,0},
        {0, "Mauro Ezequiel", "Palazzo", 85180, "AC2124",1,0},
        {0, "Roser", "Dos-Santos", 40523, "MDQ1980",3,0},
        {0, "Matilde Ester", "Campo", 66920, "MDQ8281",2,0},
        {0, "Clotilde Maria", "Morales", 90000, "EZE6482",1,0},
        {0, "Juan Francisco", "Bilbao", 50238, "CTC4683",3,0},
        {0, "Marta Rene", "Morales", 90000, "EZE6482",2,0},
        {0, "Mike Francisco", "Bilbao", 50238, "CTC4683",4,0},
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;
        }
        todoOk = 1;
    }
    return todoOk;
}

