#include <stdio.h>

#include "mock_arduino.h"
#include "debug_number.h"

FakeSerial Serial;
struct Test {
  int a;
  int b;
  const char* name = "asdf";
};

#include "digits.cpp"

int convert_signal(int value);

int main(){
  printf("===Starting code===\n");
  Test te;
  te.a = 1;
  te.b = 2;
  te.name = "eduardo schneiders";


  const char* text = "eduardo";

  setup();

  while(1) {
    loop();
    // debug_number();
  }

  return 0;
}

