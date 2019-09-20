#include <avr/io.h>
#include "Arduino.h"
#include "fnqueue.h"
#include "keyboard.h"
#include "adc_driver.h"
#include <LiquidCrystal.h>

#define MAX_TEMP 400

float Temperatura;
float arregloTemperaturas[MAX_TEMP];
static uint16_t indice = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// these constants won't change.  But you can change the size of
// your LCD using them:
const uint8_t numRows = 2;
const uint8_t numCols = 16;


void ADCaTemperatura(int adc_value){
	// Calculo de la temperatura segun el valor retornado.
	Temperatura = adc_value * 1.1 * 100 / 1024;			// formula de mapeo adc.
	arregloTemperaturas[indice] = Temperatura;
	indice = (indice + 1) % MAX_TEMP;
}

void setup()
{
	lcd.begin(numCols,numRows);
	keyboard_init();
	fnqueue_init();
	adc_cfg sensortemperatura;
	sensortemperatura.channel = 1;            // sensor de temperatura 1, SHIELD 0
	sensortemperatura.callback = ADCaTemperatura;
	adc_init(&sensortemperatura);				// inicializo el canal de sensado
}

void loop()
{
	fnqueue_run();
}

