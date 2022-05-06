/*
 * calcs.h
 *
 *  Created on: 8 abr. 2022
 *      Author: nicolas cristaldo
 */

/**
 * hace un descuento del 10% a un precio y lo pasa por referencia.
 * @param result - puntero a float, muestra el resultado del descuento
 * @param price - precio sin descuento
 * @return
 */
int discountPrice(float* result, float price);

/**
 * incrementa en 25% un precio y lo pasa por referencia.
 * @param result - puntero a float, resultado del aumento
 * @param price - precio sin aumento
 * @return
 */
int creditInterest(float* result, float price);

/**
 * pasa a bitcoin un precio y lo pasa por referencia
 * @param result - puntero a float, precio pasado a bitcoin
 * @param price - precio en pesos
 * @return
 */
int passToBtc(float* result, float price);

/**
 * calcula el precio por cada kilometro de viaje.
 * @param result - puntero a float, precio por kilometro
 * @param price - precio original
 * @param kms - kilometros de vuelo
 * @return
 */
int kmPrice(float* result, float price, float kms);

/**
 * resta dos precios y pasa el resultado por referencia.
 * @param result - puntero a float, diferencia de precio
 * @param price1 - precio de latam
 * @param price2 - precio de aerolineas
 * @return
 */
int subtractPrices(float* result, float price1, float price2);

/**
 * llama a todas las funciones de la libreria calcs.h (excepto substractPrice) y los pasa por referencia.
 * @param discount - puntero a float, precio con descuento del 10%
 * @param interest - puntero a float, precio con interes del 25%
 * @param btc - puntero a float, precio pasado a bitcoin
 * @param kms - puntero a float, precio por kilometro
 * @param price - precio original
 * @param km - kilometros de vuelo
 * @return
 */
int calculateAll(float* discount,float* interest,float* btc,float* kms, float price,float km);

#ifndef CALCS_H_
#define CALCS_H_



#endif /* CALCS_H_ */
