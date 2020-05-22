CC := g++

build: display.o fake_serial.o mock_arduino.o debug_number.o runtests.o
	$(CC) -std=c++17 display.o fake_serial.o mock_arduino.o debug_number.o runtests.o -o result.o 

display.o: display.cpp display.h
	g++ -std=c++17 -c display.cpp

fake_serial.o: fake_serial.cpp fake_serial.h
	g++ -std=c++17 -c fake_serial.cpp

mock_arduino.o: mock_arduino.cpp mock_arduino.h
	g++ -std=c++17 -c mock_arduino.cpp

debug_number.o: debug_number.cpp debug_number.h
	g++ -std=c++17 -c debug_number.cpp

runtests.o: runtests.cpp digits.cpp
	g++ -std=c++17 -c runtests.cpp

test: build
	./result.o

clean:
	rm *.o