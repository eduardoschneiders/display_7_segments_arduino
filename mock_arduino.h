#ifndef MOCKARDUINO_H
#define MOCKARDUINO_H

#include <stdio.h>
#include <unistd.h>

#include "fake_serial.h"

const int OUTPUT = 0;
const int INPUT = 1;
const int LOW = 0;
const int HIGH = 1;

void pinMode(int pin, int mode);
void digitalWrite(int pin, int mode);
void delay(int time);

#endif