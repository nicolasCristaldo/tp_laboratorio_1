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

int utn_getFlotante(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
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
		*pResultado = num;
	}

	return ret;
}

int validar_respuestaChar(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int ret = -1;
	char caracter;

	do
	{
		printf(mensaje);
		fflush(stdin); // __fpurge(stdin)
		scanf("%s",&caracter);

		if(caracter == 's' || caracter == 'n')
		{
			*pResultado = caracter;
			ret = 0;
			break;
		}

		printf(mensajeError);
		reintentos--;

	}while(reintentos >= 0);

	if(reintentos < 0)
	{
		*pResultado = 'n';
	}

	return ret;
}
