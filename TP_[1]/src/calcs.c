/*
 * calcs.c
 *
 *  Created on: 8 abr. 2022
 *      Author: nicolas cristaldo
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calcs.h"

int discountPrice(float* result, float price)
{
	int ret = -1;

	if(result != NULL)
	{
		ret = 0;
		*result = price - price * 0.1;
	}

	return ret;
}

int creditInterest(float* result, float price)
{
	int ret = -1;

	if(result != NULL)
	{
		ret = 0;
		*result = price + price * 0.25;
	}

	return ret;
}

int passToBtc(float* result, float price)
{
	int ret = -1;

	if(result != NULL)
	{
		ret = 0;
		*result = price / 4464696.76;
	}

	return ret;
}

int kmPrice(float* result, float price, float kms)
{
	int ret = -1;

	if(result != NULL)
	{
		ret = 0;
		*result = price / kms;
	}

	return ret;
}

int subtractPrices(float* result, float price1, float price2)
{
	int ret = -1;

	if(result != NULL)
	{
		ret = 0;
		*result = price1 - price2;
	}

	return ret;
}

int calculateAll(float* discount,float* interest,float* btc,float* kms, float price,float km)
{
	int ret = -1;
	/*float disc = *discount;
	float intrst = *interest;
	float bitcoin = *btc;
	float kilometres = *kms;*/

	if(discount != NULL && interest != 	NULL && btc != NULL && kms != NULL)
	{
		ret = 0;
		discountPrice(&*discount, price);
		creditInterest(&*interest, price);
		passToBtc(&*btc, price);
		kmPrice(&*kms, price, km);

		/*discount = disc;
		*interest = intrst;
		*btc = bitcoin;
		*kms = kilometres;*/
	}
	return ret;
}

