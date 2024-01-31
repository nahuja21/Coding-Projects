//Customer.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include "Customer.h"


Customer::Customer()
    : m_tasks(nullptr), m_queueTime(0), m_isDone(false) {} // default constructor

Customer::~Customer() {
  if (m_tasks) { // destructor
    delete m_tasks;
  }
}

Customer::Customer(int *task_times, char *officevalue)
    : m_tasks(new ListQueue<Action *>), m_queueTime(0) { // constructor

  for (int i = 0; i < 3; i++) { // creates actions for each office

    if (task_times[i] > 0) { // if the time is greater than 0, create an action

      Action *action = new Action(officevalue[i], task_times[i]); // create action

      m_tasks->push(action); // push action onto queue

    }
  }
  m_isDone = m_tasks->isEmpty(); // if the queue is empty, the student is done
}


void Customer::resetQueueTime() { // resets queue time
  m_queueTime = 0;
}

bool Customer::isDone() const { // returns if the student is done
  return m_isDone;
}


int Customer::getQueueTime() const { // returns queue time
  return m_queueTime;
}



void Customer::increaseQueueTime() { // increases queue time
  m_queueTime++;
}

void Customer::removeAction() {
  if (!m_tasks->isEmpty()) { // removes action
    m_tasks->pop(); // pop action off queue
  }
  m_isDone = m_tasks->isEmpty(); // if the queue is empty, the student is done
}

void Customer::reduceActionTime() {
  m_tasks->peek()->decreaseTime(); // reduces action time
}

Action *Customer::getAction() {
  return m_tasks->peek(); // returns action
}
