#ifndef DEVICE_H_
#define DEVICE_H_

#define NRO_TECLAS 5
#define TECLAUP 1
#define TECLADOWN 2
#define TECLALEFT 3
#define TECLARIGHT 0
#define TECLASELECT 4

void key_up_callback(void (* handler)(), int tecla);
void key_down_callback(void (* handler)(), int tecla);
void teclado_setup();

struct callback_str{
	void (* callback_Up) ();
	void (* callback_Down) ();
};

#endif /* DEVICE_H_ */