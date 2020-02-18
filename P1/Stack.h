#pragma once
#include "Vector.h"

template <typename T>
class Stack : public DoublyLinked{
  private:
    std::Vector<T> stack;
  public:
    Stack();
    ~Stack();

};
