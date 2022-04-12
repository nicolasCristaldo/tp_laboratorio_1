/*
 * menus.h
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */

/**
 * muestra el menu principal del programa
 * @param km - kilometros totales
 * @param price1 - precio de aerolineas
 * @param price2 - precio de latam
 */
void principalMenu(float km,float price1,float price2);

/**
 * muestra un submenu para ingresar los precios de las aerolineas.
 * @param price1 - precio de aerolineas
 * @param price2 - precio de latam
 */
int pricesSubmenu(float* price1, float* price2);

/**
 * muestra los resultados de la una aerolinea
 * @param aerolinea - nombre de la aerolinea
 * @param deb - precio con descuento del 10%
 * @param cred - precio con interes del 25%
 * @param btc - precio pasado a bitcoin
 * @param kms - precio por kilometro
 */
void pricesResults(char* aerolinea, float deb, float cred, float btc, float kms);

/**
 * muestra la diferencia de precios.
 * @param diferencia - diferencia de precio entre las dos aerolineas
 */
void mosrarDiferencia(float diferencia);

/**
 * muestra los kms ingresados
 * @param kilometres - kilometros de viaje
 */
void seeKms(float kilometres);

#ifndef MENUS_H_
#define MENUS_H_



#endif /* MENUS_H_ */
