/*
 * menus.h
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */

/**
 * muestra el menu principal del programa
 * @param km
 * @param price1
 * @param price2
 */
void principalMenu(float km,float price1,float price2);

/**
 * muestra un submenu para ingresar los precios de la aerolinea que se desee.
 * @param price1
 * @param price2
 */
void pricesSubmenu(float* price1, float* price2);

/**
 * muestra los resultados de la una aerolinea
 * @param aerolinea
 * @param deb
 * @param cred
 * @param btc
 * @param kms
 */
void pricesResults(char* aerolinea, float deb, float cred, float btc, float kms);

/**
 * muestra la diferencia de precios.
 * @param diferencia
 */
void mosrarDiferencia(float diferencia);

/**
 * muestra los kms ingresados
 * @param kilometres
 */
void seeKms(float kilometres);

#ifndef MENUS_H_
#define MENUS_H_



#endif /* MENUS_H_ */
