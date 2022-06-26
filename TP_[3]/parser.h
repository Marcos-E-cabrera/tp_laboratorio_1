
// >>> Archivo.txt
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

// >>> Archivo.bin
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

// >>> Parser Archivo ID
int parser_passengerId(FILE* pFile, LinkedList* list);
int buscarMayorId(LinkedList* this, int*id);
