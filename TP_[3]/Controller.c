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
	Passenger* newPassenger = NULL;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[8];
	char type[15];
	char status[15];
	int id;
	if(pArrayListPassenger != NULL)
	{
		if(utn_getNombre(name, "\nIngrese el nombre: ","\nError.\n",2,50,5) == -1)
		{
			return ret;
		}
		if(utn_getNombre(lastName, "\nIngrese el apellido: ", "\nError.\n",2,50,5) == -1)
		{
			return ret;
		}
		if(utn_getFlotante(&price, "\nIngrese el precio: ",  "\nError.\n",3000,150000,5) == -1)
		{
			return ret;
		}
		if(obtenerTipoPasajero(type)!= 0)
		{
			return ret;
		}

		if(utn_getAlfanumerico(flyCode, "\nIngrese el codigo de vuelo: ", "\nError.\n",4,7,5) == -1)
		{
			return ret;
		}
		if(obtenerEstadoVuelo(status) != 0)
		{
			return ret;
		}

		id = controller_IdMax(pArrayListPassenger) +1;

		newPassenger = Passenger_newParametros(id, name, type, lastName, price, flyCode, status);
		if(newPassenger != NULL)
		{
			if(ll_add(pArrayListPassenger, newPassenger) == 0)
			{
				ret = 0;
			}
		}
	}
    return ret;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int ret = -1;
    int id;
    int idMax;
    int index;
    int res;
    char array[50];
    float price;
    Passenger* passengerAux = NULL;
    if(pArrayListPassenger != NULL)
    {
    	idMax = controller_IdMax(pArrayListPassenger);
    	if(utn_getNumero(&id, "\nIngrese el id del Pasajero: ", "\nError.\n", 1, idMax, 5) == 0)
		{
			index = controller_FindById(pArrayListPassenger, id);
			passengerAux = ll_get(pArrayListPassenger,index);

			if(index != -1 && passengerAux != NULL)
			{
				printf("\n%-10s %-20s %-20s %-15s %-15s %-20s %-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO","TIPO","ESTADO");
				Passenger_PrintPassenger(passengerAux);
				if(utn_confirmar("\n¿Desea modificar este pasajero? s/n ", "\nRespuesta invalida.\n", 5) == 1)
				{
					if(utn_getNumero(&res, "\nIngrese campo a modificar:\n1 - NOMBRE.\n2 - APELLIDO.\n3 - ESTADO DE VUELO.\n4 - PRECIO.\n"
							"5 - CODIGO DE VUELO.\n6 - TIPO DE PASAJERO.\n", "\nError\n", 1, 6, 5) == 0)
					{
						switch(res)
						{
						case 1:
							if(utn_getNombre(array, "\nIngrese el nombre: ","\nError.\n",2,50,5) == 0)
							{
								Passenger_setNombre(passengerAux, array);
								ret = 0;
							}
							break;
						case 2:
							if(utn_getNombre(array, "\nIngrese el apellido: ", "\nError.\n",2,50,5) == 0)
							{
								Passenger_setApellido(passengerAux, array);
								ret = 0;
							}
							break;
						case 3:
							if(obtenerEstadoVuelo(array) == 0)
							{
								Passenger_setEstadoVuelo(passengerAux, array);
								ret = 0;
							}
							break;
						case 4:
							if(utn_getFlotante(&price, "\nIngrese el precio: ",  "\nError.\n",3000,150000,5) == 0)
							{
								Passenger_setPrecio(passengerAux, price);
								ret = 0;
							}
							break;
						case 5:
							if(utn_getAlfanumerico(array, "\nIngrese el codigo de vuelo: ", "\nError.\n",4,7,5) == 0)
							{
								Passenger_setCodigoVuelo(passengerAux, array);
								ret = 0;
							}
							break;
						case 6:
							if(obtenerTipoPasajero(array) == 0)
							{
								Passenger_setTipoPasajero(passengerAux, array);
								ret = 0;
							}
							break;
						}
					}
				}
			}
			else
			{
				printf("\nNo se encontró el id.\n");
			}
		}
    }

    return ret;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int id;
	int idMax;
	int index;
	Passenger* passengerAux = NULL;
	if(pArrayListPassenger != NULL)
	{
		idMax = controller_IdMax(pArrayListPassenger);
		if(utn_getNumero(&id, "\nIngrese el id del Pasajero a eliminar: ", "\nError.\n", 1,idMax, 5) == 0)
		{
			index = controller_FindById(pArrayListPassenger, id);
			passengerAux = ll_get(pArrayListPassenger,index);
			if(id != -1)
			{
				printf("\n%-10s %-20s %-20s %-15s %-15s %-20s %-20s","ID","NOMBRE","APELLIDO","PRECIO","CODIGO","TIPO","ESTADO");
				Passenger_PrintPassenger(passengerAux);
				if(utn_confirmar("\n¿desea eliminar este pasajero? s/n ", "\nRespuesta invalida.\n", 5) == 1)
				{
					Passenger_delete(passengerAux);
					ll_remove(pArrayListPassenger, index);
					printf("\nSe eliminó el pasajero.\n");
					ret = 0;
				}
			}
			else
			{
				printf("\nNo se encontró el id.\n");
			}
		}
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

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
			   printf("\nEsto podría tardar...\n");
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
