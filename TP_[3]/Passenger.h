#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;

// > Mostrar
int Passenger_ImprimirDatos(Passenger* auxPassenger);

// > Constructores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

// > Destructores
void Passenger_delete(Passenger* this);

// > Setters y Getters

// >> id
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

// >> nombre
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

// >> apellido
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

// >> precio
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

// >> codigo vuelo
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

// >> tipo pasajero
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getDescripcionTipoPasajero(int typePassenger,char* desc);

// >> estado vuelo
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);
int Passenger_getDescripcionStatusFlight(int statusFlight,char* desc);

int passenger_orderById(void* a, void* b);
int passenger_orderByNombre(void* a, void* b);
int passenger_orderByApellido(void* a, void* b);
int passenger_orderByPrecio(void* a, void* b);
int passenger_orderByCode(void* a, void* b);
int passenger_orderByTipoPasajero(void* a, void* b);
int passenger_orderByEstadoVuelo(void* a, void* b);

#endif /* PASSENGER_H_ */
