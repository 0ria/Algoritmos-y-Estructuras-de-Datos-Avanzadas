#include "Node.hpp"

template <typename T>
class DoublyLinked {
private:
  Node<T> nodo;
public:
  DoublyLinked(/* args */);
  ~DoublyLinked();
  void insertFront(Node<T>* head, T newData);
  void insertAfter(Node<T>* prevNode, T newData);
  void insertEnd(Node<T>* tail, T newData);
  void deleteFront();
  void deleteLast();
  void deleteAfter(Node<T>* prevNode);
  void displayList(Node<T>* node);
};

template <typename T>
DoublyLinked<T>::DoublyLinked(/* args */) {
  
}

template <typename T>
DoublyLinked<T>::~DoublyLinked() {

}

template <typename T>
void DoublyLinked<T>::insertFront(Node<T>* head, T newData) {
  Node<T>* newNode = new Node<T>;

  newNode -> data = newData;
  newNode -> next = (*head);
  newNode -> prev = NULL;

  if ((*head) != NULL)
    (*head) -> prev = newNode;

  (*head) = newNode;
}

template <typename T>
void DoublyLinked<T>::insertEnd(Node<T>* head, T newData) {
  Node<T>* newNode = new Node<T>;
  Node<T>* last = *head;

  newNode -> data = newData;
  newNode -> next = NULL;
  newNode -> prev = (*head);

  if ((*head) == NULL) {
    newNode -> prev = NULL;
    *head = newNode;
    return ;
  }
}

template <typename T>
void DoublyLinked<T>::insertAfter(Node<T>* prevNode, T newData) {
  Node<T>* newNode = new Node<T>;

  newNode -> data = newData;
  newNode -> next = prevNode -> next;
  newNode -> prev = prevNode;

  prevNode -> next = newNode;
}