#include <stdio.h>
#include "debug_number.h"
#include "mock_arduino.h"

int __anode_mode = 1;
int _a = 2;
int _b = 3;
int _c = 4;
int _d = 5;
int _e = 6;
int _f = 7;
int _g = 8;

void debug_number(){
  if (convert_signal(_arduino_pins[_a]))
    printf(" _ "); // A

  printf("\n");

  printf(convert_signal(_arduino_pins[_f]) ? "|" : " ");  // F
  
  printf(" ");

  if (convert_signal(_arduino_pins[_b]))
    printf("|");  // B
  
  printf("\n");

  if (convert_signal(_arduino_pins[_g]))
    printf(" - "); // G

  printf("\n");
  
  printf(convert_signal(_arduino_pins[_e]) ? "|" : " ");  // E

  printf(" ");

  if (convert_signal(_arduino_pins[_c]))
    printf("|");  // C

  printf("\n");

  if (convert_signal(_arduino_pins[_d]))
    printf(" - "); // D

  


  printf("\n================\n\n\n\n");  
}

int convert_signal(int value){
  return value ^ __anode_mode;
}