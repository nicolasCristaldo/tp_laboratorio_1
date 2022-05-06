/*
 * utn.c
 *
 *  Created on: 9 abr. 2022
 *      Author: nicolas cristaldo
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int ret = -1;
	int num;

	do
	{
		printf(mensaje);
		if(scanf("%d",&num) == 1)
		{
			if(num <= maximo && num >= minimo)
				{
					break;
				}
		}

		fflush(stdin); // __fpurge(stdin)

		reintentos--;

		printf(mensajeError);
	}while(reintentos >= 0);

	if(reintentos >= 0)
	{
		ret = 0;
		*pResultado = num;
	}

	return ret;
}

int utn_getFlotante(float* fResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int ret = -1;
	float num;

	do
	{
		printf(mensaje);
		if(scanf("%f",&num) == 1)
		{
			if(num <= maximo && num >= minimo)
				{
					break;
				}
		}

		fflush(stdin); // __fpurge(stdin)

		reintentos--;

		printf(mensajeError);
	}while(reintentos >= 0);

	if(reintentos >= 0)
	{
		ret = 0;
		*fResultado = num;
	}

	return ret;
}
