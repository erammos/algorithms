#pragma once
#include <iostream>
#include <stdexcept>

template <typename K, typename V> struct NodeTree {
  K key;
  V value;
  NodeTree *left = nullptr;
  NodeTree *right = nullptr;
};
template <typename K, typename V> class BSTreeRecursive {
private:
  NodeTree<K, V> *root_ = nullptr;
  NodeTree<K, V> *&Find(const K &key, NodeTree<K, V> *&current) {

    if (current == nullptr) {
      return current;
    }
    if (current->key == key) {
      return current;
    }
    if (current->key < key) {
      return Find(key, current->right);
    } else {
      return Find(key, current->left);
    }
  }
  NodeTree<K, V> *CreateNode(const K &key, const V &value) {
    NodeTree<K, V> *newNode = new NodeTree<K, V>();

    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = key;
    newNode->value = value;
    return newNode;
  }
  void Print(NodeTree<K, V> *current) {
    if (current == nullptr)
      return;
    Print(current->left);
    std::cout << current->key << std::endl;
    Print(current->right);
  }
  NodeTree<K, V> *&PreviousInOrder(NodeTree<K, V> *&node) {
    if (node->right != nullptr) {
      return PreviousInOrder(node->right);
    }
    return node;
  }

  void DeleteNode(NodeTree<K, V> *&node) {

    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node = nullptr;
    } else if (node->left == nullptr && node->right != nullptr) {
      NodeTree<K, V> *temp = node;
      node = node->right;
      delete temp;
    } else if (node->left != nullptr && node->right == nullptr) {
      NodeTree<K, V> *temp = node;
      node = node->left;
      delete temp;
    } else if (node->left != nullptr && node->right != nullptr) {
      NodeTree<K, V> *&pio = PreviousInOrder(node->left);
      if (node->left == pio) {
        NodeTree<K, V> *temp = pio;
        std::swap(node->right, pio->right);
        node->left = temp->left;
        temp->left = node;
        node = temp;
        DeleteNode(node->left);
      } else {
        std::swap(pio->left, node->left);
        std::swap(pio->right, node->right);
        std::swap(pio, node);
        DeleteNode(pio);
      }
    }
  }

public:
  BSTreeRecursive() {}

  void Insert(const K &key, const V &value) {
    if (root_ == nullptr) {
      root_ = new NodeTree<K, V>();
      root_->key = key;
      root_->value = value;
      return;
    }
    NodeTree<K, V> *&node = Find(key, root_);
    if (node != nullptr) {
      return;
    }
    node = CreateNode(key, value);
  }
  const V &operator[](const K &key) {
    NodeTree<K, V> *&node = Find(key, root_);
    return node->value;
  }
  void Delete(const K &key) {
    NodeTree<K, V> *&node = Find(key, root_);
    if (node == nullptr) {
      std::cout << "Key " << key << " not found" << std::endl;
      return;
    }
    DeleteNode(node);
  }
  void PrintInOrder() { Print(root_); }
};
