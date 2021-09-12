#pragma once
#include <iostream>
#include <stdexcept>
#include "array.h"
template<typename T>
class Queue 
{
    private:
	List<T> list;
    public:
	const T & front()
	{
	    return list[0];
	}
	bool isEmpty()
	{
	    return list.size() == 0;
	}
	void pop()
	{
	    list.removeAt(0);
	}
	void push(const T & value)
	{
	    list.insert(value);
	}
};
