// sllist.h - singly linked list class
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on SLList class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef SLLIST_H
#define SLLIST_H

#include <stdexcept>
#include <mutex>

template<class T>
class SLList {
  class Node {
  public:
    T value;
    Node *next;

    Node(T x) {
      value = x;
      next = nullptr;
    }
  };
  Node* head;
  Node* tail;
  std::mutex mtx;
  
 public:

  // Constructor
  SLList() {
    mtx.lock();
    head = nullptr;
    tail = nullptr;
    mtx.unlock();
  }

  ~SLList () {
    mtx.lock();
    Node *u = head;
    while (u != nullptr) {
      Node *w = u;
      u = u->next;
      delete w;
    }
    head = nullptr;
    tail = nullptr;
    mtx.unlock();
  }

  void push(T x) {
    mtx.lock();
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (tail == nullptr) tail = u;
    mtx.unlock();
  }

  T pop() {
    mtx.lock();
    if (nullptr == head) {
      throw std::runtime_error("El stack esta vacio");
    } 
    else {
      Node *u = head;
      T x = u->value;
      head = u->next;
      delete u;
      mtx.unlock();
      return x;
    }
  }

  bool is_empty() {
    return head == nullptr;
    
  }
};

#endif