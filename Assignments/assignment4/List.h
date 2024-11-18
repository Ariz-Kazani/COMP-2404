#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <typename T>
class List
{

public:
	// constructor
	List(int (*compare)(T, T));

	// destructor
	~List();

	// other
	void add(T t);
	T remove(int index);
	T get(int index) const;
	int getSize() const;
	bool isFull() const;
	void clear();

private:
	int (*compare)(T, T);
	int numElements;
	T *elements;
};

template <typename T>
List<T>::List(int (*compare)(T t1, T t2))
{
	elements = new T[MAX_ARRAY];
	numElements = 0;
	this->compare = compare;
}

template <typename T>
List<T>::~List()
{
	delete[] elements;
}

template <typename T>
void List<T>::add(T t)
{
	if (numElements >= MAX_ARRAY)
	{
		cerr << "List is full" << endl;
		exit(1);
	}
	int i = numElements - 1;
	while (i >= 0 && compare(elements[i], t) > 0)
	{
		elements[i + 1] = elements[i];
		--i;
	}
	elements[i + 1] = t;
	++numElements;
}

template <typename T>
T List<T>::remove(int index)
{
	if (index < 0 || index >= numElements)
	{
		cerr << "List index out of bounds" << endl;
		exit(1);
	}

	T temp = elements[index];

	for (int i = index; i < numElements - 1; ++i)
	{
		elements[i] = elements[i + 1];
	}
	--numElements;
	return temp;
}

template <typename T>
int List<T>::getSize() const
{
	return numElements;
}

template <typename T>
bool List<T>::isFull() const
{
	return numElements >= MAX_ARRAY;
}

template <typename T>
T List<T>::get(int index) const
{
	if (index < 0 || index >= numElements)
	{
		cerr << "List index out of bounds" << endl;
		exit(1);
	}
	return elements[index];
}

template <typename T>
void List<T>::clear()
{
	for (int i = 0; i < numElements; ++i)
	{
		delete elements[i];
	}
	numElements = 0;
}

#endif