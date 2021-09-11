#pragma once
template<typename T>
class LinearStructure
{
    public:
	virtual void insert(const T & value) = 0;
	virtual void insertAt(const T & value,int index) = 0;
	virtual int find(const T & value) = 0;
	virtual void remove(const T & value) = 0;
	virtual void removeAt(int index) = 0;
	virtual const T & operator[](unsigned index) = 0;
	virtual int size() = 0;
};
