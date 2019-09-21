
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "critical.h"
#include "adc_driver.h"

static int volatile actual_channel = 0;
static int converting = 0;

struct adc_cfg adc_channel_cfg[MAX_CHANNELS];

int adc_init(struct adc_cfg *cfg)
{

	adc_channel_cfg[ cfg->channel ] = *cfg;
	adc_channel_cfg[ cfg->channel ].active = 1;

	if(!converting)
	{

		cli();
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);//  prescaler 
			
		ADMUX |= (1 << REFS0);
		ADMUX &= ~(1 << ADLAR);
			
		ADCSRA &= ~(1 << ADATE);     // deshabilitar el Auto Trigger.
			
		ADCSRA |= (1 << ADEN);      // habilitar ADC.
		ADCSRA |= (1 << ADIE);

		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
			
		ADCSRA |= (1 << ADSC); 
		// habilito las interrupciones
		sei();
		converting = 1;
	}
	return 1;
}

void adc_process()
{
	// Para cada canal en el adc_channel_cfg llamo a la funcion de callback que haya terminado la conversion
	for(int i=0; i<MAX_CHANNELS; i++)
	{
		if (adc_channel_cfg[i].finish_convertion)
		{
			adc_channel_cfg[i].callback(adc_channel_cfg[i].value);
			adc_channel_cfg[i].finish_convertion = 0;
		}
	}
}

ISR(ADC_vect)
{
	uint16_t value_adc = (ADCL) | (ADCH << 8);
	adc_channel_cfg[actual_channel].value = value_adc;
	adc_channel_cfg[actual_channel].finish_convertion = 1;

	if(!actual_channel)
	{
		actual_channel = 1;

		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
		
		ADMUX |= 1<<MUX0;
	}
	else
	{
		actual_channel = 0;

		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	}

	fnqueue_add (adc_process);

	ADCSRA |= (1 << ADSC); //Poner el ADC a convertir


}

