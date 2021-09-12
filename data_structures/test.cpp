#include "array.h"
#include <cassert>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
using namespace std;

void test_queue()
{
    int test_data[10] = { 0,1,2,3,4,5,6,7,8,9};
    Queue<int> q;
    int n = 10;
    for(int i = 0; i < n;i++)
    {
	q.push(i);
    }

    int index = 0; 
    while(!q.isEmpty())
    {
	assert(q.front() == test_data[index]);
	q.pop();
	index++;
    }


}
void test_stack()
{

    int test_data[10] = { 9,8,7,6,5,4,3,2,1,0};
    Stack<int> st;
    int n = 10;
    for(int i = 0; i < n;i++)
    {
	st.push(i);
    }

    int index = 0; 
    while(!st.isEmpty())
    {
	assert(st.top() == test_data[index]);
	st.pop();
	index++;
    }

}
void test_structure(LinearStructure<int> &arr)
{
    int test_data[6] = { 1, 2, 6, 7, -1,9};

    int n = 10; 
    for(int i = 0; i < n;i++)
    {
	arr.insert(i);
    }

    assert(arr.find(4) == 4);

    arr.remove(0);
    arr.remove(9);
    arr.remove(4);

    arr.remove(8);
    assert(arr.find(8) == -1);

    arr.remove(3);
    arr.remove(5);
    arr.insert(9);

    arr.insertAt(-1,1);
    arr.insertAt(-1,5);
    arr.removeAt(1);
    for(int i = 0; i < arr.size();i++)
    {
	assert(arr[i] == test_data[i]);
    }
}
int main()
{
    Array<int> arr;
    test_structure(arr);
    List<int> lst;
    test_structure(lst);
    test_stack();
    return 0;
}

