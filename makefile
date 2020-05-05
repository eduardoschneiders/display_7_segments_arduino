CC := g++
FILES := fake_serial.cpp runtests.cpp

build: $(FILES)
	$(CC) $(FILES) -o result.o 

test:
	$(CC) test.cpp -o test.o