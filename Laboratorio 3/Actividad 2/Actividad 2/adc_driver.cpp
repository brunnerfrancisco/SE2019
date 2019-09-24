
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "critical.h"
#include "adc_driver.h"

static int volatile actual_channel = 0;
static int converting = 0;
volatile uint16_t value_adc = 0;

struct adc_cfg adc_channel_cfg[MAX_CHANNELS];

int adc_init(struct adc_cfg *cfg)
{
	adc_channel_cfg[ cfg->channel ] = *cfg;

	adc_channel_cfg[ cfg->channel ].active = 1;

	// flag para inicializar el ADC solo una vez
	if(!converting)
	{
		cli();
		
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // estos bit setean el prescaler lo pongo en 128
		ADMUX |= (1 << REFS0);
		ADMUX &= ~(1 << ADLAR);
		ADCSRA &= ~(1 << ADATE); // este bit en 0 desactiva el AutoTrigger segun el datasheet
		ADCSRA |= (1 << ADEN); // habilito el adc "lo prendo" segun el datasheet
		ADCSRA |= (1 << ADIE); // este bit activa la interrupcion por conversion completa ISR(ADC_Vect)
		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
		ADCSRA |= (1 << ADSC); // este es el bit que pone a funcionar el ADC segun el datasheet

		// habilito las interrupciones
		sei();
		converting = 1;
	}
	return 1;
}

void adc_process()
{
	// Para cada canal en el adc_channel_cfg llamo a la funcion de callback que haya terminado la conversion
	for(int i = 0; i < MAX_CHANNELS; i++)
	{
		if (adc_channel_cfg[i].finish_convertion)
		{
			adc_channel_cfg[i].callback( adc_channel_cfg[i].value );
			adc_channel_cfg[i].finish_convertion = 0;
		}
	}
}

ISR(ADC_vect)
{
	value_adc = (ADCL) | (ADCH << 8);
	adc_channel_cfg[actual_channel].value = value_adc;
	adc_channel_cfg[actual_channel].finish_convertion = 1;

	if(actual_channel == 0)
	{
		actual_channel = 1;
		// limpiamos el ADMUX
		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
		// seteamos el canal actual
		ADMUX |= 1<<MUX0;
	}
	else
	{
		actual_channel = 0;
		// limpiamos el ADMUX
		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
		// ya que se setea el canal 0 queda el ADMUX limpio
	}

	fnqueue_add (adc_process);

	ADCSRA |= (1 << ADSC); //Poner el ADC a convertir
}

