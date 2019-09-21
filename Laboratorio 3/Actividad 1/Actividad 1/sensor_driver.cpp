
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "sensor_driver.h"
#include "timers.h"
#include "adc_driver.h"

#define F_SAMPLE_SENSOR 15 // frecuencia a la que muestrea el sensor cada 15cs.
#define SENSOR_CHN 1 // el canal del ADC que va a utilizar el sensor

bool store = false; // flag que le dice al adc que llame al callback con el ultimo muestreo

static uint16_t value_store = 0;

// callback del driver para responder a la solicitud de temperaturas del main
void (* callback_sensor) (int);

// estructura donde se va a almacenar la configuracion del ADC
adc_cfg adc_sensor;

void process_callback_sensor()
{
	callback_sensor (value_store);
}

void adc_sensor_callback(uint16_t value)
{
	// si tengo que guardar el valor llamo al callback
	if(store)
	{
		store = false;
		value_store = value;
		//Serial.print("sensor adc ");Serial.println (adc_sensor->value);
		fnqueue_add ( process_callback_sensor );
	}
}

void timer_callback()
{
	store = true;
}

int sensor_init(void (* callback_sen)(int))
{
	callback_sensor = callback_sen;

	// inicializo el adc
	adc_sensor.channel = SENSOR_CHN;
	adc_sensor.callback = adc_sensor_callback;
	adc_sensor.value = 0;
	adc_sensor.active = 0;
	adc_sensor.finish_convertion = 0;
	adc_init(&adc_sensor);
	
	// inicializo el timer
	timer_t *timer = timers_new(timer_callback);
	timers_start (timer,F_SAMPLE_SENSOR);
	return true;
}