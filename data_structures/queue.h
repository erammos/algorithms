#pragma once
#include "list.h"
#include <iostream>
#include <stdexcept>
template <typename T> class Queue {
private:
  List<T> list_;

public:
  const T &Front() { return list_[0]; }
  bool IsEmpty() { return list_.Size() == 0; }
  void Pop() { list_.RemoveAt(0); }
  void Push(const T &value) { list_.Insert(value); }
};
