
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

static int index = 0;

float temperatures[MAX_TEMP];

float actual = 0;
float minimum = 0;
float maximum = 0;
float average = 0;

static uint16_t cant_samples = 0;

void computeMax(void);
void computeMin(void);
void computeAve(void);

/************************************************************************/
/*                      CALLBACKS KEYBOARD                              */
/************************************************************************/

void up_keyUp()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keyUp()
{
	lcd.setCursor(0,1);
	lcd.print("MAX. C° ");
	
	lcd.setCursor(11,1);
	lcd.print(maximum);
	
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
	
	lcd.setCursor(11,1);
	lcd.print(minimum);
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
	
	lcd.setCursor(11,1);
	lcd.print(average);
	
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
	float actual = 0;
	if(index > 0)
		actual = temperatures[index-1];
	lcd.print(actual);
}

void up_keySelect()
{
	lcd.setCursor(0,1);
	lcd.print("                ");
}

void down_keySelect()
{
	lcd.setCursor(0,1);
	lcd.print("CANT M:");
	lcd.setCursor(11,1);
	lcd.print(cant_samples);
}

/************************************************************************/
/*                         CALLBACK SENSOR                              */
/************************************************************************/

void process_temperature(float sensor_value)
{
	temperatures[index] = sensor_value;
	if(cant_samples<100)
	cant_samples++;
	index = (index + 1) % MAX_TEMP;
	cant_samples++;

	// computar la temperatura actual
	if(index > 0)
	actual = temperatures[index-1];
	
	// Hallar la temperatura maxima
	computeMax();
	
	// Hallar la temperatura minima
	computeMin();
	
	// Computar el promedio de las temperaturas registradas
	computeAve();
}

/************************************************************************/
/*                           AUXILIARES                                 */
/************************************************************************/

void computeMax()
{
	maximum = temperatures[0];
	int16_t i;
	for (i = 1; i < MAX_TEMP ; i++)
	{
		if (temperatures[i] > 0.0 && maximum < temperatures[i])
		{
			maximum = temperatures[i];
		}
	}
}

void computeMin()
{
	
	minimum = temperatures[0];
	int16_t i;
	for (i = 1; i < MAX_TEMP ; i++)
	{
		if (temperatures[i] > 0.0 && minimum > temperatures[i])
		{
			minimum = temperatures[i];
		}
	}
}

void computeAve()
{
	float sum = 0;
	for (int i = 0; i < MAX_TEMP ; i++)
	{
		sum += temperatures[i];
	}
	if(cant_samples == 0)
		average = 0;
	else
		average = sum / cant_samples;
}

void setup()
{
	lcd.begin(numCols,numRows);

	for(int i = 0; i<MAX_TEMP;i++)
		temperatures[i]=0.0f;

	lcd.setCursor (0,0);
	lcd.print ("SE2019 Sen.Temp.");
	lcd.setCursor (0,1);
	lcd.print ("                ");
	
	fnqueue_init();
	
	keyboard_init();

	sensor_init(process_temperature);
	
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

