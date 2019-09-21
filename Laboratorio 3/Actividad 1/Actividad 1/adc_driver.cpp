
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
	
	//La entrada analogica se selecciona escribiendo MUX bits en ADMUX
	//El enable se hace desde el ADC enable bit ADEN en ADCSRA
	//Para hacer que interrumpa el adc que se trigeree cuando una conversion se completa
	
	adc_channel_cfg[ cfg->channel ].active = 1;

	if(!converting)
	{

		cli();
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);//  prescaler al máximo. para modular velocidad de muestreo
			
		ADMUX |= (1 << REFS0);      // voltaje referencia.
		ADMUX &= ~(1 << ADLAR);     // left aligned (sheet: 24.9.3.1/2).
			
		ADCSRA &= ~(1 << ADATE);     // deshabilitar auto trigger.
			
		ADCSRA |= (1 << ADEN);      // enable ADC.
		ADCSRA |= (1 << ADIE);
		// habilitar que el conversor interrumpa cuando haya terminado una conversion
		ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));//Canal predefinido 0
			
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
			//Serial.print("leo en el canal ");Serial.print (adc_channel_cfg[i]->channel);
			//Serial.print(" value adc ");Serial.println (adc_channel_cfg[i]->value);
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

