
#ifndef FAKESERIAL_H
#define FAKESERIAL_H

#include <stdio.h>
#include <iostream>

using namespace std;

class FakeSerial {
  public:
    void begin(unsigned long baud);
    void println();
    void println(int input);
    void println(string input);

    void print();
    void print(int input);
    void print(string input);
    void end();
};

#endif