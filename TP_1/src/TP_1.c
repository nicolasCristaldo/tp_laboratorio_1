/*******************************************************************
*Programa: TP 1
*
*Objetivo:
*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
*para ofrecerlos a sus clientes.
*Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
*El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
*
*Version: 0.1 abril 2022
*Autor: Nicolas Cristaldo
*
********************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int selectedNum;
	float kilometres;
	float aerolineasPrice;
	float latamPrice;
	int pricesFlag = 0;
	int calcPricesFlag = 0;

	do   //menu de opciones
	{
		//system("CLS");
		printf("\n1. Ingresar Kil�metros: (km = %.2f \n)",kilometres);
		printf("\n2. Ingresar Precio de Vuelos: (Aerol�neas = %.2f, Latam = %.2f)"
			   "\n   - Precio vuelo Aerol�neas: "
			   "\n   - Precio vuelo Latam: \n",aerolineasPrice,latamPrice);
		printf("\n3. Calcular todos los costos"
			   "\n   a) Tarjeta de d�bito: (descuento 10)"
			   "\n   b) Tarjeta de cr�dito: (inter�s 25)"
		       "\n   c) Bitcoin: (1BTC -> 4606954.55 Pesos Argentinos)"
		       "\n   d) Mostrar precio por km: (precio unitario)"
      		   "\n   e) Mostrar diferencia de precio ingresada: (Latam - Aerol�neas) \n");
		printf("\n4. Informar Resultados"
			   "\n   Latam: "
			   "\n   a) Precio con tarjeta de d�bito: $ "
			   "\n   b) Precio con tarjeta de cr�dito: $ "
			   "\n   c) Precio pagando con bitcoin: BTC"
			   "\n   d) Precio unitario: $");
		printf("\n   Aerol�neas: "
			   "\n   a) Precio con tarjeta de d�bito: $ "
			   "\n   b) Precio con tarjeta de cr�dito: $ "
			   "\n   c) Precio pagando con bitcoin: BTC"
			   "\n   d) Precio unitario: $ "
			   "\n   La diferencia de precio es: $ \n");
		printf("\n5. Carga forzada de datos ");
		printf("\n6. Salir ");
		scanf("%d",&selectedNum);

		switch(selectedNum)
		{
			case 1:
				printf("\nIngrese los kilometros totales del vuelo ");
				scanf("%f",&kilometres);
				break;
			case 2:
				do
				{
					printf("\nPrecio vuelo Aerol�neas (mas de $10000): ");
					scanf("%f",&aerolineasPrice);
				}while(aerolineasPrice < 10000);
				do
				{
					printf("\nPrecio vuelo Latam (mas de $10000): ");
					scanf("%f",&latamPrice);
				}while(latamPrice < 10000);

				pricesFlag = 1;
				break;
			case 3:
				if(pricesFlag == 1)
				{
					makeDebitDiscount(aerolineasPrice);   //realiza descuento del 10%
					makeDebitDiscount(latamPrice);        //

					makeCreditInterest(aerolineasPrice);  //realiza el interes del 25%
					makeCreditInterest(latamPrice);       //

					passPriceToBtc(aerolineasPrice);      // pasa el precio a bitcoin
					passPriceToBtc(latamPrice);           //

					calcPricesFlag = 1;
				}
				else
				{
					printf("\nError, verifique los precios.\n");
				}
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				printf("\nError");
		}

	}while(selectedNum != 6);

	return EXIT_SUCCESS;
}

