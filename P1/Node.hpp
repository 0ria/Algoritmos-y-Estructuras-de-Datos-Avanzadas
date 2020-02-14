template <typename T>
class Node {
  private:
    T data;
    Node *prev;
    Node *next;
  public:
    Node();
    ~Node();
    T getData();
    Node* getPrev();
    Node* getNext();
    void setPrev(Node*);
    void setNext(Node*);
};

template <typename T>
Node<T>::Node() {
  
}