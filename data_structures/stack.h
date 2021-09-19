#pragma once
#include "array.h"
#include <iostream>
#include <stdexcept>
template <typename T> class Stack {
private:
  Array<T> array_;

public:
  const T &Top() { return array_[array_.Size() - 1]; }
  bool IsEmpty() { return array_.Size() == 0; }
  void Pop() { array_.RemoveAt(array_.Size() - 1); }
  void Push(const T &value) { array_.Insert(value); }
};
