#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int lenAux;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3. Alta de pasajero.\n"
    			"4. Modificar datos de pasajero.\n5. Baja de pasajero.\n6. Listar pasajeros.\n7. Ordenar pasajeros.\n"
    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir.\n"
    			"Seleccione una opcion: ", "\nRespuesta invalida.\n", 1, 10, 1);
        switch(option)
        {
            case 1:
            	if(ll_len(listaPasajeros) > 0)
            	{
            		if(utn_confirmar("\nYa tiene pasajeros cargados, si continua se cambiarán sus id.\n¿Continuar? s/n ",
            				"\nRespuesta invalida.\n", 5) == 1)
            		{
            			lenAux = ll_len(listaPasajeros);
            			controller_loadFromText("data.csv",listaPasajeros);
            			controller_modifyIdPassenger(listaPasajeros,lenAux);
            		}
            	}
            	else
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
            	}
                break;
            case 2:
            	if(ll_len(listaPasajeros) > 0)
            	{
					if(utn_confirmar("\nYa tiene pasajeros cargados, si continua se cambiarán sus id.\n¿Continuar? s/n ",
									"\nRespuesta invalida.\n", 5) == 1)
					{
						lenAux = ll_len(listaPasajeros);
						controller_loadFromBinary("data.bin", listaPasajeros);
						controller_modifyIdPassenger(listaPasajeros,lenAux);
					}
            	}
            	else
				{
					controller_loadFromBinary("data.bin", listaPasajeros);
				}
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	if(ll_len(listaPasajeros) > 0)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
            	break;
            case 5:
            	if(ll_len(listaPasajeros) > 0)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
				break;
			case 6:
				if(ll_len(listaPasajeros) > 0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
				break;
			case 7:
				if(ll_len(listaPasajeros) > 0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
				break;
			case 8:
				if(ll_len(listaPasajeros) > 0)
				{
					controller_saveAsText("data.csv", listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
				break;
			case 9:
				if(ll_len(listaPasajeros) > 0)
				{
					controller_saveAsBinary("data.bin", listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros cargados.\n");
				}
				break;
			case 10:
				ll_deleteLinkedList(listaPasajeros);
				break;
        }
    }while(option != 10);
    return 0;
}

