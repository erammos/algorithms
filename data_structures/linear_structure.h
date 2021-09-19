#pragma once
template <typename T> class LinearStructure {
public:
  virtual void Insert(const T &value) = 0;
  virtual void InsertAt(const T &value, int index) = 0;
  virtual int Find(const T &value) = 0;
  virtual void Remove(const T &value) = 0;
  virtual void RemoveAt(int index) = 0;
  virtual const T &operator[](unsigned index) = 0;
  virtual int Size() = 0;
};
