#ifndef DISPLAY_H
#define DISPLAY_H
	
#include "arduino.h"

  class DISPLAY {
    public:
      DISPLAY(int pins[], int anode_mode, int d1, int d2=0, int d3=0, int d4=0);
      void setup();
      void showDigit(int digit, int d=0);
      void handle(int d);
		
    private:
      int _pins[7];
      int _anode_mode;
      int _d1, _d2, _d3, _d4;
      
      int _digits[10][7] = {
        {1,1,1,1,1,1,0}, // 0
        {0,1,1,0,0,0,0}, // 1
        {1,1,0,1,1,0,1}, // 2
        {1,1,1,1,0,0,1}, // 3
        {0,1,1,0,0,1,1}, // 4
        {1,0,1,1,0,1,1}, // 5
        {1,0,1,1,1,1,1}, // 6
        {1,1,1,0,0,0,0}, // 7
        {1,1,1,1,1,1,1}, // 8
        {1,1,1,1,0,1,1}, // 9
      };
      int convert_signal(int value);
	};

#endif