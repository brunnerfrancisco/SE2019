//#define F_CPU 16000000U
#include <avr/interrupt.h>
#include <stdint.h>
#include "keyboard.h"
#include "fnqueue.h"
#include "Arduino.h"
#include "adc_driver.h"

static int16_t oldkey = -1;
int16_t adc_key_val[NRO_TECLAS] = { 50, 150, 360, 535, 760 };
struct callback_str teclas_callback[ NRO_TECLAS ];
adc_cfg cfg_keyboard;

void key_up_callback(void (* handler)(), int tecla)
{
	if(tecla>=0 && tecla < NRO_TECLAS)
		teclas_callback[tecla].callback_Up = handler;
}

void key_down_callback(void (* handler)(), int tecla)
{
	if(tecla>=0 && tecla < NRO_TECLAS)
		teclas_callback[tecla].callback_Down = handler;
}

void adc_process()
{
	int16_t k;
	int8_t analogVal = cfg_keyboard.value;
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

void keyboard_init(void)
{
	cfg_keyboard.channel = 0;
	cfg_keyboard.callback = adc_process;
	cfg_keyboard.value = 0;
	cfg_keyboard.active = 0;
	cfg_keyboard.finish_convertion = 0;
	adc_init(&cfg_keyboard);
}
