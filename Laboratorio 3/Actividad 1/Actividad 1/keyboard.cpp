
#include <avr/interrupt.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "keyboard.h"
#include "adc_driver.h"

#define KEYBOARD_CHNL 0
static int16_t oldkey = -1;
uint16_t adc_key_val[NRO_TECLAS] = { 50, 230, 360, 535, 760 };
struct callback_str teclas_callback[ NRO_TECLAS ];
adc_cfg *cfg_keyboard;

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

void adc_keyboard_process(void)
{
	int16_t k;
	/*
	Serial.println("");
	Serial.println("llegue al callback del keyboard");
	Serial.println("");
	Serial.print("keyboard value ");Serial.println(cfg_keyboard.value);
	Serial.println("");
	*/
	
	uint16_t analogVal = cfg_keyboard->value;
	Serial.print("            keyboard adc ");Serial.println (analogVal);
	for (k = 0; k < NRO_TECLAS; k++)
	{
		if (analogVal < adc_key_val[k])
		{
			if(oldkey!=k)
			{
				oldkey = k;
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
/*

void adc_keyboard_callback(void)
{
	contador++;
	if(contador > 50)
	{
		Serial.println("");
		Serial.println("llegue al callback del keyboard");
		Serial.println("");
		fnqueue_add(adc_keyboard_process);
		contador = 0;
	}
}
*/

void keyboard_init(void)
{
	cfg_keyboard->channel = KEYBOARD_CHNL;
	cfg_keyboard->callback = adc_keyboard_process;
	cfg_keyboard->value = 0;
	cfg_keyboard->active = 0;
	cfg_keyboard->finish_convertion = 0;
	adc_init(cfg_keyboard);
}
