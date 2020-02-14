#include "Vector.h"
#include "DoublyLinked.h"
#include <string>

int main (void) {
  Vector<int> v_;
  Vector<int> v_2;
  //DoublyLinked<int> l_;
  v_.pushBack(2);
  v_.pushBack(3);
  v_.pushBack(10);
  v_.pushBack(312);
  v_.pushBack(7);
  v_.pushBack(50);
  v_.popBack();
  //v_.push(8,3);
  //std::cout << "lolo: " << v_[1] << std::endl;
  //auto a = v_.get(3);
  //std::cout << "a: " << a << std::endl;
  //int b = v_.getBack();
  //std::cout << "b: " << b << std::endl;
  //v_.popBack();
  v_2 = v_;
  v_.write();

}