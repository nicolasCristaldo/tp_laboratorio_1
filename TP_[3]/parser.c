#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include <string.h>

/********************* LECTURA ****************************/
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int r;
	Passenger *newPassenger = NULL;
	char idStr[2000],nameStr[2000],lastNameStr[2000],priceStr[2000],flyCodeStr[2000],typeStr[2000],statusStr[2000];
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,lastNameStr,priceStr,flyCodeStr,typeStr,statusStr);
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,lastNameStr,priceStr,flyCodeStr,typeStr,
					statusStr);
			if(r == 7)
			{
				newPassenger = Passenger_newParametrosTxt(idStr, nameStr, typeStr, lastNameStr, priceStr, flyCodeStr,statusStr);

				if(newPassenger != NULL)
				{
					ret = 0;
					ll_add(pArrayListPassenger, newPassenger);
				}
				else
				{
					printf("No se cargó el pasajero.\n");
				}
			}
		}while(feof(pFile) == 0);
	}
    return ret;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int qty;
	Passenger passengerAux;
	Passenger* pPassenger;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			qty = fread(&passengerAux,sizeof(Passenger),1,pFile);
			if(qty == 1)
			{
				pPassenger = Passenger_newParametros(passengerAux.id, passengerAux.nombre,passengerAux.tipoPasajero,
						passengerAux.apellido, passengerAux.precio, passengerAux.codigoVuelo,passengerAux.estadoVuelo);

				if(pPassenger != NULL)
				{
					ret = 0;
					ll_add(pArrayListPassenger, pPassenger);
				}
			}
		}while(feof(pFile) == 0);
	}
	return ret;
}
/********************* ESCRITURA ****************************/
int parser_WritePassengerText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int i = 0;
	Passenger* pPassengerAux;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pFile,"id,name,lastName,price,flyCode,typePassenger,statusFlyght\n");
		do
		{
			pPassengerAux = ll_get(pArrayListPassenger,i);
			fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n",(*(pPassengerAux)).id,(*(pPassengerAux)).nombre,(*(pPassengerAux)).apellido,
					(*(pPassengerAux)).precio,(*(pPassengerAux)).codigoVuelo,(*(pPassengerAux)).tipoPasajero,(*(pPassengerAux)).estadoVuelo);
			i++;
		}while(i < ll_len(pArrayListPassenger) && feof(pFile) == 0);
		ret = 0;
	}
	return ret;
}

int parser_WritePassengerBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int i = 0;
	Passenger* pPassengerAux;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			pPassengerAux = ll_get(pArrayListPassenger,i);
			fwrite(pPassengerAux,sizeof(Passenger),1,pFile);
			i++;
		}while(i < ll_len(pArrayListPassenger));
		ret = 0;
	}
	return ret;
}
