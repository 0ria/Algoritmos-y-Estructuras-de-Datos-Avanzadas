#pragma once
#include "Vector.h"
#include <cassert>
#include <iomanip>

const int defaultSize = 10;

template <typename T>
class StackV {
  private:
    Vector<T> stack_v;
    int top;
  public:
    StackV();
    StackV(int);
    ~StackV();
    bool empty(void);
    T getTop(void);
    void pop(void);
    void push(T);
    std::ostream& write(std::ostream&);
};

template <typename T>
StackV<T>::StackV() :
stack_v(defaultSize),
top(0) {

}

template <typename T>
StackV<T>::~StackV() {

}

template <typename T>
bool StackV<T>::empty() {
  return (top < 0);
}

template <typename T>
T StackV<T>::getTop(void) {
  assert(!empty());
  return stack_v.get(top);
}

template <typename T>
void StackV<T>::pop() {
  assert(!empty());
  top--;
}

template <typename T>
void StackV<T>::push(T data) {
  top++;
  stack_v.pushBack(data);
}

template <typename T>
std::ostream& StackV<T>::write(std::ostream& os) {
  os << "Pila: |";
  for (int i = 0; i < top; i++) {
    os << stack_v.get(i);
     if (i + 1 < top)
      std::cout << ", ";
  }
  os << "|--^" << std::endl;
}