//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#ifndef LBTNODE_H
#define LBTNODE_H

#include <cstdlib>
#include <iostream>
using namespace std;


template <typename T>
class LBTNode {

public:
    explicit LBTNode(T n); //constructor
    virtual ~LBTNode(); //destructor
    template <typename S>
    friend class LazyBST;

private:

    T m_content; //content of node
    LBTNode<T> *m_parentNode;
    LBTNode<T> *m_right;
    LBTNode<T> *m_left;

};

template <typename T>

LBTNode<T>::LBTNode(T n)

    : m_content(n), m_left(nullptr), m_right(nullptr), m_parentNode(nullptr) {}



template <typename T>

LBTNode<T>::~LBTNode() {
    if (m_left) { //if left node exists
        delete m_left;
        m_left = nullptr;
    }
    if (m_right) { //if right node exists
        delete m_right;
        m_right = nullptr;
    }
}


#endif