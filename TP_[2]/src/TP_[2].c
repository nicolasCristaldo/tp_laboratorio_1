/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define QTY_PASSENGER 10

int main(void) {
	setbuf(stdout,NULL);

	Passenger arrayPassengers[QTY_PASSENGER];
	int selectedNum;
	int res;
	int actualId = 1;
	int freePosition = 1;

	initPassengers(arrayPassengers, QTY_PASSENGER);

	do
	{
		res = utn_getNumero(&selectedNum, "Seleccione una opcion:\n1-ALTAS. \n2-MODIFICAR. \n3-BAJA. \n4-INFORMAR.\n5-ALTA FORZADA.\n", "Error.\n", 1, 5, 3);
		if(!res)
		{
			switch(selectedNum)
			{
				case 1:
					loadPassenger(arrayPassengers, QTY_PASSENGER, &actualId, &freePosition);
					break;
				case 2:
					modifyPassenger(arrayPassengers, QTY_PASSENGER, actualId-1);
					break;
				case 3:
					deletePassenger(arrayPassengers, QTY_PASSENGER, actualId-1, &freePosition);
					break;
				case 4:
					inform(arrayPassengers, QTY_PASSENGER);
					break;
				case 5:
					sortPassengers(arrayPassengers, QTY_PASSENGER, 1);
					printPassengers(arrayPassengers, QTY_PASSENGER);
					printf("\n");
					sortPassengersByCode(arrayPassengers, QTY_PASSENGER, 0);
					printPassengers(arrayPassengers, QTY_PASSENGER);
					break;
			}
		}
	}while(1);
	return EXIT_SUCCESS;
}
