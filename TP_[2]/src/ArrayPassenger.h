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
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flycode
 * @return
 */
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * llama a las funciones que piden los datos del pasajero
 * @param listlist puntero a array de pasajeros
 * @param len len tamaño del array
 * @param actualId
 * @return
 */
int loadPassenger(Passenger* list, int len, int* actualId);
