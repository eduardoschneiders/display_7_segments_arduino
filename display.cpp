#include "display.h"
#include <stdio.h>

DISPLAY::DISPLAY(int pins[]){	
	_pins[0] = pins[0];
	_pins[1] = pins[1];
	_pins[2] = pins[2];
	_pins[3] = pins[3];
	_pins[4] = pins[4];
	_pins[5] = pins[5];
	_pins[6] = pins[6];
}

void DISPLAY::setup(){
	for (int i = 0; i < 7; ++i){
		pinMode(_pins[i], OUTPUT);
  }
}


void DISPLAY::showDigit(int digit){
  for (int i = 0; i < 7; ++i){
  	int signal = _digits[digit][i];
    digitalWrite(_pins[i], signal);
  }
}