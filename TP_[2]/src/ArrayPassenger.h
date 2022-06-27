/*
 * ArrayPassenger.h
 *
 *  Created on: 23 abr. 2022
 *      Author: nicolas cristaldo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#endif /* ARRAYPASSENGER_H_ */

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

typedef struct
{
	int idType;
	char description[20];
}typePassenger;

typedef struct
{
	int status;
	char description[20];
}statusFlight;

/**
 * pone la bandera isEmpty en TRUE para indicar que todas las posiciones estan vacias
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @return
 */
int initPassengers(Passenger* list, int len);
/**
 * agrega en una posicion libre del array los datos que se le pasan como parametro
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param name array de caracteres, nombre del pasajero
 * @param lastName array de caracteres, apellido del pasajero
 * @param price variable de tipo float, precio de vuelo
 * @param typePassenger variable de tipo int, tipo del pasajero
 * @param flycode array de caracteres, codigo alfanumerico del pasajero
 * @param status estado de vuelo
 * @param pos posicion del array donde se guardaron los datos, si no la encuentra, retorna -1
 * @param idActual, id maximo actual
 * @return
 */
int addPassenger(Passenger* list,int len,char* name,char* lastName,float price,int typePassenger,char* flycode, int status,int* pos,int* idActual);
/**
 * llama a las funciones que piden los datos del pasajero
 * @param listlist puntero a array de pasajeros
 * @param len len tamaño del array
 * @param idActual, id maximo actual
 * @param pos puntero a int, si hay posiciones disponibles retorna la ultima posicion donde se guardaron datos, si no hay retorna -1
 * @return
 */
int loadPassenger(Passenger* list, int len,int* pos,int* idActual);
/**
 * busca un pasajero recibiendo su id
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param id numero de id a verificar
 * @return retorna la posicion del array si se encuentra, retorna -1 si hubo un error
 */
int findPassengerById(Passenger* list, int len,int id);
/**
 * elimina de forma logica un pasajero segun su id
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param id id del pasajero
 * @return
 */
int removePassenger(Passenger* list, int len, int id);
/**
 * pide al usuario un id, si se encuentra disponible elimina de forma logica a quien tenga ese id
 * @param list puntero a array de pasajeros
 * @param types puntero a array de tipos de pasajero
 * @param status puntero a array de estados de pasajero
 * @param len tamaño del array
 * @param actualId numero de id mas grande hasta el momento
 * @param pos puntero a int, retorna 0 para señalar que hay un espacio libre
 * @return
 */
int deletePassenger(Passenger* list, typePassenger* types, statusFlight* status,int len, int actualId,int* pos);
/**
 * pide el id de un pasajero y modifica el campo deseado por el usuario
 * @param list puntero a array de pasajeros
 * @param types puntero a array de tipos de pasajero
 * @param status puntero a array de estados de pasajero
 * @param len tamaño del array
 * @param actualId numero de id mas grande hasta el momento
 * @return
 */
int modifyPassenger(Passenger* list,typePassenger* types, statusFlight* status, int len, int actualId);
/**
 * ordena el array de forma creciente o decreciente teniendo en cuenta el nombre
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param order variable de tipo int, si es 1 se ordenara el array de forma creciente, si es 0, decreciente
 * @return
 */
int sortPassengers(Passenger* list, int len, int order);
/**
 * imprime el array de pasajeros
 * @param list puntero a array de pasajeros
 * @param types puntero a array de tipos de pasajero
 * @param status puntero a array de estados
 * @param length tamaño del array
 * @return
 */
int printPassengers(Passenger* list, typePassenger* types,statusFlight* status, int length);
/**
 * ordena el array de forma creciente o decreciente teniendo en cuenta el codigo
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param order variable de tipo int, si es 1 se ordenara el array de forma creciente, si es 0, decreciente
 * @return
 */
int sortPassengersByCode(Passenger* list, int len, int order);
/**
 * informa listas ordenadas o datos de precios segun el usuario lo desee
 * @param list  puntero a array de pasajeros
 * @param len tamaño del array
 * @param types puntero a array de tipos de pasajero
 * @param status puntero a array de estados
 * @return
 */
int inform(Passenger* list, int len, typePassenger* types, statusFlight* status);
/**
 * busca una posicion libre en el array
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @return retorna la posicion libre, si no la encuentra retorna -1
 */
int findFreePosition(Passenger* list, int len);

