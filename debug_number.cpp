#include <stdio.h>
#include "debug_number.h"
#include "mock_arduino.h"


int __anode_mode = 1;
int offset = 2;

void debug_number(){
  if (convert_signal(_arduino_pins[0 + offset]))
    printf(" _ "); // A

  printf("\n");

  printf(convert_signal(_arduino_pins[5 + offset]) ? "|" : " ");  // F
  
  printf(" ");

  if (convert_signal(_arduino_pins[1 + offset]))
    printf("|");  // B
  
  printf("\n");

  if (convert_signal(_arduino_pins[6 + offset]))
    printf(" - "); // G

  printf("\n");

  
  printf(convert_signal(_arduino_pins[4 + offset]) ? "|" : " ");  // E

  printf(" ");

  if (convert_signal(_arduino_pins[2 + offset]))
    printf("|");  // C
  

  printf("\n");

  if (convert_signal(_arduino_pins[3 + offset]))
    printf(" - "); // D

  


  printf("\n================\n\n\n\n");  
}

int convert_signal(int value){
  return value ^ __anode_mode;
}