//DblList.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include <stdexcept>
#include "ListNode.h"

template <typename T>
class DblList{

    protected:
        int m_length; // number of nodes in the list
        ListNode<T>* m_tail; // points to the last node
        ListNode<T>* m_head; // points to the first node

    public:

        DblList(); // default constructor
        ~DblList(); // destructor

        void append(T item); // adds a node to the end of the list
        T pop(int index); // removes a node from the list
        void prepend(T item); // adds a node to the front of the list
        bool isEmpty(); // returns true if the list is empty
        int numNodes(); // returns the number of nodes in the list
        void push(int index, T item); // adds a node at the specified index
        T get(int index); // returns the item at the specified index
        bool has(T item); // returns true if the item is in the list
        T popFront(); // removes the first node
        T popBack(); // removes the last node

}; 

template <typename T>
DblList<T>::DblList() : m_length(0), m_head(nullptr), m_tail(nullptr) {} // default constructor

template <typename T>
DblList<T>::~DblList() { // destructor
    ListNode<T>* z;
    for (; m_head != nullptr;) {
        z = m_head;
        m_head = m_head->m_forward;
        delete z;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

template <typename T>
bool DblList<T>::has(T item) { // returns true if the item is in the list
    ListNode<T> *current = m_head; // set current to the first node

    for (; current != NULL; current = current->m_forward) { // while current customer is not null
        if (item == current->m_item) { 
            return true;
        }
    }

    return false;
}



template <typename T>
bool DblList<T>::isEmpty(){
    return (m_length == 0);
}

template <typename T> // returns the item at the specified index
void DblList<T>::append(T item) { 
    ListNode<T>* NX = new ListNode<T>(item); 
    if (isEmpty()) { 
        m_head = NX; 
    } else {
        m_tail->m_forward = NX; // set the next pointer of the last node to the new node
        NX->m_tail = m_tail;
    }
    m_tail = NX;
    ++m_length;
}

template <typename T>
int DblList<T>::numNodes(){ // returns the number of nodes in the list
    return m_length;
}


template <typename T> // returns the item at the specified index
void DblList<T>::push(int index, T item) {
    if (isEmpty() || index == 0) {
        prepend(item);
    } else if (index >= m_length - 1) {
        append(item);
    } else {
        ListNode<T>* current = m_head;
        int cPos = 0;
        for (; cPos != index; ++cPos) {
            current = current->m_forward;
        }

        ListNode<T>* NX = new ListNode<T>(item);
        current->m_tail->m_forward = NX;
        NX->m_tail = current->m_tail;
        current->m_tail = NX;
        NX->m_forward = current;
        ++m_length;
    }
}


template <typename T>
T DblList<T>::pop(int index) { // removes a node from the list
    if (!m_length) {
        throw std::out_of_range("|ERROR| The list is empty.");
    }

    T item;
    if (index <= 0) {
        return popFront();
    }
    
    if (index >= m_length - 1) {
        return popBack();
    }
    
    ListNode<T> *current = m_head;
    for (int cPos = 0; cPos < index; cPos++) {
        current = current->m_forward;
    }

    item = current->m_item;
    ListNode<T> *prev_node = current->m_tail;
    ListNode<T> *next_node = current->m_forward;
    prev_node->m_forward = next_node;
    next_node->m_tail = prev_node;
    delete current;
    m_length--;
    return item;
}

template <typename T>
T DblList<T>::get(int index) { // returns the item at the specified index
    if (!m_length) {
        throw std::out_of_range("|ERROR| The list is empty.");
    }
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("|ERROR| Invalid index at index.");
    }

    ListNode<T> *current = m_head;
    for (int cPos = 0; cPos < index; cPos++) { // while current customer is not null
        current = current->m_forward;
    }

    return current->m_item;
}

template <typename T>
T DblList<T>::popFront() { // removes the first node
    if (m_length == 0) {
        throw std::out_of_range("|ERROR| The list is empty.");
    }

    T item = m_head->m_item;
    switch (m_length) { // if there is only one node
        case 1:
            delete m_head;
            m_head = NULL;
            m_tail = NULL;
            break;
        default: // if there are more than one node
            ListNode<T> *currFront = m_head;
            m_head = m_head->m_forward;
            m_head->m_tail = NULL;
            delete currFront;
            break;
    }
    --m_length;
    return item;
}

template <typename T>
T DblList<T>::popBack() { // removes the last node
    if (m_length == 0) {
        throw std::out_of_range("|ERROR| The list is empty.");
    }

    T item = m_tail->m_item;
    switch (m_length) { // if there is only one node
        case 1:
            delete m_tail;
            m_head = NULL;
            m_tail = NULL;
            break;
        default: // if there are more than one node
            ListNode<T> *currBack = m_tail;
            m_tail = m_tail->m_tail;
            m_tail->m_forward = NULL;
            delete currBack;
            break;
    }
    --m_length;
    return item;
}

template <typename T>
void DblList<T>::prepend(T item) { // adds a node to the front of the list
    ListNode<T>* NX = new ListNode<T>(item);
    if (isEmpty()) {
        m_tail = NX;
    } else {
        m_head->m_tail = NX;
        NX->m_forward = m_head;
    }
    m_head = NX;
    ++m_length;
}



#endif
