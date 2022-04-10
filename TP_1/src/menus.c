/*
 * menus.c
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcs.h"
#include "utn.h"


void principalMenu(float km,float price1,float price2)
{
		printf("\n1. Ingresar Kilómetros: (km = %.0f) \n"
			   "\n2. Ingresar Precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f) \n"
			   "\n3. Calcular todos los costos"
		       "\n   a) Tarjeta de débito: (descuento 10)"
			   "\n   b) Tarjeta de crédito: (interés 25)"
			   "\n   c) Bitcoin: (1BTC -> 4606954.55 Pesos Argentinos)"
			   "\n   d) Mostrar precio por km: (precio unitario)"
			   "\n   e) Mostrar diferencia de precio ingresada: (Latam - Aerolíneas) \n"
			   "\n4. Informar Resultados \n"
			   "\n5. Carga forzada de datos "
			   "\n6. Salir ",km,price1,price2);
}

void pricesSubmenu(float* price1, float* price2)
{
	int num;
	float aerolineasPrice;
	float latamPrice;
	char res;

	do
	{
		utn_getNumero(&num, "\nIngresar precios:\nIngrese 1 para aerolineas\nIngrese 2 para latam ", "\nError", 1, 2, 3);

		if(num == 1)
		{
			utn_getFlotante(&aerolineasPrice, "\nPrecio vuelo aerolineas: ", "\nError", 15000, 530000, 3);
			*price1 = aerolineasPrice;
		}
		else
		{
			utn_getFlotante(&latamPrice, "\nPrecio vuelo latam: ", "\nError", 12000, 600000, 3);
			*price2 = latamPrice;
		}

		validar_respuestaChar(&res,"\n¿Desea continuar ingresando precios? s/n ","\nError",3);
	}while(res == 's');
}

void pricesResults(char* aerolinea, float deb, float cred, float btc, float kms)
{
	printf("\n Precio %s: "
		    "\n   a) Precio con tarjeta de débito: $%.2f"
		    "\n   b) Precio con tarjeta de crédito: $%.2f"
			"\n   c) Precio pagando con bitcoin: %.4f BTC"
			"\n   d) Precio unitario: $%.2f \n",aerolinea,deb,cred,btc,kms);

}

void mosrarDiferencia(float diferencia)
{
	printf("\n   La diferencia de precio es: $%.2f \n",diferencia);
}

void seeKms(float kilometres)
{
	printf("\n   Kms Ingresados: $%.0f \n",kilometres);
}
