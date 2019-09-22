/*
 * timers.h
 *
 * Created: 15/09/2019 19:56:25
 *  Author: brunn
 */ 

#ifndef TIMERS_H_
#define TIMERS_H_

	typedef struct Timer timer_t;

	timer_t *timers_new(void (*timeout_signal)(void));

	bool timers_start(timer_t* timer, uint16_t timeout_cs);

	bool timers_stop(timer_t *timer);


#endif /* TIMERS_H_ */