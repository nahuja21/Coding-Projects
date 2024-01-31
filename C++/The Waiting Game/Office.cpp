//Office.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include "Office.h"

Office::Office() // default constructor
    : m_queue(nullptr), // queue of students
      m_completedCount(nullptr), // completed count
      m_maxIdle(0), // most idle time
      m_meanWaitTime(0), // mean wait time
      m_meanIdlingTime(0), // mean idle time
      m_numLongIdling(0), // Idle over 5
      m_numLongWaits(0), // Wait over 10
      m_numMostWaited(0), // most waited
      m_totalCCount(0), // total students
      m_currentCCount(0), // current students
      m_window(nullptr), // window array
      m_windowCount(0) { // window count
}



Office::Office(int windowCount){ // constructor
    m_numLongWaits = 0; // wait over 10 count
    m_completedCount = new ListQueue<Customer*>; // completed count
    m_totalCCount = 0; // total students
    m_meanWaitTime = 0; // mean wait time
    m_numMostWaited = 0; // most waited
    m_meanIdlingTime = 0; // mean idle time
    m_maxIdle = 0; // most idle time
    m_numLongIdling = 0; // idle over 5 count

    m_currentCCount = 0; // current students
    m_windowCount = windowCount; // window count
    m_queue = new ListQueue<Customer*>; // queue of students
    m_window = new Window*[m_windowCount]; // window array

    for(int i = 0; i < m_windowCount; ++i){ // create windows
        m_window[i] = new Window();
    }
}


Office::~Office(){ // destructor
    if(m_window != nullptr){
        for(int i = 0; i < m_windowCount; ++i){
            delete m_window[i];
        }
        delete[] m_window;
    }
    if(m_queue != nullptr){
        delete m_queue;
    }
    if(m_completedCount != nullptr){
        delete m_completedCount;
    }
}


void Office::processCustomers(){ // process customers
    for(int i = 0; i < m_windowCount; ++i){
        if(!(m_queue->isEmpty()) && !(m_window[i]->isBeingUsed())){     // if queue is not empty and window is not being used        
            updateWaitingTime(m_queue->peek());

            m_window[i]->enqueueCustomer(m_queue->pop());
        }

        if(m_window[i]->isBeingUsed()){ // if window is being used

            if(m_window[i]->processCustomer()){
                m_completedCount->push(m_window[i]->currentCustomer());
                m_window[i]->customerComplete();
                --m_currentCCount; // decrement current count
            }
        }
        else{
            updateIdleTime(m_window[i]);
        }
    }

    if(!m_queue->isEmpty()){       // if queue is not empty update wait time
        updateCustomerWaitTime();
    }
}

int Office::getNumCustomersWaiting(){
    return m_queue->count();
}

void Office::enqueueCustomer(Customer* c){
    if(c->getAction()->getWaitTime() > 0){
        m_queue->push(c);
        ++m_currentCCount;
        ++m_totalCCount;
    }
    else{
        c->removeAction();
        m_completedCount->push(c);
    }
}

ListQueue<Customer*>* Office::getProcessedCustomers(){
    return m_completedCount;
}


void Office::outputSummary(){ // output summary in the console

    std::cout << "Mean student wait time: " << (m_meanWaitTime / (double) m_totalCCount) << " tick(s)" << std::endl;
    std::cout << "Mean window idle time: " << ((m_meanIdlingTime / (double) m_windowCount)) << " tick(s)" << std::endl;
    std::cout << "Longest student wait time: " << m_numMostWaited << " tick(s)" << std::endl;
    std::cout << "Longest window idle time: " << m_maxIdle << " tick(s)" << std::endl;

}
int Office::getLongIdle(){ //Idling over 5
    return m_numLongIdling;
}

void Office::updateIdleTime(Window* w){
    w->addIdleTime();
    ++m_meanIdlingTime;

    if(w->idleDuration() > m_maxIdle){
        m_maxIdle = w->idleDuration();
    }

    if(w->idleDuration() > 5){
        if(m_numLongIdling < m_windowCount){
            ++m_numLongIdling;
        }
    }
}

int Office::getActiveCount(){
    return m_currentCCount;
}

void Office::updateCustomerWaitTime(){
    int customerIndex = m_queue->count();
    for(int i = 0; i < customerIndex; ++i){
        Customer* c = m_queue->pop();
        c->increaseQueueTime();
        m_queue->push(c);
    }
}

void Office::updateWaitingTime(Customer* c){
    int customerWaitTime = c->getQueueTime();
    m_meanWaitTime += customerWaitTime;

    if(customerWaitTime > m_numMostWaited){
        m_numMostWaited = customerWaitTime;
    }

    if(customerWaitTime > 10){
        ++m_numLongWaits;
    }
}

int Office::getLongWait(){
    return m_numLongWaits;
}
