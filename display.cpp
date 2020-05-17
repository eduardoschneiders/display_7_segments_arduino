#include "display.h"
#include <stdio.h>

DISPLAY::DISPLAY(int pins[], int anode_mode, int d1, int d2, int d3, int d4){
	_pins[0] = pins[0];
	_pins[1] = pins[1];
	_pins[2] = pins[2];
	_pins[3] = pins[3];
	_pins[4] = pins[4];
	_pins[5] = pins[5];
	_pins[6] = pins[6];
	_anode_mode = anode_mode;
	_d1 = d1;
}

void DISPLAY::setup(){
	pinMode(_d1, OUTPUT);

	for (int i = 0; i < 7; ++i){
		pinMode(_pins[i], OUTPUT);
  }
}


void DISPLAY::showDigit(int digit){
	digitalWrite(_d1, convert_signal(HIGH));

  for (int i = 0; i <= 6; ++i){
  	int signal = convert_signal(_digits[digit][i]);
    digitalWrite(_pins[i], signal);
  }
}

int DISPLAY::convert_signal(int value){
	return value ^ _anode_mode;
}