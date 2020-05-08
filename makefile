CC := g++
FILES := fake_serial.cpp mock_arduino.cpp runtests.cpp

build: $(FILES)
	$(CC) $(FILES) -o result.o 

test: build
	./result.o