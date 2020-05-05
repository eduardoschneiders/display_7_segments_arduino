#include <stdio.h>


const int OUTPUT = 0;
const int INPUT = 1;
const int LOW = 0;
const int HIGH = 1;

#include "fake_serial.h"

FakeSerial Serial;

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

#include "digits.c"


int main(){
  printf("===Starting code====\n");
  setup();

  while(1){
    loop();
  }

  
  return 0;
}
