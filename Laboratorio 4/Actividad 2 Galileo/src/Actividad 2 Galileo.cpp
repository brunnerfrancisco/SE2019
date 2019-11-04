#include "mraa.hpp"

#include <iostream>
using namespace std;

// Tipos de mensjaes soportados
#define OBTENER_TEMP 11
#define OBTENER_MAX 21
#define OBTENER_MIN 31
#define OBTENER_PROM 41
#define OBTENER_TODO 51
#define RESPONDER_TEMP 12
#define RESPONDER_MAX 22
#define RESPONDER_MIN 32
#define RESPONDER_PROM 42
#define RESPONDER_TODO 52

//caracteres especiales del protocolo para armar el paquete
#define PKG_START 0
#define PKG_TYPE 1
#define PKG_SIZE 2

#define START_BYTE '<'
#define END_BYTE '>'

// Buffer para los paquetes
uint8_t pkg_send[4];  			// Paquete minimo a enviar. [caracter inicio (1B), tipo (1B), tamaño (1B), caracter final (1B) ]
uint8_t pkg_receive[256];		// Paquete maximo a recibir. [caracter inicio (1B), tipo (1B), tamaño (1B), payload(MAX 251), caracter final (1B)]

// Inicializar led conectado a GPIO y controlador de I2C
// Comunicacion
mraa::Gpio* d_pin = NULL;
mraa::I2c* i2c;

int tieneRespuesta;

// Funciones
int obtener_operacion();
void enviarmensaje(int operacion);
void trabajarrespuesta();
void imprimir_menu();
int verificarRta(uint8_t tipo);

int main() {

	int operacion = 0;

	d_pin = new mraa::Gpio(3, true, true);

    i2c = new mraa::I2c(0);
    i2c->address(8);

	for(int i=0; i<256; i++) pkg_receive[i] = 0x00; // init package

	imprimir_menu();

	operacion = obtener_operacion();

    // Indefinidamente
    for (;;)
    {
			if (operacion > 0) // if operacion valida
			{
				enviarmensaje(operacion);
				trabajarrespuesta();
				sleep(1);
				d_pin->write(1);// Luego de un segundo, encender led e imprimir por stdout
			}
			else printf("Ingrese una operacion valida\n");
    	// Forzar la salida de stdout
    	fflush(stdout);
    	fflush(stdin);
    	imprimir_menu();
    	operacion = obtener_operacion();
    }
    return 0;
}

int obtener_operacion(){
	char op;
	int resu = scanf("%s",&op);
	if(resu > 0){
		if ((op > 48) && (op < 55)){
			return (int)(op - 48);
		}
	}
	return (-1);
}

void enviarmensaje(int operacion){
	// Armo el mensaje.
	pkg_send[PKG_START] = START_BYTE; // caracter de inicio
    switch (operacion){
    case 1: pkg_send[PKG_TYPE] = OBTENER_TEMP;	//	pkg_send   ->       [<|1|4|>]
    	break;
    case 2: pkg_send[PKG_TYPE] = OBTENER_MAX; //	pkg_send   ->       [<|2|4|>]
        break;
    case 3: pkg_send[PKG_TYPE] = OBTENER_MIN; //	pkg_send   ->       [<|3|4|>]
        break;
    case 4: pkg_send[PKG_TYPE] = OBTENER_PROM; //	pkg_send   ->       [<|4|4|>]
        break;
    case 5: pkg_send[PKG_TYPE] = OBTENER_TODO; //	pkg_send   ->       [<|5|4|>]
        break;
    }
    pkg_send[PKG_SIZE] = 0x04;		// tamaño minimo ya que estoy armando el pedido
    pkg_send[3] = END_BYTE; // caracter de fin

    // con el mensaje a enviar armado, comienzo la transmision
	sleep(1);
	d_pin->write(0);
	i2c->write(pkg_send, pkg_send[2]);
}


void trabajarrespuesta(){
	pkg_receive[0] = i2c->readByte();
	if(pkg_receive[0] == START_BYTE)
	{
		pkg_receive[1] = i2c->readByte();
		if(pkg_receive[1] != END_BYTE && verificarRta(pkg_receive[1]))
		{
			pkg_receive[2] = i2c->readByte();
			if(pkg_receive[2] > 4 && pkg_receive[2] < 256 && pkg_receive[2] != END_BYTE)
			{
				int i = 2;
				while(pkg_receive[i] != END_BYTE && i < 256)
				{
					i += 1;
					pkg_receive[i] = i2c->readByte();
				}
				if(i >= 256)
				{
					printf("Error reading pkg: No END_BYTE found\n");
				}
			} else printf("Error reading pkg: invalid SIZE\n");
		} else printf("Error reading pkg: invalid TYPE\n");
	} else printf("Error reading pkg: No START_BYTE found\n");

	switch(pkg_receive[1]){
	case RESPONDER_TEMP:
			printf("ACTUAL: %d\n", pkg_receive[3]);
			break;
		case RESPONDER_MAX:
			printf("MAXIMA: %d\n", pkg_receive[3]);
			break;
		case RESPONDER_MIN:
			printf("MINIMA: %d\n", pkg_receive[3]);
			break;
		case RESPONDER_PROM:
			printf("PROMEDIO: %d\n", pkg_receive[3]);
			break;
		case RESPONDER_TODO:
			printf("ACTUAL: %d\n", pkg_receive[3]);
			printf("MAXIMA: %d\n", pkg_receive[4]);
			printf("MINIMA: %d\n", pkg_receive[5]);
			printf("PROMEDIO: %d\n", pkg_receive[6]);
			break;
	}
}

int verificarRta(uint8_t tipo){
return RESPONDER_TEMP == tipo || RESPONDER_MAX == tipo || RESPONDER_MIN == tipo || RESPONDER_PROM == tipo || RESPONDER_TODO == tipo;
}


void imprimir_menu(){
	printf("1.- ACTUAL \n");
	printf("2.- MAXIMA \n");
	printf("3.- MINIMA \n");
	printf("4.- PROMEDIO \n");
	printf("5.- TODO \n");
}

