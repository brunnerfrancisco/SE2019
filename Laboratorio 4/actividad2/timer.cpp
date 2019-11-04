
#include <avr/io.h>
#include <stdint.h>
#include "Arduino.h"
#include "fnqueue.h"
#include "critical.h"
#include "timer.h"
#include <avr/interrupt.h>

static volatile uint16_t count_timer = 0;

void (*timeout_signal) () = NULL;

void timer_init(void (* callback)(void))
{
	critical_begin();
	TCCR2A = 0;// set entire TCCR2A register to 0
	TCCR2B = 0;// same for TCCR2B
	TCCR2A |= (1 << WGM21);  // ctc for timer 0
	TIMSK2 |= (1<<TOIE2); //setea la interrupcion por overflow
	TCNT2 = 0; //set timer en 0
	TCCR2B |= (1 << CS21) | (1 << CS20);  // CS#1 y CS#0 bits -> Timer2 preescaler = 64
	critical_end();

	timeout_signal=callback;
	
}

ISR(TIMER2_OVF_vect)
{
	TCNT2 = 0;
	count_timer++;
	if(count_timer==10) // cuento 10 interrupciones de 1,024ms -> llamo a la funcion de callback cada 10,24ms
	{
		count_timer = 0;
		fnqueue_add(timeout_signal);
	}
}