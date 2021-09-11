#include "array.h"
#include "list.h"
#include <iostream>
#include <cassert>
using namespace std;

void test_structure(LinearStructure<int> &arr)
{
    int test_data[5] = { 1, 2, 6, 7,9};

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
    return 0;
}

