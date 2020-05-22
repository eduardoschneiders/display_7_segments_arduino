#include "fake_serial.h"

void FakeSerial::begin(unsigned long baud){
  // printf("Begin serial\n");
};

void FakeSerial::println(){
  cout << endl;
}

void FakeSerial::println(int input){
  cout << input << endl;
}

void FakeSerial::println(string input){
  cout << input << endl;
}

void FakeSerial::print(){
  return;
}

void FakeSerial::print(int input){
  cout << input;
}

void FakeSerial::print(string input){
  cout << input;
}

void FakeSerial::end(){
  return;
}
