#include <stdio.h>

#include "mock_arduino.h"

FakeSerial Serial;

#include "digits.cpp"
int __anode_mode = 1;
int offset = 2;

void debug_number();
int convert_signal(int value);

int main(){
  printf("===Starting code====\n");
  setup();

  while(1){
    loop();
    debug_number();
  }

  return 0;
}

void debug_number(){
  if (convert_signal(_arduino_pins[0 + offset]))
    printf("  _ "); // A

  printf("\n");

  if (convert_signal(_arduino_pins[5 + offset]))
    printf("|");  // F

  printf("   ");

  if (convert_signal(_arduino_pins[1 + offset]))
    printf("|");  // B

  printf("\n");

  if (convert_signal(_arduino_pins[6 + offset]))
    printf("  - "); // G

  printf("\n");

  if (convert_signal(_arduino_pins[4 + offset]))
    printf("|");  // E

  printf("   ");

  if (convert_signal(_arduino_pins[2 + offset]))
    printf("|");  // C

  printf("\n");

  if (convert_signal(_arduino_pins[3 + offset]))
    printf("  - "); // D

  


  printf("\n================\n\n");
  
  // printf("%d", convert_signal(_arduino_pins[0]));
  // printf("%d", convert_signal(_arduino_pins[1]));
  // printf("%d", convert_signal(_arduino_pins[2]));
  // printf("%d", convert_signal(_arduino_pins[3]));
  // printf("%d", convert_signal(_arduino_pins[4]));
  // printf("%d", convert_signal(_arduino_pins[5]));
  // printf("%d", convert_signal(_arduino_pins[6]));
  // printf("%d", convert_signal(_arduino_pins[7]));
  // printf("%d", convert_signal(_arduino_pins[8]));
  // printf("%d", convert_signal(_arduino_pins[9]));
  // printf("%d", convert_signal(_arduino_pins[10)]);
  // printf("%d", convert_signal(_arduino_pins[11)]);
  // printf("%d", convert_signal(_arduino_pins[12)]);
  // printf("%d", convert_signal(_arduino_pins[13)]);
  printf("\n\n");
}

int convert_signal(int value){
  return value ^ __anode_mode;
}