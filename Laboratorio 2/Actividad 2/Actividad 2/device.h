#ifndef DEVICE_H_
#define DEVICE_H_

#define NRO_TECLAS 5
#define TECLA1 1
#define TECLA2 2
#define TECLA3 3
#define TECLA4 0
#define TECLA5 4

void key_up_callback(void (* handler)(), int tecla);
void key_down_callback(void (* handler)(), int tecla);
void teclado_setup();

struct callback_str{
	void (* callback_Up) ();
	void (* callback_Down) ();
};

#endif /* DEVICE_H_ */