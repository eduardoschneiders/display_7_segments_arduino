#include <stdlib.h>

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

void setup() {
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

  Serial.begin(9600);
}

void writeDigit(int number);

void loop() {
  Serial.println();
  Serial.println(123);
  Serial.println("asdf");
  writeDigit(0);
  writeDigit(1);
  writeDigit(2);
  writeDigit(3);
  writeDigit(4);
  writeDigit(5);
  writeDigit(6);
  writeDigit(7);
  writeDigit(8);
  writeDigit(9);

  Serial.println("===================");

  delay(1000);
  // exit(1);
}

void writeDigit(int number){
  int digits[10][7] = {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0},
    {0,0,0,0,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,1},
    {0,0,0,0,1,1,0},
    {0,0,0,0,1,1,1},
    {0,0,0,1,0,0,0},
    {0,0,0,1,0,0,1},
  };

  for (int i = 0; i < 7; i++) {
    Serial.print(digits[number][i]);
  }

  Serial.println();
}


