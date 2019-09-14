//#define F_CPU 16000000U
#include <avr/interrupt.h>
#include <stdint.h>
#include "device.h"
#include "fnqueue.h"
#include "Arduino.h"

static int16_t oldkey=-1;
static volatile int16_t analogVal;
static int contador=0;
int16_t adc_key_val[NRO_TECLAS] ={50, 150, 360, 535, 760 };
struct callback_str teclas_callback[NRO_TECLAS];

void key_up_callback(void (* handler)(), int tecla){
	if(tecla>=0 && tecla < NRO_TECLAS){
		teclas_callback[tecla].callback_Up = handler;
	}
}

void key_down_callback(void (* handler)(), int tecla){
	if(tecla>=0 && tecla < NRO_TECLAS){
		teclas_callback[tecla].callback_Down = handler;
	}
}

void ProcesarAdc()
{
	int16_t k;
	for (k = 0; k < NRO_TECLAS; k++)
	{
		if (analogVal < adc_key_val[k])
		{
			if(oldkey!=k)
			{
				oldkey=k;
				Serial.println(analogVal);
				Serial.println(k);
				teclas_callback[k].callback_Down();
			}
			break;
		}
	}
	if (k >= NRO_TECLAS)		//solto el boton
	if(oldkey!= -1)
	{
		teclas_callback[oldkey].callback_Up();
		oldkey = -1;     // Solto el boton y cambio el valor de oldkey
	}
	;
}

ISR(ADC_vect){
	contador++;
	if(contador>50){
		analogVal= ADC;
		fnqueue_add(ProcesarAdc);
		contador=0;
	}
	
}

void teclado_setup()
{
		
		// clear ADLAR in ADMUX (0x7C) to right-adjust the result
		// ADCL will contain lower 8 bits, ADCH upper 2 (in last two bits)
		ADMUX &= ~(1<<ADLAR);
		
		// Set REFS1..0 in ADMUX (0x7C) to change reference voltage to the
		// proper source (01)
		ADMUX |= (1<<REFS0);
		
		// Clear MUX3..0 in ADMUX (0x7C) in preparation for setting the analog
		// input
		ADMUX &= ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0);
		
		// Set MUX3..0 in ADMUX (0x7C) to read from AD8 (Internal temp)
		// Do not set above 15! You will overrun other parts of ADMUX. A full
		// list of possible inputs is available in Table 24-4 of the ATMega328
		// datasheet
		
		//Queda como 0 porque de la pantalla lee en el pin 0.
		
		//	ADMUX |= 8;
		// ADMUX |= B00001000; // Binary equivalent
		
		// Set ADEN in ADCSRA (0x7A) to enable the ADC.
		// Note, this instruction takes 12 ADC clocks to execute
		ADCSRA |= 1<<ADEN;
		
		// Set ADATE in ADCSRA (0x7A) to enable auto-triggering.
		ADCSRA |= 1<<ADATE;
		
		// Clear ADTS2..0 in ADCSRB (0x7B) to set trigger mode to free running.
		// This means that as soon as an ADC has finished, the next will be
		// immediately started.
		ADCSRB &= ~(1<<ADTS2 | 1<<ADTS1 | 1<<ADTS0);
		
		// Set the Prescaler to 128 (16000KHz/128 = 125KHz)
		// Above 200KHz 10-bit results are not reliable.
		ADCSRA |= (1<<ADPS2 | 1<<ADPS1 | 1<<ADPS2);
		
		// Set ADIE in ADCSRA (0x7A) to enable the ADC interrupt.
		// Without this, the internal interrupt will not trigger.
		ADCSRA |= 1<<ADIE;
		
		// Enable global interrupts
		// AVR macro included in <avr/interrupts.h>, which the Arduino IDE
		// supplies by default.
		sei();
		
		// Kick off the first ADC
		
		// Set ADSC in ADCSRA (0x7A) to start the ADC conversion
		ADCSRA |= 1<<ADSC;
		
}