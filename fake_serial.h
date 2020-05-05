
#ifndef FAKESERIAL_H
#define FAKESERIAL_H

#include <stdio.h>
#include <iostream>

using namespace std;

class FakeSerial {
  public:
    void begin(unsigned long baud);
    void println();
    void println(int a);
    void println(string input);
    void end();
};

#endif