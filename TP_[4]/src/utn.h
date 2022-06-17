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
/**
 * pide un nombre al usuario y lo valida
 * @param cResultado puntero a array de caracteres
 * @param mensaje puntero a char, mensaje para pedir el nombre
 * @param mensajeError puntero a char, mensaje de error
 * @param minimo cantidad minima de caracteres
 * @param maximo cantidad maxima de caracteres
 * @param reintentos cantidad de reintentos
 * @return
 */
int utn_getNombre(char* cResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/**
 * pide un valor alfanumerico al usuario y lo valida
 * @param cResultado puntero a array de caracteres
 * @param mensaje puntero a char, mensaje para pedir el alfanumerico
 * @param mensajeError puntero a char, mensaje de error
 * @param minimo cantidad minima de caracteres
 * @param maximo cantidad maxima de caracteres
 * @param reintentos cantidad de reintentos
 * @return
 */
int utn_getAlfanumerico(char* cResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/**
 * pide una letra (s o n) al usuario
 * @param mensaje puntero a char, mensaje para pedir la respuesta
 * @param mensajeError puntero a char, mensaje de error
 * @param reintentos cantidad de reintentos
 * @return retorna 1 si la respuesta fue s, 0 si fue n, -1 si hubo un error o no se ingreso una respuesta valida
 */
int utn_confirmar(char* mensaje,char* mensajeError,int reintentos);
/**
 * pide un telefono y lo valida
 * @param cResultado puntero a array de caracteres
 * @param mensaje puntero a char, mensaje para pedir el telefono
 * @param mensajeError puntero a char, mensaje de error
 * @param minimo cantidad minima de caracteres
 * @param maximo cantidad maxima de caracteres
 * @param reintentos cantidad de reintentos
 * @return
 */
int utn_getTelefono(char* cResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/***************** VALIDACIONES ***********************/

/**
 * valida si una cadena de texto es una respuesta s o n
 * @param cadena array de caracteres
 * @return
 */
int esRespuestaValida(char* cadena);
/**
 *valida que la cadena de texto sea un nombre
 * @param cadena cadena de array de caracteres
 * @return
 */
int esNombre(char* cadena);
/**
 *valida que la cadena de texto sea numerica
 * @param cadena cadena de array de caracteres
 * @return
 */
int esNumerica(char* cadena);
/**
 *valida que la cadena sea un numero flotante
 * @param cadena cadena de array de caracteres
 * @return
 */
int esFlotante(char* cadena);
/**
 *valida que la cadena sea alfanumerica
 * @param cadena cadena de array de caracteres
 * @return
 */
int esAlfanumerica(char* cadena);
/**
 *valida que la cadena sea un numero telefonico
 * @param cadena cadena de array de caracteres
 * @return
 */
int esTel(char* cadena);
/**
 * recibe una cadena, su primer caracter lo pone en mayuscula y el resto minuscula.
 * @param name char* cadena a modificar.
 * @return
 */
int arreglarNombre(char* name);
/**
 * recibe una cadena y pone en mayuscula todos sus caracteres
 * @param cadena char* cadena a modificar.
 * @return
 */
int pasarAMayuscula(char* cadena);

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
