//Window.h
//PA4
//Caden Goodwin & Nikhil Ahuja


#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"

class Window {

private:
    int m_idleDuration; //time window has been idle
    bool m_using; //returns true if window is being used
    Customer* m_student; //student currently using window

public:
    Window(); // default constructor
    ~Window(); // destructor
    void customerComplete(); // removes student from window
    int idleDuration(); // returns idle duration
    bool processCustomer(); // processes student
    void addIdleTime(); // adds idle time
    bool isBeingUsed(); // returns if window is being used
    Customer* currentCustomer(); // returns current student
    void enqueueCustomer(Customer* c); // adds student to window


};

#endif
