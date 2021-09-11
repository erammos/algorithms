#pragma once
#include <iostream>
#include <stdexcept>
#include "linear_structure.h"
template<typename T>
class Node
{
    public:
	T data;
	Node * next;
};
template<typename T>
class List: public LinearStructure<T> 
{
    private:
	Node<T> * head;
	Node<T> * tail;
	int length;
    public:
	List()
	{
	    head = new Node<T>();
	    head->next = NULL;
	    tail = head;
	    length = 0;
	}
	virtual int size()
	{
	    return length;
	}
	virtual void insert(const T & value)
	{
	    tail->next = new Node<T>();
	    tail->next->data = value;
	    tail = tail->next;
	    tail->next = NULL;
	    length++;
	}
	virtual void insertAt(const T & value, int index)
	{  
	    Node<T> * current;
	    Node<T> * previous = head;
	    int i = 0;
	    for(current = head->next;current!=NULL;current=current->next)
	    {

		if(index == i)
		{
		    Node<T> * temp = new Node<T>();
		    temp->data = value;
		    temp->next = current;
		    previous->next = temp;
		    if(current == tail)
		    {
			tail = temp;
		    }
		    length++;
		    return;
		}
		previous = current;
		i++;
	    }

	}
	virtual int find(const T & value)
	{
	    Node<T> * current;
	    int index = 0;
	    for(current = head->next;current!=NULL;current=current->next)
	    {
		if(current->data == value)
		{
		    return index;
		}
		index++;
	    }
	    return -1;
	}
	virtual void remove(const T & value)
	{
	    Node<T> * current;
	    Node<T> * previous = head;
	    for(current = head->next;current!=NULL;current=current->next)
	    {
		if(current->data == value)
		{
		    if(current == tail)
		    {
			tail = previous;
		    }
		    previous->next = current->next;
		    length--;
		    delete current;
		    return;
		}

		previous = current;
	    }

	}
	virtual void removeAt(int index)
	{
	    remove(operator[](index));
	}
	virtual	const T & operator[](unsigned index)
	{
	    Node<T> * current;
	    int i = 0;
	    for(current = head->next;current!=NULL;current=current->next)
	    {
		if(i == index)
		{
		    return current->data;
		}
		i++;
	    }


	    throw std::out_of_range("index out of bounds");
	}	
};
