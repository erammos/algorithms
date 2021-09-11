#pragma once
#include <stdexcept>
#include "linear_structure.h"
template<typename T>
class Array:public LinearStructure<T>
{
    private:

	T * data;
	int capacity;
	int length;

	void resize(int cap)
	{
	    capacity = cap;
	    T * temp = new T[capacity];
	    for(int i = 0;i < length;i++)
	    {
		temp[i] = data[i];
	    }
	    delete data;
	    data = temp;
	}

    public:

	int cap()
	{
	    return capacity;
	}
	virtual	int size()
	{
	    return length;
	}
	Array():capacity(5),length(0)
	{
	    data = new T[capacity];
	}
	virtual	void insert(const T & value)
	{
	    data[length] = value;
	    length++; 
	    if(length == capacity)
	    {
		resize(capacity * 2);
	    } 
	}
	virtual	void insertAt(const T & value, int index)
	{

	    int aux = data[index];
	    for(int i = index + 1;i < length + 1;i++)
	    {
		std::swap(aux,data[i]);
	    }
	    data[index] = value;
	    length++;
	    if(length == capacity)
	    {
		resize(capacity * 2);
	    }

	}
	virtual int find(const T & value)
	{
	    for(int i = 0;i < length;i++)
	    {
		if(data[i] == value)
		{
		    return i;
		}
	    }
	    return -1;
	}
	virtual void remove(const T & value)
	{
	    if(length <= 0) return;

	    int index = find(value);

	    if(index < 0) throw std::logic_error("index not found");
	    for(int i = index;i < length - 1;i++)
	    {
		data[i] = data[i + 1];
	    }
	    length--;

	    if(length == capacity / 4)
	    {
		resize(capacity / 2);
	    }
	}
	virtual	const T & operator[](unsigned index)
	{
	    if(index >=length)
	    {
		throw std::out_of_range("index out of bounds");
	    }
	    return data[index];
	}	
};
