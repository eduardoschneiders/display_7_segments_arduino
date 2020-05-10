#ifndef DISPLAY_H
#define DISPLAY_H
	
#include "arduino.h"

	class DISPLAY {
		public:
			DISPLAY(int pins[]);
			void setup();
			void showDigit(int a);
		
		private:
			int _pins[7];
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
	};

#endif