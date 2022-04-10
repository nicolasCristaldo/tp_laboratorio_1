/*
 * utn.h
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */
/**
 * pide un numero entero, lo valida y lo pasa por puntero.
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * pide un numero flotante, lo valida y lo pasa por puntero.
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return
 */
int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * valida respuestas de tipo char (s/n)
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param reintentos
 * @return
 */
int validar_respuestaChar(char* pResultado,char* mensaje,char* mensajeError,int reintentos);

unsigned int verifica(void);

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
