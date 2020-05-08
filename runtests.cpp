#include <stdio.h>

#include "mock_arduino.h"

FakeSerial Serial;

#include "digits.c"

int main(){
  printf("===Starting code====\n");
  setup();

  while(1){
    loop();
  }

  
  return 0;
}
