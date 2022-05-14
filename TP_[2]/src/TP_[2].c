/********************************************************************
*Programa: TP 2
*
*Objetivo: Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
* no puede tener más de 2000 pasajeros.
*
* 1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
* número de Id. El resto de los campos se le pedirá al usuario.
* 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
* o Precio o Tipo de pasajero o Código de vuelo
* 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
* 4. INFORMAR:
* 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
* 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
* promedio.
* 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
*
*mayo 2022
*Autor: Nicolas Cristaldo
*
********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define QTY_PASSENGER 2000

int main(void) {
	setbuf(stdout,NULL);

	Passenger arrayPassengers[QTY_PASSENGER];
	int selectedNum;
	int res;
	int actualId = 1;
	int freePosition = 0;
	Passenger array_AF[7] = {{1,"Olga","Fernandez",23200,"AAA123",3,1,0},
							{16,"Jorge Luis","Rodriguez Silva",84250.25,"BBB123",2,1,0},
							{22,"Fabricio Alejandro","Molina",12476,"CCC123",1,0,0},
							{21,"Ramiro","Somoza",22750,"DDD123",2,1,0},
							{31,"Marcelo Daniel","Gallardo",91218,"AAA123",2,1,0},
							{9,"Liliana","Perez Benitez",41589.36,"EEE123",2,0,0},
							{23,"Kiara","Alvarez Cossini",68545,"BBB123",1,1,0}};

	typePassenger types[3] = {{1,"Menor"},{2,"Adulto"},{3,"Jubilado"}};
	statusFlight status[2] = {{0,"Cancelado"},{1,"Activo"}};

	initPassengers(arrayPassengers, QTY_PASSENGER);

	do
	{
		res = utn_getNumero(&selectedNum, "Seleccione una opcion:\n1-ALTAS. \n2-MODIFICAR. \n3-BAJA. \n4-INFORMAR.\n5-ALTA FORZADA.\n6-CERRAR.\n", "Error.\n", 1, 6, 3);
		if(!res)
		{
			switch(selectedNum)
			{
				case 1:
					if(freePosition < QTY_PASSENGER )
					{
						loadPassenger(arrayPassengers, QTY_PASSENGER, &actualId, &freePosition);
					}
					else
					{
						printf("\nNo hay mas espacios disponibles.\n\n");
					}
					break;
				case 2:
					if(freePosition > 0)
					{
						modifyPassenger(arrayPassengers, QTY_PASSENGER, actualId-1);
					}
					else
					{
						printf("\nNo hay pasajeros cargados.\n\n");
					}
					break;
				case 3:
					if(freePosition > 0)
					{
						deletePassenger(arrayPassengers, QTY_PASSENGER, actualId-1, &freePosition);
					}
					else
					{
						printf("\nNo hay pasajeros cargados.\n\n");
					}
					break;
				case 4:
					if(freePosition > 0)
					{
						inform(arrayPassengers, QTY_PASSENGER, types, status);
					}
					else
					{
						printf("\nNo hay pasajeros cargados.\n\n");
					}
					break;
				case 5:
					sortPassengersByCode(array_AF, 7, 1);
					printPassengers(array_AF, types, status, 7);
					break;
			}
		}
	}while(selectedNum != 6);
	return EXIT_SUCCESS;
}
