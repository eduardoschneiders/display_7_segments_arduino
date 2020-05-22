#include "debug_number.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>

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
  _d2 = d2;
  _d3 = d3;
  _d4 = d4;
}

void DISPLAY::setup(){
	pinMode(_d1, OUTPUT);

  if (_d2 && _d3 && _d4){
    pinMode(_d2, OUTPUT);
    pinMode(_d3, OUTPUT);
    pinMode(_d4, OUTPUT);
  }

	for (int i = 0; i < 7; ++i){
		pinMode(_pins[i], OUTPUT);
  }
}


void DISPLAY::showDigit(int digit, int d){
  if (digit > 9){
    printf("Digit (%d) greater than allowed digit 9!\n", digit);
    exit(EXIT_FAILURE);
  }

  if (!d)
    d = _d1;

  if (_d2 && _d3 && _d4){
    digitalWrite(_d1, convert_signal(LOW));
    digitalWrite(_d2, convert_signal(LOW));
    digitalWrite(_d3, convert_signal(LOW));
    digitalWrite(_d4, convert_signal(LOW));

    digitalWrite(d, convert_signal(HIGH));
  } else {
    digitalWrite(_d1, convert_signal(HIGH));
  }

  for (int i = 0; i < 7; ++i){
  	int signal = convert_signal(_digits[digit][i]);
    digitalWrite(_pins[i], signal);
  }

  debug_number();
}

void DISPLAY::handle(int d){
  // TODO receive number as param;
  // Split it in algarisms;
  // Call showDigit on that number;
  // Handle has to be in a loop;
  // It should be inside a thread, so it don't stop the main process

  // Split it in algarisms;
  printf("\n--------------------------Init handle--------------------------\n");
  printf("%d\n", d);

  if (_d2 && _d3 && _d4){

    int d1 = ((d % 10000) - (d % 1000)) / 1000;
    int d2 = ((d % 1000) - (d % 100)) / 100;
    int d3 = ((d % 100) - (d % 10)) / 10;
    int d4 = d % 10;

    printf("%d, %d, %d, %d\n", d1, d2, d3, d4);

    showDigit(d1, _d1);
    sleep(1);
    showDigit(d2, _d2);
    sleep(1);
    showDigit(d3, _d3);
    sleep(1);
    showDigit(d4, _d4);
  } else {
    showDigit(d, _d1);
  }

  printf("\n--------------------------End handle--------------------------\n");

}

int DISPLAY::convert_signal(int value){
	return value ^ _anode_mode;
}