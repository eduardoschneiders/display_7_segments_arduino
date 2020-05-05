
#include "fake_serial.h"

void FakeSerial::begin(unsigned long baud){
  printf("Begin serial\n");
};

void FakeSerial::println(){
  return;
}

void FakeSerial::println(int input){
  cout << input << endl;
}

void FakeSerial::println(string input){
  cout << input << endl;
}

void FakeSerial::end(){
  return;
}
