//#define F_CPU 16000000U
#include "Arduino.h"
#include <LiquidCrystal.h>
#include "fnqueue.h"
#include "device.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void up_keyUp(){
	lcd.setCursor(0,1);
	lcd.print("UP KeyUP        ");
}
void down_keyUp(){
	lcd.setCursor(0,1);
	lcd.print("DOWN KeyUP      ");
}
void up_keyDown(){
	lcd.setCursor(0,1);
	lcd.print("UP KeyDown      ");
}
void down_keyDown(){
	lcd.setCursor(0,1);
	lcd.print("DOWN KeyDown    ");
}
void up_keyRight(){
	lcd.setCursor(0,1);
	lcd.print("UP KeyRight     ");
}
void down_keyRight(){
	lcd.setCursor(0,1);
	lcd.print("DOWN KeyRight   ");
}
void up_keyLeft(){
	lcd.setCursor(0,1);
	lcd.print("UP KeyLeft      ");
}
void down_keyLeft(){
	lcd.setCursor(0,1);
	lcd.print("DOWN KeyLeft    ");
}
void up_keySelect(){
	lcd.setCursor(0,1);
	lcd.print("UP KeySelect    ");
}
void down_keySelect(){
	lcd.setCursor(0,1);
	lcd.print("DOWN KeySelect  ");
}

// these constants won't change.  But you can change the size of
// your LCD using them:
const uint8_t numRows = 2;
const uint8_t numCols = 16;

void setup()
{
	lcd.begin(numCols,numRows);
	teclado_setup();
	
	fnqueue_init();
	
	key_up_callback(up_keyUp, TECLA1);
	key_down_callback(down_keyUp, TECLA1);
	key_up_callback(up_keyDown, TECLA2);
	key_down_callback(down_keyDown, TECLA2);
	key_up_callback(up_keyLeft, TECLA3);
	key_down_callback(down_keyLeft, TECLA3);
	key_up_callback(up_keyRight, TECLA4);
	key_down_callback(down_keyRight, TECLA4);
	key_up_callback(up_keySelect, TECLA5);
	key_down_callback(down_keySelect, TECLA5);
	
	lcd.setCursor(0, 0);
	lcd.print("Key Pad Test");
	lcd.setCursor(0, 1);
	lcd.print("Sist.Emb. 2019");
}

void loop()
{
	fnqueue_run();
}
