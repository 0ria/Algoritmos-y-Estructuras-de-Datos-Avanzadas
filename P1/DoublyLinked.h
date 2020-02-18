#pragma once
#include "Node.h"
#include <cassert>

template <typename T>
class DoublyLinked {
private:
  int sz;
  Node<T>* head;
  Node<T>* tail;
public:
  DoublyLinked(/* args */);
  ~DoublyLinked();
  void insertHead(Node<T>*);
  void insertAfter(Node<T>*, T newData);
  void insertTail(Node<T>*);
  Node<T>* extractHead(void);
  Node<T>* extractTail(void);
  void deleteAfter(Node<T>* prevNode);
  Node<T>* getHead(void);
  Node<T>* getTail(void);
  std::ostream& write(std::ostream&);
  bool empty(void);
  int getSize(void);
};

template <typename T>
DoublyLinked<T>::DoublyLinked() :
head(NULL),
tail(NULL),
sz(0) {
  
}

template <typename T>
DoublyLinked<T>::~DoublyLinked() {

}

template <class T>
bool DoublyLinked<T>::empty(void) {
  if (head == NULL) {
    assert(tail == NULL);
	  assert(sz == 0);
	  return true;
	} 
  else return false;
}

template <typename T>
void DoublyLinked<T>::insertHead(Node<T>* nodo) {
  if (empty()) {
    head = nodo;
    tail = head;
  }
  else {
    head -> setPrev(nodo);
    nodo -> setNext(head);
    head = nodo;
  }
  sz++;
}

template <typename T>
void DoublyLinked<T>::insertTail(Node<T>* nodo) {
  if (empty()) {
    head = nodo;
    tail = head;
  }
  else {
    tail -> setNext(nodo);
    nodo -> setPrev(tail);
    tail = nodo;
  }
}

template <typename T>
Node<T>* DoublyLinked<T>::extractTail(void) {
  Node<T>* newNode = tail;
  tail = tail -> getPrev();

  if (tail != NULL)
    tail -> setNext(NULL);
  else
    head = NULL;

  sz--;

  newNode -> setNext(NULL);
  newNode -> setPrev(NULL);
  return newNode;
}

template <typename T>
Node<T>* DoublyLinked<T>::extractHead(void) {
  Node<T>* newNode = head;
  head = head -> getNext();

  if (head)
    head -> setPrev(NULL);
  else
    tail = NULL;

  sz--;

  newNode -> setNext(NULL);
  newNode -> setPrev(NULL);
  return newNode; 
}

template <typename T>
Node<T>* DoublyLinked<T>::getHead(void) {
  return head;
}

template <typename T>
Node<T>* DoublyLinked<T>::getTail(void) {
  return tail;
}

template <typename T>
std::ostream& DoublyLinked<T>::write(std::ostream& os) {
  Node<T>* newNode = head;  
  std::cout << "Dll: [";
  while (newNode != NULL) {
    newNode -> write(os);
    newNode = newNode->getNext();
    if (newNode != NULL) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

template <typename T>
int DoublyLinked<T>::getSize(void) {
  return sz;
}

/*
template <typename T>
void DoublyLinked<T>::insertAfter(Node<T>* prevNode, T newData) {
  Node<T>* newNode = new Node<T>;

  newNode -> data = newData;
  newNode -> next = prevNode -> next;
  newNode -> prev = prevNode;

  prevNode -> next = newNode;
}
*/