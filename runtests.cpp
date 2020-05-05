#include <stdio.h>

#include "fake_serial.h"

FakeSerial Serial;

#include "mock_arduino.h"

#include "digits.c"


int main(){
  printf("===Starting code====\n");
  setup();

  while(1){
    loop();
  }

  
  return 0;
}
