#define F_CPU 16000000U

#include "Arduino.h"

const int ledPin =  13; 

int buttonState;
int counterDelay;
int inByte;
int cuarto_caso = 1;

void setup() {
	// initialize serial communication:
	Serial.begin(9600);
	//Inicializar el pin del led como salida
	DDRB |= (1<<DDB5);
	pinMode(ledPin, OUTPUT);
	//digitalWrite(ledPin, HIGH);
	buttonState = 1;
	counterDelay = 0;
}


void loop() {
	// read the sensor:
	if (Serial.available() > 0) {
		inByte = Serial.read(); //leo el caracter
		//Serial.println(inByte);
		buttonState = ((inByte - 49) % 6) + 1; // '1' -> 49 ASCII
	}
	
	switch (buttonState)
	{
		case 1:
			//digitalWrite(ledPin,HIGH);
			//ledState=1;
			PORTB |= (1<<PB5);	//Enciende el Led
		break;
		case 2:
		//Serial.println(counterDelay);
		if(counterDelay >= 100)
		{
			/*if(ledState==0){
				digitalWrite(ledPin,HIGH);
				ledState=1;
				}else{
				digitalWrite(ledPin,LOW);
				ledState=0;
			}*/
			PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
			counterDelay = 0;
		}else
		{
			_delay_ms(10);
			counterDelay++;
		}
		break;
		case 3:
		if(counterDelay >= 50)
		{
			/*if(ledState==0){
				digitalWrite(ledPin,HIGH);
				ledState=1;
				}else{
				digitalWrite(ledPin,LOW);
				ledState=0;
			}*/
			PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
			counterDelay = 0;
		}else
		{
			_delay_ms(10);
			counterDelay++;
		}
		break;
		case 4:
		if(counterDelay >= 25)
		{
			/*if(ledState==0){
				digitalWrite(ledPin,HIGH);
				ledState=1;
				}else{
				digitalWrite(ledPin,LOW);
				ledState=0;
			}*/
			PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
			counterDelay = 0;
		}else
		{
			_delay_ms(10);
			counterDelay++;
		}
		break;
		case 5:
		if(cuarto_caso)
		{
			if(counterDelay>=50)
			{
				PORTB &= ~(1<<PB5);     //Apaga el Led
				counterDelay = 0;
				cuarto_caso = 0;
			}else
			{
				_delay_ms(10);
				counterDelay++;
			}
			}else{
			if(counterDelay>=100)
			{
				PORTB |= (1<<PB5);	//Enciende el Led
				counterDelay = 0;
				cuarto_caso = 1;
			}else
			{
				_delay_ms(10);
				counterDelay++;
			}
		}
		break;
		case 6:
			//digitalWrite(ledPin,LOW);
			//ledState=0;
			PORTB &= ~(1<<PB5);     //Apaga el Led
		break;
	}
	
}