/*
 * arraysChar.h
 *
 *  Created on: 26 abr. 2022
 *      Author: nico
 */

#ifndef ARRAYSCHAR_H_
#define ARRAYSCHAR_H_
/**
 * valida un numero telefonico
 * @param resultado
 * @param tel
 * @param cant
 * @return
 */
int esTelefono(int* resultado, char tel[], int cant);
/**
 * valida una cadena alfanumerica
 * @param resultado
 * @param alfanum
 * @param cant
 * @return
 */
int esAlfanumerico(int* resultado, char alfanum[], int cant);
/**
 * valida que la cadena son solo letras y espacio en el medio
 * @param pResultado cadena es un puntero al espacio de memoria donde se dejara el
resultado de la funcion
 * @return Retorna 1 si todo ok, 0, SI ES ERROR.
 */
int esLetraConEspacio(char *pResultado);
/**
* \brief valida que la cadena son solo letras
* \param cadena es un puntero al espacio de memoria donde se dejara el
resultado de la funcion
* return Retorna 1 si todo ok, 0, SI ES ERROR.
*/
int esSoloLetra(char *pResultado);
/**
 * valida que la cadena solo sean numeros
 * @param pResultado
 * @return
 */
int esSoloNumero(char *pResultado);


#endif /* ARRAYSCHAR_H_ */
