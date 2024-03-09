#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

template <typename T>
class DoublyLinkedList {
protected:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:
    void addFirst(T data);
    void addLast(T data);
    int size();
    bool empty();
    ~DoublyLinkedList();
};

template <typename T>
void DoublyLinkedList<T>::addFirst(T data){
    Node<T> *node = new Node<T>(data);
    node->next = head;
    head = node;
    if (head == nullptr){
        tail = head;
    }
}

template <typename T>
void DoublyLinkedList<T>::addLast(T data){
    Node<T> *node = new Node<T>(data);
    if (empty()){
        addFirst(data);
        return;
    }

    Node<T> *curr = this->head;

    while(curr->next != nullptr){
        curr = curr->next;
    }
    node->prev = curr;
    curr->next = node;
}

template <typename T>
int DoublyLinkedList<T>::size() {
    Node<T>* curr = this->head;
    int count = 0;

    while (curr != nullptr){
        count++;
        curr = curr->next;
    }
    return count;
}

template <typename T>
bool DoublyLinkedList<T>::empty(){
    return head == nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

#endif