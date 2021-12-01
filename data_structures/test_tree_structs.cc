#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "bst_recursive.h"
#include "heap.h"
using namespace std;

void test1() {
  BSTreeRecursive<int, string> tree;
  tree.Insert(37, "");
  tree.Insert(19, "");
  tree.Insert(51, "");
  tree.Insert(51, "");
  tree.Insert(55, "");
  tree.Insert(4, "");
  tree.Insert(11, "");
  tree.Insert(20, "");
  tree.Insert(2, "");
  tree.PrintInOrder();
  tree.Delete(11);
  tree.Delete(51);
  tree.Delete(19);
  cout << "*********" << endl;
  tree.PrintInOrder();
}
void test2() {
  vector<int> test;
  BSTreeRecursive<int, string> tree;
  for (int i = 0; i < 100; i++) {
    int n = rand() % 100;
    tree.Insert(n, "");
    test.push_back(n);
  }
  tree.PrintInOrder();
  for (int i = 0; i < 50; i++) {
    int key = test.back();
    tree.Delete(key);
    test.pop_back();
  }
  cout << "***********" << endl;
  tree.PrintInOrder();
}
void test_heap() {
  Heap<int> h;
  int temp = 2;
  h.Insert(10, temp);
  h.Insert(5, temp);
  h.Insert(9, temp);
  h.Insert(8, temp);
  h.Insert(7, temp);
  h.Insert(12, temp);
  h.Insert(0, temp);
  h.Print();
  cout << "************" << endl;
  for (int i = 0; i < 7; i++) {
    cout << h.RemoveMinPriority() << endl;
  }
}
int main() {
  test1();
  test2();
  test_heap();
  return 0;
}
