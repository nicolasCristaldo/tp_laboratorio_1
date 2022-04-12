/*
 * utn.h
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */
/**
 * pide un numero entero, lo valida y lo pasa por puntero.
 * @param pResultado - numero ingresado y validado
 * @param mensaje - mensaje para pedir el numero
 * @param mensajeError - mensaje de error
 * @param minimo - numero mas chico en el rango de validacion
 * @param maximo - numero mas grande en el rango de validacion
 * @param reintentos - cantidad de reintentos
 * @return
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * pide un numero flotante, lo valida y lo pasa por puntero.
 * @param fResultado - numero ingresado y validado
 * @param mensaje - mensaje para pedir el numero
 * @param mensajeError - mensaje de error
 * @param minimo - numero mas chico en el rango de validacion
 * @param maximo - numero mas grande en el rango de validacion
 * @param reintentos - cantidad de reintentos
 * @return
 */
int utn_getFlotante(float* fResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


unsigned int verifica(void);

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
