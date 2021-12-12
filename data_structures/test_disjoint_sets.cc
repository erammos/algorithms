#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << std::endl;
  }
}
int find(int arr[], int i) {
  vector<int> list;
  while (arr[i] != -1) {
    list.push_back(i);
    i = arr[i];
  }
  for (auto &j : list) {
    arr[j] = i;
  }
  return i;
};
void unionSet(int arr[], int size[], int a, int b) {
  int rootA = find(arr, a);
  int rootB = find(arr, b);
  if (size[rootA] <= size[rootB]) {
    arr[rootA] = rootB;
    size[rootB] += size[rootA];
  } else {
    arr[rootB] = rootA;
    size[rootA] += size[rootB];
  }
}
int main() {
  int n = 20;
  int *array = new int[n];
  int *size = new int[n];

  for (int i = 0; i < n; i++) {
    array[i] = -1;
    size[i] = 1;
  }
  unionSet(array, size, 0, 1);
  unionSet(array, size, 1, 2);
  unionSet(array, size, 5, 7);
  unionSet(array, size, 7, 8);
  unionSet(array, size, 7, 9);

  cout << find(array, 2) << std::endl;
  cout << find(array, 9) << std::endl;
  cout << find(array, 8) << std::endl;
  cout << find(array, 7) << std::endl;
  cout << find(array, 0) << std::endl;
  cout << "***********" << endl;
  print(array, 20);
}
