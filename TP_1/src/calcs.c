/*
 * calcs.c
 *
 *  Created on: 8 abr. 2022
 *      Author: nicolas cristaldo
 */


#include <stdio.h>
#include <stdlib.h>

float makeDebitDiscount(float price)
{
	float discountPrice;

	discountPrice = price - price * 0.1;

	return discountPrice;
}

float makeCreditInterest(float price)
{
	float interestPrice;

	interestPrice = price + price * 0.25;

	return interestPrice;
}

float passPriceToBtc(float price)
{
	float btcPrice;

	btcPrice = price / 4606954.55;

	return btcPrice;
}
