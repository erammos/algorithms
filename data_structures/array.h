#pragma once
#include <stdexcept>
template<typename T>
class Array
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
	int size()
	{
	    return length;
	}
	Array():capacity(5),length(0)
	{
	    data = new T[capacity];
	}
	void insert(const T & value)
	{
	    data[length] = value;
	    length++; 
	    if(length == capacity)
	    {
		resize(capacity * 2);
	    } 
	}
	int find(const T & value)
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
	void remove(const T & value)
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
	const T & operator[](unsigned index)
	{
	    if(index >=length)
	    {
		throw std::out_of_range("index out of bounds");
	    }
	    return data[index];
	}	
};
