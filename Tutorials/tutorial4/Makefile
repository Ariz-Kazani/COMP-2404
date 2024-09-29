all: test
	
test: test.cc Video.o HeapArrays.o StackArrays.o Date.o
	g++ -o test test.cc Video.o HeapArrays.o StackArrays.o Date.o
	
StackArrays.o:	StackArrays.h StackArrays.cc 
	g++ -c StackArrays.cc 
	
HeapArrays.o:	HeapArrays.h HeapArrays.cc 
	g++ -c HeapArrays.cc 

Video.o:	Video.h Video.cc
	g++ -c Video.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

	
clean:
	rm -f test *.o
