#ifndef LINKEDNODE_HPP
#define LINKEDNODE_HPP

template <typename T>
class Node {
public:
    T data;
    Node(T d);
    Node *next = nullptr;
    Node *prev = nullptr;
};

template <typename T>
Node<T>::Node(T d) {
    data = d;
}

#endif