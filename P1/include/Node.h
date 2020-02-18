#pragma once

template <typename T>
class Node {
  private:
    T data;
    Node<T> *prev;
    Node<T> *next;
  public:
    Node();
    Node(T);
    virtual ~Node();
    T getData();
    void setData(T);
    Node<T>* getPrev();
    Node<T>* getNext();
    void setPrev(Node<T>*);
    void setNext(Node<T>*);
    std::ostream& write(std::ostream&);
};

template <typename T>
Node<T>::Node() :
next(NULL),
prev(NULL),
data() {
  
}

template <typename T>
Node<T>::Node(T newData) :
next(NULL),
prev(NULL),
data(newData) {

}

template <typename T>
Node<T>::~Node() {
  next = NULL;
  prev = NULL;
}

template <typename T>
void Node<T>::setPrev(Node<T>* node) {
  prev = node;
}

template <typename T>
void Node<T>::setNext(Node<T>* node) {
  next = node;
}

template <typename T>
Node<T>* Node<T>::getNext(void) {
  return next;
}

template <typename T>
Node<T>* Node<T>::getPrev(void) {
  return prev;
}

template <typename T>
T Node<T>::getData(void) {
  return data;
}

template <typename T>
void Node<T>::setData(T newData) {
  data = newData;
}

template <typename T>
std::ostream& Node<T>::write(std::ostream& os) {
  os << data;
  return os;
}
