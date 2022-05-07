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
 * @param id variable de int, id del pasajero
 * @param name array de caracteres, nombre del pasajero
 * @param lastName array de caracteres, apellido del pasajero
 * @param price variable de tipo float, precio de vuelo
 * @param typePassenger variable de tipo int, tipo del pasajero
 * @param flycode array de caracteres, codigo alfanumerico del pasajero
 * @return
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * llama a las funciones que piden los datos del pasajero
 * @param listlist puntero a array de pasajeros
 * @param len len tamaño del array
 * @param actualId numero de id mas grande hasta el momento
 * @return
 */
int loadPassenger(Passenger* list, int len, int* actualId);
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
 * @param len tamaño del array
 * @param actualId numero de id mas grande hasta el momento
 * @return
 */
int deletePassenger(Passenger* list, int len, int actualId);
/**
 * pide el id de un pasajero y modifica el campo deseado por el usuario
 * @param list puntero a array de pasajeros
 * @param len tamaño del array
 * @param actualId numero de id mas grande hasta el momento
 * @return
 */
int modifyPassenger(Passenger* list, int len, int actualId);
