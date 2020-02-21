#include "../include/Vector.h"
#include "../include/DoublyLinked.h"
#include "../include/StackV.h"
#include "../include/Queue.h"
#include <string>

int main (void) {
  Vector<int> v_;
  DoublyLinked<int> l_;
  StackV<int> p_;
  Queue<int> q_;
  v_.pushBack(2);
  v_.pushBack(6);
  v_.pushBack(6);
  v_.pushBack(8);
  v_.pushBack(10);
  v_.write(std::cout);

  Node<int>* a = new Node<int>(9);
  l_.insertHead(new Node<int>(6));
  l_.insertHead(a);
  l_.insertHead(new Node<int>(20));
  l_.write(std::cout);

  p_.push(10);
  p_.push(5);
  p_.push(25);
  p_.pop();
  p_.write(std::cout);

  q_.insertBack(5);
  q_.insertBack(6);
  q_.insertBack(8);
  q_.extractFront();
  q_.write(std::cout);

}