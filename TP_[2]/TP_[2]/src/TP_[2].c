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

#define QTY_PASSENGER 2000

int main(void) {
	setbuf(stdout,NULL);

	Passenger arrayPassengers[QTY_PASSENGER];
	int selectedNum;
	int res;
	int actualId = 1;

	initPassengers(arrayPassengers, QTY_PASSENGER);

	do
	{
		res = utn_getNumero(&selectedNum, "Seleccione una opcion:\n1-ALTAS. \n2-MODIFICAR. \n3-BAJA. \n4-INFORMAR\n", "Error.\n", 1, 4, 3);
		if(!res)
		{
			switch(selectedNum)
			{
				case 1:
					loadPassenger(arrayPassengers, QTY_PASSENGER, &actualId);

					printf("\n %s",arrayPassengers[0].name);
					printf("\n %s",arrayPassengers[0].lastName);
					printf("\n %s",arrayPassengers[0].flyCode);
					printf("\n %.2f",arrayPassengers[0].price);
					printf("\n %d",arrayPassengers[0].id);
					printf("\n %d",arrayPassengers[0].typePassenger);
					printf("\n %d",arrayPassengers[0].isEmpty);

					printf("\n %s",arrayPassengers[1].name);
					printf("\n %s",arrayPassengers[1].lastName);
					printf("\n %s",arrayPassengers[1].flyCode);
					printf("\n %.2f",arrayPassengers[1].price);
					printf("\n %d",arrayPassengers[1].id);
					printf("\n %d",arrayPassengers[1].typePassenger);
					printf("\n %d",arrayPassengers[1].isEmpty);

					printf("\n %s",arrayPassengers[2].name);
					printf("\n %s",arrayPassengers[2].lastName);
					printf("\n %s",arrayPassengers[2].flyCode);
					printf("\n %.2f",arrayPassengers[2].price);
					printf("\n %d",arrayPassengers[2].id);
					printf("\n %d",arrayPassengers[2].typePassenger);
					printf("\n %d",arrayPassengers[2].isEmpty);
					break;
				case 2:
					modifyPassenger(arrayPassengers, QTY_PASSENGER, actualId-1);
					break;
				case 3:
					deletePassenger(arrayPassengers, QTY_PASSENGER, actualId-1);
					break;
				case 4:
					break;
			}
		}
	}while(1);
	return EXIT_SUCCESS;
}
