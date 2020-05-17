CC := g++

build: display.o fake_serial.o mock_arduino.o runtests.o
	$(CC) display.o fake_serial.o mock_arduino.o runtests.o -o result.o 

display.o: display.cpp display.h
	g++ -std=c++17 -c display.cpp

fake_serial.o: fake_serial.cpp fake_serial.h
	g++ -std=c++17 -c fake_serial.cpp

mock_arduino.o: mock_arduino.cpp mock_arduino.h
	g++ -std=c++17 -c mock_arduino.cpp

runtests.o: runtests.cpp
	g++ -std=c++17 -c runtests.cpp

test: build
	./result.o

clean:
	rm *.o