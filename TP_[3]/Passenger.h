/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	char tipoPasajero[25];
	char estadoVuelo[25];
}Passenger;
/************************* NUEVO PASAJERO ***********************************/
/**
 * \brief crea un nuevo pasajero
 * @return retorna NULL si no se pudo crear un nuevo pasajero, retorna un puntero a pasajero si se pudo crear correctamente.
 */
Passenger* Passenger_new();
/**
 * \brief crea un nuevo pasajero con los datos pasados como parametros.
 * @param id int, id del nuevo pasajero.
 * @param nombre array de caracteres, nombre del nuevo pasajero.
 * @param tipoPasajero array de caracteres, tipo del nuevo pasajero.
 * @param apellido array de caracteres, apellido del nuevo pasajero.
 * @param precio float, precio del nuevo pasajero.
 * @param codigoVuelo array de caracteres, codigo del nuevo pasajero.
 * @param estadoVuelo array de caracteres, estado del nuevo pasajero.
 * @return retorna NULL si no se pudo crear un nuevo pasajero, retorna un puntero a pasajero si se pudo crear correctamente.
 */
Passenger* Passenger_newParametros(int id,char* nombre,char* tipoPasajero,char* apellido,float precio,char* codigoVuelo,char* estadoVuelo);
/**
 * \brief crea un nuevo pasajero con los datos pasados como parametros (todos de tipo array de caracteres).
 * @param idStr array de caracteres, id del nuevo pasajero.
 * @param nombreStr array de caracteres, nombre del nuevo pasajero.
 * @param tipoPasajeroStr array de caracteres, tipo del nuevo pasajero.
 * @param apellidoStr array de caracteres, apellido del nuevo pasajero.
 * @param precioStr array de caracteres, precio del nuevo pasajero.
 * @param codigoStr array de caracteres, codigo del nuevo pasajero.
 * @param estadoVueloStr array de caracteres, estado del nuevo pasajero.
 * @return
 */
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* precioStr,
		char* codigoStr,char* estadoVueloStr);
/******************** TRABAJO CON PASAJEROS *************************/
/**
 * \brief elimina un pasajero
 * @param this puntero a pasajero, pasajero a eliminar.
 */
void Passenger_delete(Passenger* this);
/**
 * \brief compara 2 pasajeros.
 * @param this1 puntero a void, es asignado a un puntero a pasajero para poder ser coparado.
 * @param this2 puntero a void, es asignado a un puntero a pasajero para poder ser coparado.
 * @return retorna 1 si el apellido o nombre del primer pasajero es mayor al del segundo, -1 en caso contrario o si se produjo un error.
 */
int Passenger_ComparePassengersByName(void* this1,void* this2);
/**
 * \brief muestra un pasajero por pantalla.
 * @param this puntero a pasajero. pasajero a mostrar.
 */
void Passenger_PrintPassenger(Passenger* this);

int Passenger_ComparePassengersByCode(void* this1,void* this2);

/******************** SETTERS Y GETTERS ***************************/
/**
 * \brief asigna un parametro al campo id de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param id int, id del pasajero.
 * @return retorna 0 si se pudo asignar el id, -1 si hubo un error.
 */
int Passenger_setId(Passenger* this,int id);
/**
 * \brief recibe un array de caracteres, lo combierte a int y se lo asigna al campo id de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param id array de caracteres, id del pasajero.
 * @return retorna 0 si se pudo asignar el id, -1 si hubo un error.
 */
int Passenger_setIdTxt(Passenger* this,char* id);
/**
 * \brief obtiene el valor del campo id de un pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el id.
 * @param id puntero a int, variable donde se guardará el valor del id del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * \brief asigna un parametro al campo nombre de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param nombre array de caracteres, nombre a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * \brief obtiene el valor del campo nombre del pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el nombre.
 * @param nombre array de caracteres, variable donde se guardará el valor del nombre del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * \brief asigna un parametro al campo apellido de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param apellido array de caracteres, apellido a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * \brief obtiene el valor del campo apellido del pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el apellido.
 * @param apellido array de caracteres, variable donde se guardará el valor del apellido del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * \brief asigna un parametro al campo codigoVuelo de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param codigoVuelo array de caracteres, codigo de vuelo a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * \brief obtiene el valor del campo codigoVuelo del pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el codigo de vuelo.
 * @param codigoVuelo array de caracteres, variable donde se guardará el valor del codigo del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * \brief asigna un parametro al campo tipoPasajero de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param tipoPasajero array de caracteres, tipo a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/**
 * \brief obtiene el valor del campo tipoPasajero del pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el tipo.
 * @param tipoPasajero array de caracteres, variable donde se guardará el valor del tipo de pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/**
 * \brief asigna un parametro al campo precio de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param precio float, precio a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setPrecio(Passenger* this,float precio);
/**
 * \brief recibe un array de caracteres, lo combierte a float y se lo asigna al campo precio de un pasajero.
 * @param this  puntero al pasajero a ser modificado.
 * @param precio array de caracteres, precio a asignar.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setPrecioTxt(Passenger* this,char* precio);
/**
 * \brief obtiene el valor del campo precio de un pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el precio.
 * @param precio puntero a float, variable donde se guardará el valor del precio del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * \brief asigna un parametro al campo estadoVuelo de un pasajero.
 * @param this puntero al pasajero a ser modificado.
 * @param estadoVuelo array de caracteres, estado a asignar.
 * @return  retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
/**
 * \brief obtiene el valor del campo estadoVuelo del pasajero.
 * @param this puntero al pasajero de donde se quiere obtener el estado.
 * @param estadoVuelo array de caracteres, variable donde se guardará el valor del estado del pasajero.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/*************************** OBTENER ESTADO Y TIPO **************************************/
/**
 * \brief pregunta por el tipo de pasajero y lo retorna por referencia
 * @param tipoPasajero array de caracteres, variable donde se guardará el tipo según la respuesta del usuario.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int obtenerTipoPasajero(char* tipoPasajero);
/**
 * \brief pregunta por el estado de vuelo  y lo retorna por referencia
 * @param estadoVuelo array de caracteres, variable donde se guardará el estado según la respuesta del usuario.
 * @return retorna 0 si todo salio bien, -1 si hubo un error.
 */
int obtenerEstadoVuelo(char* estadoVuelo);

#endif /* PASSENGER_H_ */
