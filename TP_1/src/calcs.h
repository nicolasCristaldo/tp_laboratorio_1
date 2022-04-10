/*
 * calcs.h
 *
 *  Created on: 8 abr. 2022
 *      Author: nicolas cristaldo
 */

/**
 * hace un descuento del 10% a un precio y lo pasa por puntero.
 * @param result
 * @param price
 * @return
 */
int discountPrice(float* result, float price);

/**
 * incrementa en 25% un precio y lo pasa por puntero.
 * @param result
 * @param price
 * @return
 */
int creditInterest(float* result, float price);

/**
 * pasa a bitcoin un precio y lo pasa por puntero
 * @param result
 * @param price
 * @return
 */
int passToBtc(float* result, float price);

/**
 * calcula el precio por cada kilometro de viaje.
 * @param result
 * @param price
 * @param kms
 * @return
 */
int kmPrice(float* result, float price, float kms);

/**
 * resta dos precios y pasa el resultado por puntero.
 * @param result
 * @param price1
 * @param price2
 * @return
 */
int subtractPrices(float* result, float price1, float price2);

/**
 * hace todos los calculos de la libreria calcs.h (excepto substractPrice) y los pasa por puntero.
 * @param discount
 * @param interest
 * @param btc
 * @param kms
 * @param price
 * @param km
 * @return
 */
int calculateAll(float* discount,float* interest,float* btc,float* kms, float price,float km);

#ifndef CALCS_H_
#define CALCS_H_



#endif /* CALCS_H_ */
