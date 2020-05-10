#include <stdlib.h>
#include "display.h"

int d1 = 9;
int d2 = 10;
int d3 = 11;
int d4 = 12;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int pins[] = {a,b,c,d,e,f,g};
int anode_mode = 1;

DISPLAY display(pins, anode_mode, d1);
void setup() {
  display.setup();
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < 10; i++){
    Serial.println(i);
    display.showDigit(i);
  }

  // delay(1000 * 10);
  exit(0);
}