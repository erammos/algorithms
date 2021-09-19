#include "array.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include <cassert>
#include <iostream>
using namespace std;

void TestQueue() {
  int test_data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Queue<int> q;
  int n = 10;
  for (int i = 0; i < n; i++) {
    q.Push(i);
  }

  int index = 0;
  while (!q.IsEmpty()) {
    assert(q.Front() == test_data[index]);
    q.Pop();
    index++;
  }
}
void TestStack() {

  int test_data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  Stack<int> st;
  int n = 10;
  for (int i = 0; i < n; i++) {
    st.Push(i);
  }

  int index = 0;
  while (!st.IsEmpty()) {
    assert(st.Top() == test_data[index]);
    st.Pop();
    index++;
  }
}
void TestStructure(LinearStructure<int> &arr) {
  int test_data[6] = {1, 2, 6, 7, -1, 9};

  int n = 10;
  for (int i = 0; i < n; i++) {
    arr.Insert(i);
  }

  assert(arr.Find(4) == 4);

  arr.Remove(0);
  arr.Remove(9);
  arr.Remove(4);

  arr.Remove(8);
  assert(arr.Find(8) == -1);

  arr.Remove(3);
  arr.Remove(5);
  arr.Insert(9);

  arr.InsertAt(-1, 1);
  arr.InsertAt(-1, 5);
  arr.RemoveAt(1);
  for (int i = 0; i < arr.Size(); i++) {
    assert(arr[i] == test_data[i]);
  }
}
int main() {
  Array<int> arr;
  TestStructure(arr);
  List<int> lst;
  TestStructure(lst);
  TestStack();
  return 0;
}
