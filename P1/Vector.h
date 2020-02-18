#pragma once
#include <cstdio>
#include <iostream>

// Mirar herramienta sonarQube
// TODO: PROBLEMA CON vector<vector<T> > 
template <typename T>
class Vector {
private:
  T *ptr;
  int sz;
  int current;
public:
  Vector();
  Vector(int);
  Vector(const Vector<T>&);
  ~Vector();
  void pushBack(T);
  void push(T, int);
  void popBack();
  void pop(int);
  int getSize(void);
  T get(int);
  T getBack(void);
  void write(void);
  std::ostream& write(std::ostream&) const;
  T& operator[](int);
  Vector<T>& operator=(Vector<T>&);
  inline friend std::ostream& operator<<(std::ostream& os, Vector<T> const& v) { v.write(os); return os; };
};


// Constructor por defecto
template <typename T>
Vector<T>::Vector() {
  sz = 1;
  ptr = new T[sz];
  current = 0;
}

//Constructor dado un tamaño
template <typename T>
Vector<T>::Vector(int size) {
  if (size < 0)
    std::cout << "Error introduciendo tamaño vector" << std::endl;
  sz = size;
  current = 0;
  ptr = new T[size];
  for(int i = 0; i < size; i++)
    ptr[i] = 0;
}

//Constructor de copia
template <typename T>
Vector<T>::Vector(const Vector<T>& v):
ptr (new T[sz]),
sz (v.sz) {
  for(int i = 0; i < sz; i++)
    ptr[i] = v.ptr[i];
}

template <typename T>
Vector<T>::~Vector() {

}

template <typename T>
void Vector<T>::pushBack(T element) {
  if (current == sz) {
    T* temp = new T[sz * 2];

    for(int i = 0; i < sz; i++)
      temp[i] = ptr[i];

    delete[] ptr;
    sz *= 2;
    ptr = temp;
  }
  ptr[current] = element;
  current++;
}

template <typename T>
void Vector<T>::push(T element, int position) {
  if((position == sz) && (current == position))
    pushBack(element);
  else if (position > sz) {
      sz = position + 1;
      ptr[position] = element;
      current = position + 1;
  }
  else{
    if(position > current)
      current = position + 1;
    ptr[position] = element;
    //current++;
  }
}

template <typename T>
void Vector<T>::popBack() {
  current--;
}
/*
template <typename T>
void Vector<T>::pop(int position) {
  
}
*/

template <typename T>
int Vector<T>::getSize() {
  return current;
}

template <typename T>
T Vector<T>::get(int position) {
  return ptr[position];
}

template <typename T>
T Vector<T>::getBack() {
  return ptr[current];
}

template <typename T>
void Vector<T>::write() {
  for(int i = 0; i < current; i++) {
    std::cout << ptr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
std::ostream& Vector<T>::write(std::ostream& os) const{
  os << "Vector: {";
  for(int i = 0; i < current; i++) {
      os << ptr[i];
    if (i + 1 < current)
      os << ", ";
  }
  os << "}" << std::endl;
  return os;
}

template <typename T>
T& Vector<T>::operator[](int position) {
  if(position < 0 || position >= sz)
    throw std::out_of_range{ "Vector::operator[]"};
  return ptr[position];
}

template <typename T>
  Vector<T>& Vector<T>::operator=(Vector<T>& v) {
    T* temp = new T[v.current];
    for (int i = 0; i < v.current; i++)
      temp[i] = v[i]; 
    delete[] ptr;
    this -> ptr = temp;
    this -> sz = v.sz;
    this -> current = v.current;
    return *this;
}




