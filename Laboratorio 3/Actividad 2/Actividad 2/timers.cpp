/*
 * timers.cpp
 *
 * Created: 15/09/2019 19:56:11
 *  Author: brunn
 */ 

#define MAX_TIMERS 16

#include <stdint.h> 
#include <stdio.h>
#include <stdint.h>

#include "Arduino.h"
#include "fnqueue.h"
#include "critical.h"
#include "timer.h"
#include "timers.h"

struct Timer
{
	void (* timeout_signal)(void); // asociated timer callback
	uint16_t timeout_cs;
	uint16_t count_timeout_cs;
	bool state;
};

static int index = 0;

static timer_t timers_SW[MAX_TIMERS];

void callback_timer (void)
{
	// update count_timeout_cs of all timers if OVF -> callback (cont_timeot_cs == timeout_cs)

	int i = 0;
	for (i = 0; i < index; i++)
	{
		if(timers_SW[i].state)
		{
			timers_SW[i].count_timeout_cs++;
			if(timers_SW[i].count_timeout_cs >= timers_SW[i].timeout_cs)
			{
				fnqueue_add (timers_SW[i].timeout_signal);
				timers_SW[i].count_timeout_cs = 0;
			}
		}
	}
}

timer_t *timers_new(void (* timeout_signal)(void))
{
	if(index < MAX_TIMERS)
	{
		timers_SW[index].count_timeout_cs = 0;
		timers_SW[index].state = false;
		timers_SW[index].timeout_cs = 0;
		timers_SW[index].timeout_signal = timeout_signal;
		if(index == 0)
		{
			timer_init(callback_timer);
		}
		index++;
		return &timers_SW[index-1];
	}
	
	return NULL;
}

bool timers_start(timer_t* timer, uint16_t timeout_cs)
{
	timer->timeout_cs = timeout_cs;
	timer->count_timeout_cs = 0;
	timer->state = true;

	return true;
}

bool timers_stop(timer_t *timer)
{
	timer->timeout_cs = 0;
	timer->state = false;

	return true;
}

