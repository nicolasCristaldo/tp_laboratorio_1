/********************* LECTURA ****************************/
/**
 * \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * @param pFile puntero al archivo donde se parsearan los datos.
 * @param pArrayListPassenger linkedList, lista donde se guardaran los pasajeros.
 * @return retorna 0 si se pudo cargar el pasajero, -1 si hubo un error.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
/**
 * \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 * @param pFile puntero al archivo donde se parsearan los datos.
 * @param pArrayListPassenger linkedList, lista donde se guardaran los pasajeros.
 * @return retorna 0 si se pudo cargar el pasajero, -1 si hubo un error.
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/********************* ESCRITURA ****************************/
/**
 * \brief escribe en el archivo data.csv los pasajeros cargados en la linkedList.
 * @param pFile puntero al archivo donde se escribiran los pasajeros.
 * @param pArrayListPassenger linkedList, lista de donde se sacan los pasajeros.
 * @return retorna 0 si se pudo cargar el pasajero, -1 si hubo un error.
 */
int parser_WritePassengerText(FILE* pFile , LinkedList* pArrayListPassenger);
/**
 * \brief escribe en un archivo .bin los pasajeros cargados en la linkedList.
 * @param pFile puntero al archivo donde se escribiran los pasajeros.
 * @param pArrayListPassenger linkedList, lista de donde se sacan los pasajeros.
 * @return retorna 0 si se pudo cargar el pasajero, -1 si hubo un error.
 */
int parser_WritePassengerBinary(FILE* pFile , LinkedList* pArrayListPassenger);
