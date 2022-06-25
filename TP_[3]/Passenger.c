/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include <ctype.h>

/************************* NUEVO PASAJERO ***********************************/
Passenger* Passenger_new()
{
	Passenger *newPassenger = NULL;

	newPassenger = (Passenger*)malloc(sizeof(Passenger));
	if(newPassenger != NULL)
	{
		strcpy(newPassenger->apellido,"");
		strcpy(newPassenger->codigoVuelo,"");
		newPassenger->id = 0;
		strcpy(newPassenger->nombre,"");
		newPassenger->precio = 0;
		strcpy(newPassenger->tipoPasajero,"");
		strcpy(newPassenger->estadoVuelo,"");
	}

	return newPassenger;
}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* precioStr,char* codigoStr,
										char* estadoVueloStr)
{
	Passenger *newPassenger = NULL;
	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoStr != NULL &&
			estadoVueloStr != NULL)
	{
		newPassenger = Passenger_new();

		if(newPassenger != NULL)
		{
			if(Passenger_setApellido(newPassenger, apellidoStr) != 0)
			{
				printf("\nError al cargar apellido.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setNombre(newPassenger, nombreStr) != 0)
			{
				printf("\nError al cargar nombre.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setPrecioTxt(newPassenger, precioStr) != 0)
			{
				printf("\nError al cargar precio.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setCodigoVuelo(newPassenger, codigoStr) != 0)
			{
				printf("\nError al cargar codigo.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setIdTxt(newPassenger, idStr) != 0)
			{
				printf("\nError al cargar id.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr) != 0)
			{
				printf("\nError al cargar tipo.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setEstadoVuelo(newPassenger, estadoVueloStr) != 0)
			{
				printf("\nError al cargar estado.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
		}
	}
	return newPassenger;
}
Passenger* Passenger_newParametros(int id,char* nombre,char* tipoPasajero,char* apellido,float precio,char* codigoVuelo
		,char* estadoVuelo)
{
	Passenger *newPassenger = NULL;
	if(id > 0 && nombre != NULL && tipoPasajero != NULL && apellido != NULL && precio > 0 && codigoVuelo != NULL && estadoVuelo != NULL)
	{
		newPassenger = Passenger_new();

		if(newPassenger != NULL)
		{
			if(Passenger_setApellido(newPassenger, apellido) != 0)
			{
				printf("\nError al cargar apellido.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setNombre(newPassenger, nombre) != 0)
			{
				printf("\nError al cargar nombre.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setPrecio(newPassenger, precio) != 0)
			{
				printf("\nError al cargar precio.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setCodigoVuelo(newPassenger, codigoVuelo) != 0)
			{
				printf("\nError al cargar codigo.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setId(newPassenger, id) != 0)
			{
				printf("\nError al cargar id.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setTipoPasajero(newPassenger, tipoPasajero) != 0)
			{
				printf("\nError al cargar tipo de pasajero.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
			else if(Passenger_setEstadoVuelo(newPassenger, estadoVuelo) != 0)
			{
				printf("\nError al cargar estado.\n");
				free(newPassenger);
				newPassenger = NULL;
			}
		}
	}
	return newPassenger;
}

/******************** TRABAJO CON PASAJEROS *************************/

int Passenger_addPassenger(LinkedList* pArrayListPassenger)
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
		if(utn_getNombre(name, "\nIngrese el nombre: ","\nError.\n",2,50,5) == 0 &&
				utn_getNombre(lastName, "\nIngrese el apellido: ", "\nError.\n",2,50,5) == 0&&
				utn_getFlotante(&price, "\nIngrese el precio: ",  "\nError.\n",3000,150000,5) == 0 &&
				obtenerTipoPasajero(type)== 0 && utn_getAlfanumerico(flyCode, "\nIngrese el codigo de vuelo: ", "\nError.\n",4,7,5) == 0&&
				obtenerEstadoVuelo(status) == 0)
		{
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
	}
	return ret;
}

int passenger_removePassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;
	int id;
	int idMax;
	int index;
	Passenger* passengerAux = NULL;
	if(pArrayListPassenger != NULL)
	{
		idMax = controller_IdMax(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		if(utn_getNumero(&id, "\nIngrese el id del Pasajero a eliminar: ", "\nError.\n", 1,idMax, 5) == 0)
		{
			index = controller_FindById(pArrayListPassenger, id);
			passengerAux = ll_get(pArrayListPassenger,index);
			if(id != -1 && passengerAux != NULL)
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
				printf("\nNo se encontró el id.\n\n");
			}
		}
	}

	return ret;
}

int Passenger_editPassenger(LinkedList* pArrayListPassenger)
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
		controller_ListPassenger(pArrayListPassenger);
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
				printf("\nNo se encontró el id.\n\n");
			}
		}
	}

	return ret;
}
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

void Passenger_PrintPassenger(Passenger* this)
{
	printf("\n%-10d %-20s %-20s %-15.2f %-15s %-20s %-20s",(*(this)).id,(*(this)).nombre,(*(this)).apellido,(*(this)).precio,(*(this)).codigoVuelo,
			(*(this)).tipoPasajero,(*(this)).estadoVuelo);
}

int Passenger_ComparePassengersByName(void* this1,void* this2)
{
	int ret = -1;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;
	if(this1 != NULL && this2 != NULL)
	{
		passenger1 = this1;
		passenger2 = this2;

		if(strcmp((*(passenger1)).apellido,(*(passenger2)).apellido) > 0)
		{
			ret = 1;
		}
		else if(strcmp((*(passenger1)).apellido,(*(passenger2)).apellido) == 0 && strcmp((*(passenger1)).nombre,(*(passenger2)).nombre) > 0)
		{
			ret = 1;
		}
	}
	return ret;
}
int Passenger_ComparePassengersByCode(void* this1,void* this2)
{
	int ret = -1;
	Passenger* passenger1 = NULL;
	Passenger* passenger2 = NULL;
	if(this1 != NULL && this2 != NULL)
	{
		passenger1 = this1;
		passenger2 = this2;

		if(strcmp((*(passenger1)).codigoVuelo,(*(passenger2)).codigoVuelo) > 0)
		{
			ret = 1;
		}
		else if(strcmp((*(passenger1)).codigoVuelo,(*(passenger2)).codigoVuelo) == 0 && (*(passenger1)).precio > (*(passenger2)).precio)
		{
			ret = 1;
		}
	}
	return ret;
}
/******************** SETTERS Y GETTERS ***************************/

int Passenger_setId(Passenger* this,int id)
{
	int ret = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
int Passenger_setIdTxt(Passenger* this,char* id)
{
	int ret = -1;
	int num;

	if(this != NULL && id != NULL && esNumerica(id) != 0)
	{
		num = atoi(id);
		if(num > 0)
		{
			this->id = num;
			ret = 0;
		}
	}
	return ret;
}
int Passenger_getId(Passenger* this,int* id)
{
	int ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ret = -1;
	if(this != NULL && nombre != NULL && esNombre(nombre) != 0 && strlen(nombre) < 50)
	{
		arreglarNombre(nombre);
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		ret = 0;
	}
	return ret;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre != NULL)
	{
		nombre = this->nombre;
	}
	return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ret = -1;

	if(this != NULL && apellido != NULL && esNombre(apellido) != 0 && strlen(apellido) < 50)
	{
		arreglarNombre(apellido);
		strncpy(this->apellido,apellido,sizeof(this->apellido));
		ret = 0;
	}
	return ret;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ret = -1;

	if(this != NULL && apellido != NULL)
	{
		apellido = this->apellido;
	}
	return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1;
	if(this != NULL && codigoVuelo != NULL && esAlfanumerica(codigoVuelo) != 0 && strlen(codigoVuelo) < 9)
	{
		pasarAMayuscula(codigoVuelo);
		strncpy(this->codigoVuelo,codigoVuelo,sizeof(this->codigoVuelo));
		ret = 0;
	}
	return ret;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		codigoVuelo = this->codigoVuelo;
	}
	return ret;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret = -1;

	if(this != NULL && tipoPasajero != NULL && esNombre(tipoPasajero) != 0 && strlen(tipoPasajero) < 25)
	{
		strncpy(this->tipoPasajero,tipoPasajero,sizeof(this->tipoPasajero));
		ret = 0;
	}
	return ret;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		tipoPasajero = this->apellido;
	}
	return ret;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int ret = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		ret = 0;
	}

	return ret;
}
int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int ret = -1;
	float num = 0;

	if(this != NULL && precio != NULL && esFlotante(precio) != 0)
	{
		num = atof(precio);
		if(num > 0)
		{
			this->precio = num;
			ret = 0;
		}
	}

	return ret;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ret = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret = -1;

	if(this != NULL && estadoVuelo != NULL && esNombre(estadoVuelo) != 0 && strlen(estadoVuelo) < 25)
	{
		strncpy(this->estadoVuelo,estadoVuelo,sizeof(this->estadoVuelo));
		ret = 0;
	}
	return ret;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ret = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		estadoVuelo = this->estadoVuelo;
	}
	return ret;
}
/*************************** OBTENER ESTADO Y TIPO **************************************/

int obtenerEstadoVuelo(char* statusStr)
{
	int ret = -1;
	int res;
	if(statusStr != NULL)
	{
		if(utn_getNumero(&res,"\nIngrese el estado del pasajero:\n1 - EN VUELO.\n2 - ATERRIZADO."
				"\n3 - EN HORARIO.\n4 - DEMORADO.\n","\nError.\n",1,4,5) == 0)
		{
			switch(res)
			{
				case 1:
					strcpy(statusStr,"En Vuelo");
					break;
				case 2:
					strcpy(statusStr,"Aterrizado");
					break;
				case 3:
					strcpy(statusStr,"En Horario");
					break;
				case 4:
					strcpy(statusStr,"Demorado");
					break;
			}
			ret = 0;
		}
	}
	return ret;
}

int obtenerTipoPasajero(char* typeStr)
{
	int ret = -1;
	int res;
	if(typeStr != NULL)
	{
		if(utn_getNumero(&res,"\nIngrese el tipo de pasajero:\n1 - PRIMERA CLASE.\n2 - CLASE EJECUTIVA."
						"\n3 - CLASE ECONOMICA.\n","\nError.\n",1,3,5)==0)
		{
			switch(res)
			{
				case 1:
					strcpy(typeStr,"FirstClass");
					break;
				case 2:
					strcpy(typeStr,"ExecutiveClass");
					break;
				case 3:
					strcpy(typeStr,"EconomyClass");
					break;
			}
			ret = 0;
		}
	}
	return ret;
}

