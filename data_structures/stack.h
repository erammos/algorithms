#pragma once
#include <iostream>
#include <stdexcept>
#include "array.h"
template<typename T>
class Stack 
{
    private:
	Array<T> array;
    public:
	const T & top()
	{
	    return array[array.size() - 1];
	}
	bool isEmpty()
	{
	    return array.size() == 0;
	}
	void pop()
	{
	    array.removeAt(array.size() - 1);
	}
	void push(const T & value)
	{
	    array.insert(value);
	}
};
