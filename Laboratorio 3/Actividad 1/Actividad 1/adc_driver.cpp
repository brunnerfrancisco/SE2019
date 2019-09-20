#include "adc_driver.h"
#include <avr/interrupt.h>

static int volatile actual_channel = 0;
static int converting = 0;
static int cant_channels = 0;

static volatile int counter_switch;

struct adc_cfg adc_channel_cfg[MAX_CHANNELS];

int adc_init(struct adc_cfg *cfg)
{
	int ret = 1;
	//Configuro todo para el canal inicial
	int ADC_channel = cfg->channel;
	if(ADC_channel>-1 && ADC_channel<6)
	{
		adc_channel_cfg[cfg->channel] = *cfg;
		adc_channel_cfg[cfg->channel].active = 1;

		actual_channel= ADC_channel;

		// si no estoy convirtiendo
		if(cant_channels==0)
		{
			//ADMUX &= ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0);	//clear MUX0...3
			ADMUX |= (ADC_channel);								//inicializar MUX0..2 segun el canal ingresado
			ADMUX |= (1<<REFS0);								//Avcc (+5V) como voltaje de referencia

			ADCSRA |= (1<<ADPS2);
			ADCSRA |= (1<<ADIE);
			ADCSRA |= (1<<ADEN);								//Activar el ADC y activar la interrupcion al completar una conversion
			ADCSRA |= (1<<ADSC);								//Poner el ADC a convertir
			
			converting = 0;
			
		}
		cant_channels++;
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return ret;
}

void adc_loop()
{
	// Para cada canal en el adc_channel_cfg
	int i = 0;
	for(i=0; i<MAX_CHANNELS; i++)
	{
		if (adc_channel_cfg[i].finish_convertion)
		{
			adc_channel_cfg[i].callback(i);
		}
	}
}

ISR(ADC_vect)
{
	adc_channel_cfg[actual_channel].value = ADC;
	adc_channel_cfg[actual_channel].finish_convertion = 1;

	fnqueue_add (adc_loop);

	// buscar el proximo canal
	if(actual_channel == 0)
		actual_channel = 1;
	else
		actual_channel = 0;

	ADCSRA |=  (1<<ADSC) ; // con esto le digo que arranque a convertir denuevo
}

