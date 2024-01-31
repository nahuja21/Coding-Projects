//ListNode.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>

template <typename T>
class ListNode {

private:
    T m_item;
    ListNode<T>* m_tail; // points to the previous node
    ListNode<T>* m_forward; // points to the next node

public:
    ListNode(T item); // constructor
    ~ListNode(); // destructor
    template <typename S>
    friend class DblList; // friend classes learned from https://www.geeksforgeeks.org/friend-class-function-cpp/

};

template <typename T>
ListNode<T>::ListNode(T item)
    : m_item(item), m_forward(NULL), m_tail(NULL) { // constructor
}

template <typename T>
ListNode<T>::~ListNode() { // destructor
    m_tail = NULL;
    m_forward = NULL;
}

#endif
