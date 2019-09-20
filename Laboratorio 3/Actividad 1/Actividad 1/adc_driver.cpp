#include "adc_driver.h"
#include "fnqueue.h"
#include <avr/interrupt.h>
#include <stdio.h>

static int volatile actual_channel = 0;
static int converting = 0;
static int cant_channels = 0;

struct adc_cfg adc_channel_cfg[MAX_CHANNELS];

int adc_init(struct adc_cfg *cfg)
{
	//Configuro todo para el canal inicial
	int ADC_channel = cfg->channel;
	if(ADC_channel>-1 && ADC_channel<6)
	{
		adc_channel_cfg[cfg->channel] = *cfg;
		adc_channel_cfg[cfg->channel].active = 1;

		actual_channel= ADC_channel;

		// si no estoy convirtiendo
		if(!converting)
		{
			ADMUX |= (ADC_channel);								//inicializar MUX0..2 segun el canal ingresado
			if(cant_channels==0)
			{
				ADMUX |= (1<<REFS0);								//Avcc (+5V) como voltaje de referencia
				ADCSRA |= (1<<ADPS1) | (1<<ADPS2) | (1<<ADPS0);
				ADCSRA |= (1<<ADEN) | ~(1<<ADATE) | (1<<ADSC) | (1<< ADIE);
				converting = 1;
			}
		}
		cant_channels++;
		return 1;
	}
	else
		return 0;
}

void process_adc()
{
	// Para cada canal en el adc_channel_cfg llamo a la funcion de callback que haya terminado la conversion
	int i = 0;
	for(i=0; i<MAX_CHANNELS; i++)
	{
		if(adc_channel_cfg[i].active)
		{
			if (adc_channel_cfg[i].finish_convertion)
			{
				fnqueue_add (adc_channel_cfg[i].callback);
			}
		}
	}
}

ISR(ADC_vect)
{
	adc_channel_cfg[actual_channel].value = ADC;
	adc_channel_cfg[actual_channel].finish_convertion = 1;

	fnqueue_add (process_adc);

	// buscar el proximo canal
	if(actual_channel == 0)
		actual_channel = 1;
	else
		actual_channel = 0;

	ADMUX |= (actual_channel); // seteo el proximo canal a convertir
	ADCSRA |= (1<<ADSC);//Poner el ADC a convertir
}

