all: a1

a1: main.o Campground.o Campsite.o Camper.o Category.o Date.o Tester.o
	g++ -o a1 main.o Campground.o Campsite.o Camper.o Category.o Date.o Tester.o

main.o: main.cc Campground.h Tester.h
	g++ -c main.cc

Campground.o: Campground.cc Campground.h
	g++ -c Campground.cc

Campsite.o: Campsite.cc Campsite.h
	g++ -c Campsite.cc

Camper.o: Camper.cc Camper.h
	g++ -c Camper.cc

Category.o: Category.cc Category.h
	g++ -c Category.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

clean:
	rm -f a1 *.o