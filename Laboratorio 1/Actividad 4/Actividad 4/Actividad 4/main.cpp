/*
 Migración a código AVR del ejemplo Blink de Arduino:
 http://www.arduino.cc/en/Tutorial/Blink
 */
#define F_CPU 16000000U
#include <avr/io.h>
#include <util/delay.h>

int buttonState;
int buttonStateAux;
int pinValue = 0;
int counterDelay = 0;
int cuarto_caso = 1;

int main()
{
	//Inicializar el pin del pulsador como entrada
	DDRD &= ~(1<<DDD2);
	//Inicializar el pin del led como salida
	DDRB |= (1<<DDB5);

	while (1)
	{
		//Leer el estado del pulsador
		buttonStateAux = PIND & (1<<PD2);

		//Si cambió el estado del pulsador...
		if (buttonStateAux != pinValue)
		{
			//Se espera un tiempo para evitar leer el ruido del rebote del pulsador
			_delay_ms(50);

			//Se vuelve a leer el estado del pulsador
			buttonStateAux = PIND & (1<<PD2);

			//Si el cambio se mantiene, se interpreta como evento de keydown/keyup válido
			if (buttonStateAux != pinValue)
			{
				//El pulso es válido, se implementa la lógica del sistema

				//Si no está presionado el pulsador (se detectó un keyup)...
				if (!buttonStateAux)
				{
					buttonState = (buttonState + 1) % 6;
				}

				//Si hubo cambios válidos actualizo el valor de lectura anterior
				pinValue = buttonStateAux;
			}
		}
		switch (buttonState)
		{
			case 0:
				PORTB |= (1<<PB5);	//Enciende el Led
			break;
			case 1:
				if(counterDelay>=100)
				{
					PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
					counterDelay = 0;
				}else
				{
					_delay_ms(10);
					counterDelay++;
				}
			break;
			case 2:
				if(counterDelay>=50)
				{
					PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
					counterDelay = 0;
				}else
				{
					_delay_ms(10);
					counterDelay++;
				}
			break;
			case 3:
				if(counterDelay>=25)
				{
					PORTB ^= (1<<PB5); //Se modifica el estado del led (toggle vía XOR)
					counterDelay = 0;
				}else
				{
					_delay_ms(10);
					counterDelay++;
				}
			break;
			case 4:
			if(cuarto_caso)
			{
				if(counterDelay>=50)
				{
					PORTB &= ~(1<<PB5);     //Apaga el Led
					counterDelay = 0;
					cuarto_caso = 0;
				}else
				{
					_delay_ms(10);
					counterDelay++;
				}
			}else{
				if(counterDelay>=100)
				{
					PORTB |= (1<<PB5);	//Enciende el Led
					counterDelay = 0;
					cuarto_caso = 1;
				}else
				{
					_delay_ms(10);
					counterDelay++;
				}
			}
			break;
			case 5:
				PORTB &= ~(1<<PB5);     //Apaga el Led
			break;
		}
		
	}
}
