//Office.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include "Window.h"

class Office{

    private:
    
        int m_maxIdle; //max idle time
        ListQueue<Customer*>* m_queue; //queue of customers
        ListQueue<Customer*>* m_completedCount; //completed count
        int m_currentCCount; //current customers
        int m_numLongWaits; //number of long waits (over 10)
        int m_windowCount; //number of windows
        void updateIdleTime(Window* w); //update idle time
        int m_totalCCount; //total customers
        int m_meanWaitTime; //mean wait time
        int m_numLongIdling; //number of long idling (over 5)
        Window** m_window; //array of windows
        int m_meanIdlingTime; //mean idle time
        void updateWaitingTime(Customer* c); //update waiting time
        void updateCustomerWaitTime(); //update customer wait time
        int m_numMostWaited; //number of the time most waited

    public:

        Office(); //constructor
        Office(int windowCount);
        ~Office(); //destructor

        int getNumCustomersWaiting(); //get number of customers waiting
        void enqueueCustomer(Customer* c); //enqueue customer
        ListQueue<Customer*>* getProcessedCustomers(); //get processed customers
        void outputSummary(); //output summary
        int getActiveCount();
        void processCustomers(); //process customers
        int getLongIdle(); //get long idle (over 5)
        int getLongWait(); //get long wait (over 10)


};

#endif