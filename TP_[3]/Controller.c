#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"
#include <string.h>

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
    FILE *pFile;
    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pFile = fopen(path,"r");
    	if(pFile == NULL)
    	{
    		printf("\nError al abrir el archivo.\n");
    	}
    	else
    	{
    		if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0)
    		{
    			ret = 0;
    		}
    		fclose(pFile);
    	}
    }
    return ret;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE *pFile;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile == NULL)
		{
			printf("\nError al abrir el archivo.\n");
		}
		else
		{
			if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
			{
				ret = 0;
			}
			fclose(pFile);
		}

	}
	return ret;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	if(pArrayListPassenger != NULL)
	{
		ret = Passenger_addPassenger(pArrayListPassenger);
	}
    return ret;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int ret = -1;
    if(pArrayListPassenger != NULL)
    {
    	ret = Passenger_editPassenger(pArrayListPassenger);
    }

    return ret;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	if(pArrayListPassenger != NULL)
	{
		ret = passenger_removePassenger(pArrayListPassenger);
	}

    return ret;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int ret = -1;
    int i;
    Passenger* passengerAux = NULL;
    if(pArrayListPassenger != NULL)
    {
    	printf("\n************************************************************************************************************************");
    	printf("\n%-10s %-20s %-20s %-15s %-15s %-20s %-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO","TIPO","ESTADO");
    	for(i = 0; i < ll_len(pArrayListPassenger) ; i++)
    	{
    		passengerAux = ll_get(pArrayListPassenger, i);
    		Passenger_PrintPassenger(passengerAux);
    	}
    	printf("\n************************************************************************************************************************\n");
    	ret = 0;
    }
    return ret;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
   int ret = -1;
   int order;
   int (*pFuncion)(void*, void*) = NULL;
   if(pArrayListPassenger != NULL)
   {
	   if(utn_getNumero(&order, "\nOrdenar pasajeros:\n1 - Por apellido y nombre.\n2 - Por codigo y precio.\n", "\nError.\n", 1, 2, 5) == 0)
	   {
		   switch(order)
		   {
			   case 1:
				   pFuncion = Passenger_ComparePassengersByName;
				   break;
			   case 2:
				   pFuncion = Passenger_ComparePassengersByCode;
				   break;
		   }
		   if(utn_getNumero(&order, "\nOrdenar pasajeros:\n1 - Ascendentemente.\n0 - descendentemente.\n", "\nError.\n", 0, 1, 5) == 0)
		   {
			   printf("\nEsto podría tardar...\n\n");
			   ll_sort(pArrayListPassenger, pFuncion, order);
			   ret = 0;
		   }
	   }
   }
   return ret;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE *pFile;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nError al abrir el archivo.\n");
		}
		else
		{
			if(parser_WritePassengerText(pFile, pArrayListPassenger) == 0)
			{
				ret = 0;
			}
			fclose(pFile);
		}
	}
	return ret;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;
	FILE *pFile;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nError al abrir el archivo.\n");
		}
		else
		{
			parser_WritePassengerBinary(pFile, pArrayListPassenger);
			ret = 0;
			fclose(pFile);
		}
	}
	return ret;
}

int controller_FindById(LinkedList* pArrayListPassenger, int id)
{
	int ret = -1;
	int i;
	Passenger* passengerAux = NULL;
	if(pArrayListPassenger != NULL && id > 0)
	{
		for(i = 0; i <= ll_len(pArrayListPassenger);i++)
		{
			passengerAux = ll_get(pArrayListPassenger,i);
			if(passengerAux != NULL && (*(passengerAux)).id == id)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}

int controller_IdMax(LinkedList* pArrayListPassenger)
{
	int i;
	int id = -1;
	Passenger* passengerAux = NULL;
	if(pArrayListPassenger != NULL)
	{
		id = 0;
		for(i = 0; i <= ll_len(pArrayListPassenger);i++)
		{
			passengerAux = ll_get(pArrayListPassenger,i);
			if(passengerAux != NULL && (*(passengerAux)).id > id)
			{
				id = (*(passengerAux)).id;
			}
		}
	}

	return id;
}

int controller_modifyIdPassenger(LinkedList* pArrayListPassenger, int len)
{
	int ret = -1;
	int i;
	int idMax;
	int id;
	Passenger* passengerAux;
	if(pArrayListPassenger != NULL)
	{
		idMax = controller_IdMax(pArrayListPassenger);
		if(idMax > 0)
		{
			ret = 0;
			for(i = 0; i < len; i++)
			{
				passengerAux = ll_get(pArrayListPassenger,i);
				Passenger_getId(passengerAux, &id);
				Passenger_setId(passengerAux, id+idMax);
			}
		}
	}

	return ret;
}
