/*
 * utn.h
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */
/**
 * pide un numero entero, lo valida y lo pasa por referencia.
 * @param pResultado - puntero a int, numero ingresado y validado
 * @param mensaje - puntero a char, mensaje para pedir el numero
 * @param mensajeError - puntero a char, mensaje de error
 * @param minimo - numero mas chico dentro del rango de validacion
 * @param maximo - numero mas grande dentro del rango de validacion
 * @param reintentos - cantidad de reintentos
 * @return
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * pide un numero flotante, lo valida y lo pasa por referencia.
 * @param fResultado - puntero a float, numero ingresado y validado
 * @param mensaje - puntero a char, mensaje para pedir el numero
 * @param mensajeError - puntero a char, mensaje de error
 * @param minimo - numero mas chico dentro del rango de validacion.
 * @param maximo - numero mas grande dentro del rango de validacion.
 * @param reintentos - cantidad de reintentos
 * @return
 */
int utn_getFlotante(float* fResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
