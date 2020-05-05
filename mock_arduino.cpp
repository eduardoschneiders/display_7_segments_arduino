#include "mock_arduino.h"

void pinMode(int pin, int mode){
  printf("pinMode ");
  printf("pin: %d ", pin);
  printf("mode: %d\n", mode);
}

void digitalWrite(int pin, int mode){
  printf("digitalWrite ");
  printf("pin: %d ", pin);
  printf("mode: %d\n", mode);
}

void delay(int time){
  usleep(time * 1000);
}