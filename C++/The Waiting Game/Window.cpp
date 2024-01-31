//Window.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include "Window.h"

Window::Window()
    : m_student(nullptr), m_using(false), m_idleDuration(0) { // default constructor
}

Window::~Window() { // destructor
    if (m_student != nullptr) {
        delete m_student;
    }
}

bool Window::isBeingUsed() { // returns if window is being used
    return m_using;
}

void Window::customerComplete() { // removes student from window
    m_student->removeAction();
    m_student = nullptr;
    m_using = false;
}

void Window::enqueueCustomer(Customer* c) { // adds student to window
    m_student = c;
    m_student->resetQueueTime();
    m_using = true;
}

void Window::addIdleTime() { // adds idle time
    m_idleDuration++;
}

int Window::idleDuration() { // returns idle duration
    return m_idleDuration;
}

Customer* Window::currentCustomer() { // returns current student
    return m_student;
}

bool Window::processCustomer() { // processes student
    bool complete = false;

    if (m_student != nullptr) {
        m_student->reduceActionTime();
        complete = m_student->getAction()->isDone();
    }
    return complete;
}
