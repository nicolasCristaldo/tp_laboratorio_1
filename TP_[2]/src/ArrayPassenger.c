/*
 * ArrayPassenger.c
 *
 *  Created on: 23 abr. 2022
 *      Author: nicolas cristaldo
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include <string.h>
#include "arraysChar.h"

static int addName(char* name, int len, char* question);
static int addPrice(float* price);
static int addType(int* type);
static int addFlyCode(char* flyCode, int len);

static int addName(char* name, int len, char* question)
{
	int ret = -1;
	char aux[4000];

	if(name != NULL)
	{
		ret = 0;
		do
		{
			strncpy(aux,"",sizeof(aux));
			printf(question);
			fflush(stdin);
			gets(aux);
		}while(esLetraConEspacio(aux) == 0 || strlen(aux) >= len);
		strncpy(name,aux,len);
	}

	return ret;
}

static int addPrice(float* price)
{
	int ret = -1;

	if(price != NULL)
	{
		ret = 0;
		do
		{
			printf("\nIngrese precio: ");
			scanf("%f",price);
		}while(*price < 10000);
	}
	return ret;
}

static int addType(int* type)
{
	int ret = -1;

	if(type != NULL)
	{
		ret = 0;
		do
		{
			printf("\nIngrese el tipo de pasajero(1-Menor, 2-Adulto, 3-Jubilado): ");
			scanf("%d",type);
		}while(*type < 1 || *type > 3);
	}
	return ret;
}

static int addFlyCode(char* flyCode, int len)
{
	int ret = -1;
	char aux[4000];
	int res;

	if(flyCode != NULL && len > 0)
	{
		ret = 0;
		do
		{
			strncpy(aux,"",sizeof(aux));
			printf("\nIngrese codigo de vuelo: ");
			fflush(stdin);
			gets(aux);
			esAlfanumerico(&res, aux, sizeof(aux));
		}while(res == 0 || strlen(aux) >= len);
		strncpy(flyCode,aux,len);
	}
	return ret;
}
int initPassengers(Passenger* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		ret = 0;

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}

	}
	return ret;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && (typePassenger >= 1 || typePassenger <= 3) && flycode > 0)
	{
		ret = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].isEmpty = 0;
				list[i].id = id;
				strncpy(list[i].name,name,sizeof(list[i].name));
				strncpy(list[i].lastName,lastName,sizeof(list[i].lastName));
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strncpy(list[i].flyCode,flycode,sizeof(list[i].flyCode));
				break;
			}
		}

		if(i == len)
		{
			printf("\nNo hay espacios disponibles.\n");
		}
	}
	return ret;
}

int loadPassenger(Passenger* list, int len, int* actualId)
{
	int ret = -1;
	char res;
	int id = *actualId;
	char name[51];
	char lastName[51];
	float price;
	int type;
	char flyCode[10];

	if(list != NULL && len > 0)
	{
		ret = 0;
		do
		{
			strncpy(name,"",sizeof(name));
			addName(name, sizeof(name), "\nIngrese su nombre: ");
			strncpy(lastName,"",sizeof(lastName));
			addName(lastName, sizeof(lastName), "\nIngrese su apellido: ");
			addPrice(&price);
			addType(&type);
			strncpy(flyCode,"",sizeof(flyCode));
			addFlyCode(flyCode, sizeof(flyCode));

			addPassenger(list, len, id, name, lastName, price, type, flyCode);

			id++;
			printf("desea continuar? s/n ");
			fflush(stdin);
			scanf("%c", &res);
		}while(res == 's');
		*actualId = id;
	}

	return ret;
}
