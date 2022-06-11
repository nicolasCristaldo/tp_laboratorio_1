/**
 * \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * @param path char*, archivo donde se sacaran los pasajeros.
 * @param pArrayListPassenger linkedList*, lista donde se guardaran los pasajeros.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/**
 * \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * @param path char*, archivo donde se sacaran los pasajeros.
 * @param pArrayListPassenger  linkedList*, lista donde se guardaran los pasajeros.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/**
 * \brief Alta de pasajero
 * @param pArrayListPassenger linkedList*, lista donde se guardará el pasajero dado de alta.
 * @return retorna 0 si se pudo guardar el pasajero en la linkedList, -1 si no.
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);
/**
 * \brief Modificar un datoo de un pasajero.
 * @param pArrayListPassenger linkedList*, lista de donde se sacara el pasajero a modificar.
 * @return retorna 0 si se pudo guardar los cambios del pasajero, -1 si no.
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);
/**
 *	\brief Baja de pasajero.
 * @param pArrayListPassenger linkedList*, lista de donde se sacara el pasajero a eliminar.
 * @return retorna 0 si se pudo eliminar el pasajero, -1 si no.
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);
/**
 * \brief Listar pasajeros.
 * @param pArrayListPassenger linkedList*, lista de donde se sacaran los pasajeros a mostrar.
 * @return retorna 0 si se pudo mostrar la lista, -1 si no.
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);
/**
 * \brief Ordenar pasajeros.
 * @param pArrayListPassenger linkedList*, lista de donde se ordenaran los pasajeros.
 * @return retorna 0 si se ordenaron los pasajeros, -1 si no.
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);
/**
 *\brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * @param path char*, archivo donde se guardaran los pasajeros.
 * @param pArrayListPassenger linkedList*, lista donde se sacaran los pasajeros.
 * @return retorna 0 si todo sale bien, -1 si no.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
/**
 *\brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * @param path char*, archivo donde se guardaran los pasajeros.
 * @param pArrayListPassenger linkedList*, lista donde se sacaran los pasajeros.
 * @return retorna 0 si todo sale bien, -1 si no.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/**
 * \brief busca un pasajero en la linkedList por su id.
 * @param pArrayListPassenger linkedList*, lista donde se busca al pasajero.
 * @param id int, id del pasajero a buscar.
 * @return si encuentra el id retorna el indice del pasajero en la linkedList, si no lo encuentra retorna -1;
 */
int controller_FindById(LinkedList* pArrayListPassenger, int id);
/**
 * \brief busca el id maximo dentro de la linkedList.
 * @param pArrayListPassenger linkedList*, lista donde se buscara el id mas alto.
 * @return en caso de error retorna -1, retorna 0 si no hay pasajeros cargados sino retorna el id mas alto.
 */
int controller_IdMax(LinkedList* pArrayListPassenger);
/**
 *\brief modifica los ids de los pasajeros.
 * @param pArrayListPassenger linkedList*, lista donde se sacan los pasajeros.
 * @param len int, numero maximo de pasajeros a ser modificados.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int controller_modifyIdPassenger(LinkedList* pArrayListPassenger, int len);


