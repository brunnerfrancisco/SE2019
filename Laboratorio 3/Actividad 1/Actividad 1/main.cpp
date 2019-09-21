
#include <avr/io.h>
#include <stdint.h>
#include <LiquidCrystal.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "keyboard.h"
#include "sensor_driver.h"

#define MAX_TEMP 100

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// these constants won't change.  But you can change the size of
// your LCD using them:
const uint8_t numRows = 2;
const uint8_t numCols = 16;

float Temperatura;
float arregloTemperaturas[MAX_TEMP];
static uint16_t indice = 0;

void up_keyUp()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keyUp()
{
	lcd.setCursor(0,1);
	lcd.print("MAX. C° ");
	
	float mayor = arregloTemperaturas[0];
	int16_t i;
	for (i = 1; i < MAX_TEMP ; i++)
	{
		if (mayor < arregloTemperaturas[i])
		{
			mayor = arregloTemperaturas[i];
		}
	}
	
	lcd.setCursor(11,1);
	lcd.print(mayor);
	
}

void up_keyDown()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keyDown()
{
	lcd.setCursor(0,1);
	lcd.print("MIN. C° ");
	
	float minimo = arregloTemperaturas[0];
	int16_t i;
	for (i = 1; i < MAX_TEMP ; i++)
	{
		if (minimo > arregloTemperaturas[i])
		{
			minimo = arregloTemperaturas[i];
		}
	}
	
	lcd.setCursor(11,1);
	lcd.print(minimo);
}

void up_keyRight()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keyRight()
{
	lcd.setCursor(0,1);
	lcd.print("PROM. C° ");
	Serial.println ("llegue al down_keyRight");
	float promedio=0;
	int16_t i;
	for (i = 1; i < MAX_TEMP ; i++)
	{
		promedio = promedio + arregloTemperaturas[i];
	}
	promedio = promedio / 100;
	
	lcd.setCursor(11,1);
	lcd.print(promedio);
	
}

void up_keyLeft()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keyLeft()
{
	lcd.setCursor(0,1);
	lcd.print("ACTUAL C° ");
	lcd.setCursor(11,1);
	lcd.print(Temperatura);
}

void up_keySelect()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keySelect()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void process_temperature(int sensor_value)
{
	// Calculo de la temperatura segun el valor retornado.
	Temperatura = sensor_value * 1.1 * 100 / 1024;			// formula de mapeo del sensor
	arregloTemperaturas[indice] = Temperatura;
	indice = (indice + 1) % MAX_TEMP;
	//Serial.println("hola llegue al procesar temperatura");
	//Serial.println(sensor_value);
}

void setup()
{
	Serial.begin (9600);

	lcd.begin(numCols,numRows);

	lcd.setCursor (0,0);
	lcd.print ("SE2019 Sen.Temp.");
	lcd.setCursor (0,1);
	lcd.print ("                ");
	
	fnqueue_init();
	
	keyboard_init();

	//sensor_init(process_temperature);
	
	// callbacks del keyboard
	key_up_callback(up_keyUp, TECLAUP);
	key_down_callback(down_keyUp, TECLAUP);
	key_up_callback(up_keyDown, TECLADOWN);
	key_down_callback(down_keyDown, TECLADOWN);
	key_up_callback(up_keyLeft, TECLALEFT);
	key_down_callback(down_keyLeft, TECLALEFT);
	key_up_callback(up_keyRight, TECLARIGHT);
	key_down_callback(down_keyRight, TECLARIGHT);
	key_up_callback(up_keySelect, TECLASELECT);
	key_down_callback(down_keySelect, TECLASELECT);
	
}

void loop()
{
	fnqueue_run();
}

