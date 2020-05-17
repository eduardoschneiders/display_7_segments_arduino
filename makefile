CC := g++
FILES := display.cpp fake_serial.cpp mock_arduino.cpp runtests.cpp

build: $(FILES)
	$(CC) -std=c++17 $(FILES) -o result.o 

test: build
	./result.o