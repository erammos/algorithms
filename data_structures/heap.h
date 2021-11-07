#pragma once
#include <iostream>
#include <stdexcept>

#include "array.h"

template <typename T>
class Node {
 public:
  int priority;
  T data;
};
template <typename T>
class Heap {
 private:
  Array<Node<T>*> pq;
  int parent(int x) { return x / 2; }
  int leftChild(int x) { return 2 * x; }
  int rightChild(int x) { return 2 * x + 1; }

  void HeapUp(int index) {
    if (index == 1) return;
    if (pq[parent(index)]->priority > pq[index]->priority) {
      std::swap(pq[parent(index)], pq[index]);
      HeapUp(parent(index));
    }
  }
  void HeapDown(int index) {
    if (index >= pq.Size() - 1) return;
    int minIndex = leftChild(index);
    if (rightChild(index) < pq.Size() &&
        pq[minIndex]->priority > pq[rightChild(index)]->priority) {
      minIndex = rightChild(index);
    }
    if (pq[minIndex]->priority < pq[index]->priority) {
      std::swap(pq[minIndex], pq[index]);
      HeapDown(minIndex);
    }
  }

 public:
  Heap() { pq.Insert(nullptr); }
  void Insert(int priority, T& data) {
    Node<T>* node = new Node<T>();
    node->priority = priority;
    node->data = data;
    pq.Insert(node);
    HeapUp(pq.Size() - 1);
  }
  int RemoveMinPriority() {
    int temp = pq[1]->priority;

    std::swap(pq[1], pq[pq.Size() - 1]);
    pq.RemoveAt(pq.Size() - 1);
    HeapDown(1);
    return temp;
  }
  int Size() { return pq.Size() - 1; }
  void Print() {
    for (int i = 1; i < pq.Size(); i++) {
      std::cout << pq[i]->priority << std::endl;
    }
  }
};
