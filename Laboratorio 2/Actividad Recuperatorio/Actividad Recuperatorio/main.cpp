
#include <avr/io.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "timers.h"

#define PIN_LED1 2
#define PIN_LED2 4
#define PIN_LED3 7

const uint16_t F_LED1_CS = 50;
const uint16_t F_LED2_CS = 100;
const uint16_t F_LED3_CS = 200;

bool stateLED1 = false;
bool stateLED2 = false;
bool stateLED3 = false;

void callback_LED1(void)
{
	if(stateLED1)
		digitalWrite (PIN_LED1,LOW);
	else
		digitalWrite (PIN_LED1,HIGH);
	stateLED1=!stateLED1;
	//PORTB ^= (1<<PB2);
}

void callback_LED2(void)
{
	if(stateLED2)
		digitalWrite (PIN_LED2,LOW);
	else
		digitalWrite (PIN_LED2,HIGH);
	stateLED2=!stateLED2;
	//PORTB ^= (1<<PB4);
}

void callback_LED3(void)
{
	if(stateLED3)
		digitalWrite (PIN_LED3,LOW);
	else
		digitalWrite (PIN_LED3,HIGH);
	stateLED3=!stateLED3;
	//PORTB ^= (1<<PB7);
}


void setup()
{
	Serial.begin(9600);
	timer_t *timer_LED1 = timers_new(callback_LED1);
	timer_t *timer_LED2 = timers_new(callback_LED2);
	timer_t *timer_LED3 = timers_new(callback_LED3);

	pinMode (PIN_LED1,OUTPUT);
	pinMode (PIN_LED2,OUTPUT);
	pinMode (PIN_LED3,OUTPUT);
	//DDRB |= (1<<DDB2);
	//DDRB |= (1<<DDB4);
	//DDRB |= (1<<DDB7);

	timers_start(timer_LED1, F_LED1_CS);
	timers_start(timer_LED2, F_LED2_CS);
	timers_start(timer_LED3, F_LED3_CS);
}

void loop()
{
	fnqueue_run();
}