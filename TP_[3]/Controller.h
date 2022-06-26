
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);  	// | 1 |0
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);	// | 2 |0

int controller_addPassenger(LinkedList* pArrayListPassenger);					// | 3 |0
int controller_editPassenger(LinkedList* pArrayListPassenger);					// | 4 |0
int controller_removePassenger(LinkedList* pArrayListPassenger);				// | 5 |0
int controller_ListPassenger(LinkedList* pArrayListPassenger);					// | 6 |0
int controller_sortPassenger(LinkedList* pArrayListPassenger);					// | 7 |0

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);		// | 8 |0
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);		// | 9 |0

// >>> Controller Archivo ID
int controller_passengerId(char* path, LinkedList* list);
int controller_BuscarId(LinkedList* pArrayListPassenger, int id);
