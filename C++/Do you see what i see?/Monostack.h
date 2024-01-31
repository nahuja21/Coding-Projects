#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Monostack
{
    public:
    Monostack();
    Monostack(int iSize, char o);
    ~Monostack();
    void push(T c);
    T pop();
    T peek();
    bool isFull();
    bool isEmpty();
    int size();


    private:
    T* seatsArray;
    char m_order;
    int m_count;
    int m_maxSize;
    int m_top;

};

template <typename T>
Monostack<T>::Monostack()
{
    seatsArray = NULL;
    m_count = 0;
    m_maxSize = 0;
    m_top = -1;
    m_order = '\0';

}


template <typename T>
Monostack<T>::Monostack(int iSize, char o){
    seatsArray = new T[iSize];
    m_maxSize = iSize;
    m_count = 0;
    m_top = -1;
    m_order = o;

}

template <typename T>
Monostack<T>::~Monostack(){
    delete [] seatsArray;
}

template <typename T>
bool Monostack<T>::isFull(){
    return (m_count == m_maxSize);
}

template <typename T>
bool Monostack<T>::isEmpty(){
    return (m_count == 0);
}

template <typename T>
int Monostack<T>::size(){
    return m_count;
}

template <typename T>
void Monostack<T>::push(T c){
    if(isFull()){
        T* test = new T[2*m_maxSize];
        for(int i = 0; i < m_maxSize; ++i){
            test[i] = seatsArray[i];
        }
        m_maxSize *= 2;
    }

    if (m_order == 'i'){
        while (seatsArray[m_top] > c && m_top >= 0){
            pop();
        }
    } else if (m_order == 'd'){
        while (seatsArray[m_top] < c && m_top >= 0){
            pop();
        }
    }

    seatsArray[++m_top] = c;
    ++m_count;
}

template <typename T>
T Monostack<T>::pop(){
    --m_count;
    return seatsArray[m_top--];
}

template <typename T>
T Monostack<T>::peek(){
    return seatsArray[m_top];
}

#endif