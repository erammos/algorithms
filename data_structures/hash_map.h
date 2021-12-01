#pragma once
#include <iostream>
#include <stdexcept>

#include "array.h"
#include "list.h"

template <typename K, typename V>
class HashNode {
 public:
  K key;
  V value;
  HashNode *next = nullptr;
  HashNode(K key, V value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
  }
  ~HashNode() {
    if (next != nullptr) {
      delete next;
    }
  }
};
template <typename K, typename V>
class HashMap {
 private:
  HashNode<K, V> **data_;
  int length_ = 1;
  int n = 0;
  std::hash<K> myHash;

  void InternalInsert(HashNode<K, V> **data, int size, const K &key,
                      const V &value) {
    int i = myHash(key) % size;
    if (data[i] == nullptr) {
      data[i] = new HashNode<K, V>(key, value);
      return;
    }
    HashNode<K, V> *current = data[i];
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new HashNode<K, V>(key, value);
  }

  void Rehash() {
    int newlength = 2 * length_;
    HashNode<K, V> **temp = new HashNode<K, V> *[newlength];
    for (int i = 0; i < length_; i++) {
      HashNode<K, V> *current = data_[i];
      while (current != nullptr) {
        InternalInsert(temp, newlength, current->key, current->value);
        current = current->next;
      }
    }
    delete data_;
    data_ = temp;
  }

 public:
  HashMap() { data_ = new HashNode<K, V> *[length_]; }
  const V &Find(const K &key) {
    int i = myHash(key) % length_;
    HashNode<K, V> *current = data_[i];
    while (current != nullptr) {
      if (current->key == key) {
        return current->value;
      }
      current = current->next;
    }
    return NULL;
  }

  void Insert(const K &key, const V &value) {
    if (n == length_) {
      Rehash();
    }
    InternalInsert(data_, length_, key, value);
    n++;
  }
};