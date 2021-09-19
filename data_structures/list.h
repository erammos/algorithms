#pragma once
#include "linear_structure.h"
#include <iostream>
#include <stdexcept>
template <typename T> class Node {
public:
  T data;
  Node *next;
};
template <typename T> class List : public LinearStructure<T> {
private:
  Node<T> *head_;
  Node<T> *tail_;
  int length_;

public:
  List() : length_(0) {
    head_ = new Node<T>();
    head_->next = NULL;
    tail_ = head_;
  }
  virtual int Size() { return length_; }
  virtual void Insert(const T &value) {
    tail_->next = new Node<T>();
    tail_->next->data = value;
    tail_ = tail_->next;
    tail_->next = NULL;
    length_++;
  }
  virtual void InsertAt(const T &value, int index) {
    Node<T> *current;
    Node<T> *previous = head_;
    int i = 0;
    for (current = head_->next; current != NULL; current = current->next) {

      if (index == i) {
        Node<T> *temp = new Node<T>();
        temp->data = value;
        temp->next = current;
        previous->next = temp;
        if (current == tail_) {
          tail_ = temp;
        }
        length_++;
        return;
      }
      previous = current;
      i++;
    }
  }
  virtual int Find(const T &value) {
    Node<T> *current;
    int index = 0;
    for (current = head_->next; current != NULL; current = current->next) {
      if (current->data == value) {
        return index;
      }
      index++;
    }
    return -1;
  }
  virtual void Remove(const T &value) {
    Node<T> *current;
    Node<T> *previous = head_;
    for (current = head_->next; current != NULL; current = current->next) {
      if (current->data == value) {
        if (current == tail_) {
          tail_ = previous;
        }
        previous->next = current->next;
        length_--;
        delete current;
        return;
      }

      previous = current;
    }
  }
  virtual void RemoveAt(int index) { Remove(operator[](index)); }
  virtual const T &operator[](unsigned index) {
    Node<T> *current;
    int i = 0;
    for (current = head_->next; current != NULL; current = current->next) {
      if (i == index) {
        return current->data;
      }
      i++;
    }

    throw std::out_of_range("index out of bounds");
  }
};
