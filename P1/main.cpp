#include "Vector.h"
#include "DoublyLinked.h"
#include <string>

int main (void) {
  Vector<int> v_;
  Vector<int> v_2;
  DoublyLinked<int> l_;
  v_.pushBack(2);
  v_.pushBack(6);
  v_.pushBack(6);
  v_.pushBack(8);
  v_[1] = 10;
  l_.insertHead(new Node<int>(5));
  l_.insertHead(new Node<int>(6));
  l_.write(std::cout);
  std::cout << std::endl;
  v_2 = v_;
  v_.write(std::cout);

}