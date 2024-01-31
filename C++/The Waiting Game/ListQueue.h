//ListQueue.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H


#include "DblList.h"

template <typename T>
class ListQueue {

private:
    DblList<T>* m_queueList; // points to the previous node

public:
    ListQueue(); // constructor
    ~ListQueue(); // destructor

    bool isEmpty(); // returns true if the list is empty
    int count(); // returns the number of nodes in the list
    T pop(); // removes a node from the list
    T peek(); // returns the item at the specified index
    void push(T c); // adds a node to the end of the list

};

template <typename T>
ListQueue<T>::ListQueue() // constructor
    : m_queueList(new DblList<T>()) {
}

template <typename T> // destructor
ListQueue<T>::~ListQueue() {
    delete m_queueList;
}

template <typename T>
void ListQueue<T>::push(T item) { // adds a node to the end of the list
    m_queueList->append(item);
}

template <typename T>
bool ListQueue<T>::isEmpty() { // returns true if the list is empty
    return m_queueList->isEmpty();
}

template <typename T>
T ListQueue<T>::peek() { // returns the item at the specified index
    return m_queueList->get(0);
}


template <typename T> // returns the number of nodes in the list
int ListQueue<T>::count() {
    return m_queueList->numNodes();
}


template <typename T>
T ListQueue<T>::pop() { // removes a node from the list
    return m_queueList->popFront();
}


#endif