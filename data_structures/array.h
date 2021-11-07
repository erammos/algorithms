#pragma once
#include <stdexcept>

#include "linear_structure.h"

template <typename T>
class Array : public LinearStructure<T> {
 private:
  T *data_;
  int capacity_;
  int length_;

  void Resize(int cap) {
    capacity_ = cap;
    T *temp = new T[capacity_];
    for (int i = 0; i < length_; i++) {
      temp[i] = data_[i];
    }
    delete data_;
    data_ = temp;
  }

 public:
  int Cap() { return capacity_; }
  virtual int Size() { return length_; }
  Array() : capacity_(5), length_(0) { data_ = new T[capacity_]; }
  virtual void Insert(const T &value) {
    data_[length_] = value;
    length_++;
    if (length_ == capacity_) {
      Resize(capacity_ * 2);
    }
  }
  virtual void InsertAt(const T &value, int index) {
    T aux = data_[index];
    for (int i = index + 1; i < length_ + 1; i++) {
      std::swap(aux, data_[i]);
    }
    data_[index] = value;
    length_++;
    if (length_ == capacity_) {
      Resize(capacity_ * 2);
    }
  }
  virtual int Find(const T &value) {
    for (int i = 0; i < length_; i++) {
      if (data_[i] == value) {
        return i;
      }
    }
    return -1;
  }
  virtual void Remove(const T &value) {
    if (length_ <= 0) return;

    int index = Find(value);

    if (index < 0) throw std::logic_error("index not found");
    for (int i = index; i < length_ - 1; i++) {
      data_[i] = data_[i + 1];
    }
    length_--;

    if (length_ == capacity_ / 4) {
      Resize(capacity_ / 2);
    }
  }
  virtual void RemoveAt(int index) { Remove(operator[](index)); }
  virtual T &operator[](unsigned index) {
    if (index >= length_) {
      throw std::out_of_range("index out of bounds");
    }
    return data_[index];
  }
};
