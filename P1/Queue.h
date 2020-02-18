#pragma once
#include "DoublyLinked.h"
#include <iostream>
#include <cassert>

template <typename T>
class Queue {
  private:
    DoublyLinked<T> queueL;
  public:
    Queue();
    ~Queue();
    bool empty(void);
    int size(void);
    T getFront(void);
    void insertBack(T);
    void extractFront(void);
    std::ostream& write(std::ostream&);
};

template <typename T>
Queue<T>::Queue() {

}

template <typename T>
Queue<T>::~Queue() {

}

template <typename T>
bool Queue<T>::empty() {
  return queueL.empty();
}

template <typename T>
int Queue<T>::size(void) {
  return queueL.getSize();
}

template <typename T>
T Queue<T>::getFront(void) {
  assert(!empty());
			
	Node<T>* newNode = queueL.getHead();
	T data = newNode->getData();
	return (data);
}

template <typename T>
void Queue<T>::extractFront(void){
	assert(!empty());			

	Node<T>* node = queueL.extractTail();
	delete node;
}

template <typename T>
void Queue<T>::insertBack(T data){

	Node<T>* node = new Node<T>(data);
	queueL.insertHead(node);
}

template <typename T>
std::ostream& Queue<T>::write(std::ostream& os) {

	Node<T>* newNode = queueL.getHead();
  os << "Cola: --> ";
	while(newNode != NULL){
		os << newNode->getData();
		newNode = newNode->getNext();
    if (newNode != NULL) {
      os << ", ";
    }
	}
  os << " -->" << std::endl;			
	return os;
}


