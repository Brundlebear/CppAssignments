//SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector
{
private:
	T* aptr;
	int arraySize;
	void memError();
	void subError();

public:
	SimpleVector()
	{
		aptr = 0;
		arraySize = 0;
	}

	SimpleVector(int);

	SimpleVector(const SimpleVector&);

	~SimpleVector();

	int size() const
	{
		return arraySize;
	}

	T getElementAt(int position);

	void push_back(T);
	T pop_back();

	T& operator[] (const int&);
};

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	for (int count = 0; count < arraySize; count++)
	{
		*(aptr + count) = T(rand() %100);
	}
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	if (aptr = 0)
	{
		memError();
	}

	for (int count = 0; count < arraySize; count++)
	{
		*(aptr + count) = *(obj.aptr + count);
	}

}

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
	{
		delete[] aptr;
	}
}

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		subError();
	}
	return aptr[sub];
}

template <class T>
T& SimpleVector<T>::operator[](const int& sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		subError();
	}
	return aptr[sub];
}

template <class T>
void SimpleVector<T>::push_back(T newElement)
{
	int index = 0;
	int newSize = arraySize + 1;
	T* newArray = new T[newSize];
	for (index = 0; index < arraySize; index++)
	{
		*(newArray + index) = *(aptr + index);
	}
	*(newArray + (newSize - 1)) = newElement;

	aptr = newArray;
	arraySize = newSize;

}

template <class T>
T SimpleVector<T>::pop_back()
{
	int index = 0;
	T returnValue = *(aptr + (arraySize - 1));
	int newSize = arraySize - 1;
	T* newArray = new T[newSize];

	for (index = 0; index < newSize; index++)
	{
		*(newArray + index) = *(aptr + index);
	}

	aptr = newArray;
	arraySize = newSize;
	return returnValue;

}
#endif
#pragma once