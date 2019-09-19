#include <avr/io.h>
#include "Arduino.h"
#include "fnqueue.h"
#include "keyboard.h"
#include "adc_driver.h"
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// these constants won't change.  But you can change the size of
// your LCD using them:
const uint8_t numRows = 2;
const uint8_t numCols = 16;

void setup()
{
	lcd.begin(numCols,numRows);
	teclado_setup();
	
	fnqueue_init();
}

void loop()
{
	fnqueue_run();
}

