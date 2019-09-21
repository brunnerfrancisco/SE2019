
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "critical.h"
#include "adc_driver.h"

static int volatile actual_channel = 0;
static int converting = 0;
static int cant_channels = 0;

struct adc_cfg adc_channel_cfg[MAX_CHANNELS];

int adc_init(struct adc_cfg *cfg)
{
	//Configuro todo para el canal inicial
	critical_begin ();
	int ADC_channel = cfg->channel;
	if(ADC_channel>-1 && ADC_channel<MAX_CHANNELS)
	{
		adc_channel_cfg[cfg->channel] = *cfg;
		adc_channel_cfg[cfg->channel].active = true;

		// si no estoy convirtiendo
		if(!converting)
		{

			actual_channel = ADC_channel;
			ADMUX |= (ADC_channel); //inicializar MUX0..2 segun el canal ingresado

			// si es el primer canal configuro el ADC con la configuracion general
			if(cant_channels == 0)
			{
				//ADCSRB = 0; // este registro no lo deberia tocar segun el datasheet
				
				ADCSRA |= (1<<ADEN); // habilito el adc "lo prendo" segun el datasheet
				ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // estos bit setean el prescaler lo pongo en 16
				ADCSRA |= (1<< ADIE); // este bit activa la interrupcion por conversion completa ISR(ADC_Vect)
				ADCSRA |= ~(1<<ADATE); // este bit en 0 desactiva el AutoTrigger segun el datasheet
				ADCSRA |= (1<<ADSC); // este es el bit que pone a funcionar el ADC segun el datasheet
			}
			converting = 1;
		}
		cant_channels++;
		critical_end ();
		return 1;
	}
	else
		return 0;
}

void adc_process()
{
	// Para cada canal en el adc_channel_cfg llamo a la funcion de callback que haya terminado la conversion
	critical_begin();
	int i = 0;
	for(i=0; i<MAX_CHANNELS; i++)
	{
		if(adc_channel_cfg[i].active)
		{
			if (adc_channel_cfg[i].finish_convertion)
			{
				Serial.print("leo en el canal ");Serial.print (adc_channel_cfg[i].channel);
				Serial.print("value adc ");Serial.println (adc_channel_cfg[i].value);
				fnqueue_add (adc_channel_cfg[i].callback);
				adc_channel_cfg[i].finish_convertion = 0;
			}
		}
	}
	critical_end();
}

ISR(ADC_vect)
{
	adc_channel_cfg[actual_channel].value = ADC;//ADCH<<8 | ADCL;
	adc_channel_cfg[actual_channel].finish_convertion = 1;

	fnqueue_add (adc_process);

	/*// buscar el proximo canal
	if(actual_channel == 0)
		actual_channel = 1;
	else
		actual_channel = 0;*/

	ADMUX = (actual_channel); // seteo el proximo canal a convertir

	ADMUX |= (1<<MUX3);

	ADCSRA |= (1<<ADSC); //Poner el ADC a convertir
}

