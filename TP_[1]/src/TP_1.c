/*******************************************************************
*Programa: TP 1
*
*Objetivo:
*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
*para ofrecerlos a sus clientes.
*Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
*El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
*
*abril 2022
*Autor: Nicolas Cristaldo
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "calcs.h"
#include "utn.h"
#include "menus.h"

// valores de la carga forzada
#define CF_KMS 7090
#define CF_AERLS 162965
#define CF_LATAM 159339

int main(void) {
	setbuf(stdout, NULL);

	int selectedNum;
	float kilometres = 0;
	float aerlsPrice = 0;
	float latamPrice = 0;
	float aerlsPriceDisc;
	float latamPriceDisc;
	float aerlsInterest;
	float latamInterest;
	float aerlsPriceBtc;
	float latamPriceBtc;
	float aerlsKmPrice;
	float latamKmPrice;
	float priceDif;
	int pricesFlag = 0;
	int calcPricesFlag = 0;
	int kmFlag = 0;

	do
	{
		principalMenu(kilometres, aerlsPrice, latamPrice);
		utn_getNumero(&selectedNum,": ","\nError",1,6,3);

		switch(selectedNum)
		{
			case 1:
				utn_getFlotante(&kilometres,"\nIngrese los kilometros: ","\nError",20,14000,3);
				kmFlag = 1;
				break;
			case 2:
				pricesSubmenu(&aerlsPrice, &latamPrice);
				pricesFlag = 1;
				break;
			case 3:
				if(pricesFlag == 1 && kmFlag == 1)
				{
					calculateAll(&aerlsPriceDisc, &aerlsInterest, &aerlsPriceBtc, &aerlsKmPrice, aerlsPrice, kilometres);
					calculateAll(&latamPriceDisc, &latamInterest, &latamPriceBtc, &latamKmPrice, latamPrice, kilometres);
					subtractPrices(&priceDif, latamPrice, aerlsPrice);
					calcPricesFlag = 1;
				}
				else
				{
					printf("\nError, verifique los precios o kilometros ingresados.\n");
				}
				break;
			case 4:
				if(calcPricesFlag == 1)
				{
					seeKms(kilometres);
					pricesResults("aerolineas", aerlsPrice, aerlsPriceDisc, aerlsInterest, aerlsPriceBtc, aerlsKmPrice);
					pricesResults("latam", latamPrice, latamPriceDisc, latamInterest, latamPriceBtc, latamKmPrice);
					seeDiference(priceDif);
				}
				else
				{
					printf("\nError, no se calcularon los precios.\n");
				}
				break;
			case 5:
				calculateAll(&aerlsPriceDisc, &aerlsInterest, &aerlsPriceBtc, &aerlsKmPrice, CF_AERLS, CF_KMS);
				calculateAll(&latamPriceDisc, &latamInterest, &latamPriceBtc, &latamKmPrice, CF_LATAM, CF_KMS);
				subtractPrices(&priceDif, 159339, 162965);
				seeKms(CF_KMS);
				pricesResults("aerolineas", CF_AERLS, aerlsPriceDisc, aerlsInterest, aerlsPriceBtc, aerlsKmPrice);
				pricesResults("latam", CF_LATAM, latamPriceDisc, latamInterest, latamPriceBtc, latamKmPrice);
				seeDiference(priceDif);
				break;
			case 6:
				break;
			default:
				printf("\nError");
		}

	}while(selectedNum != 6);

	return EXIT_SUCCESS;
}

