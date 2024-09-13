all: p1 p2 p3

p1: p1.cc
	g++ -o p1 p1.cc

p2: p2.cc
	g++ -o p2 p2.cc

p3: p3.o power.o
	g++ -o p3 p3.o power.o

p3.o: p3.cc
	g++ -c p3.cc

power.o: power.cc
	g++ -c power.cc

clean:
	rm -f p1 p2 p3 p3.o power.o
