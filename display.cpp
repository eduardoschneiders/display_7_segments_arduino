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

void DISPLAY::showDigit(int number){
  if (_d2 && _d3 && _d4){
    int* digits = splitDigits(number);

    renderDigit(digits[0], _d1);
    delay(10);
    renderDigit(digits[1], _d2);
    delay(10);
    renderDigit(digits[2], _d3);
    delay(10);
    renderDigit(digits[3], _d4);
    delay(10);
  } else {
    renderDigit(number, _d1);
  }
}

void DISPLAY::renderDigit(int digit, int d){
  if (digit > 9){
    printf("Digit (%d) greater than allowed digit 9!\n", digit);
    exit(EXIT_FAILURE);
  }

  if (!d)
    d = _d1;

  if (_d2 && _d3 && _d4){
    shutdownAllDigits();

    digitalWrite(d, convert_signal(HIGH));
  } else {
    digitalWrite(_d1, convert_signal(HIGH));
  }

  for (int i = 0; i < 7; ++i){
  	int signal = convert_signal(_digits[digit][i]);
    digitalWrite(_pins[i], signal);
  }

  printf("\nDigit: %d\n", d);
  debug_number();
}

int DISPLAY::convert_signal(int value){
	return value ^ _anode_mode;
}

int* DISPLAY::splitDigits(int digit){
  int* array = new int[4];

  array[0] = ((digit % 10000) - (digit % 1000)) / 1000;
  array[1] = ((digit % 1000) - (digit % 100)) / 100;
  array[2] = ((digit % 100) - (digit % 10)) / 10;
  array[3] = digit % 10;

  return array;
}

void DISPLAY::shutdownAllDigits(){
  digitalWrite(_d1, convert_signal(LOW));
  digitalWrite(_d2, convert_signal(LOW));
  digitalWrite(_d3, convert_signal(LOW));
  digitalWrite(_d4, convert_signal(LOW));
}