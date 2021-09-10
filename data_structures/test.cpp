#include "array.h"
#include <iostream>
using namespace std;

int main()
{

    int n = 10; 
    Array<int> arr;
    for(int i = 0; i < n;i++)
    {
	arr.insert(i);
    }

    arr.remove(0);
    arr.remove(9);
    arr.remove(4);
    arr.remove(8);
    arr.remove(3);
    arr.remove(5);

    for(int i = 0; i < arr.size();i++)
    {
	cout << arr[i] << "\n";
    }
    return 0;
}
