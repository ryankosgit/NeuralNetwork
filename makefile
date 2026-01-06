all: driver.o
	g++ driver.o -o nn.x

driver.o: driver.cpp nn.h nn.cpp
	g++ -c driver.cpp

run: all
	./nn.x

clean:
	rm -f *.o *.x