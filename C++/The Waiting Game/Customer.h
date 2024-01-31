//Customer.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
#include "Action.h"

class Customer {

private:

  bool m_isDone;
  int m_queueTime; //time spent in queue
  ListQueue<Action *> *m_tasks; //list of actions


public:

  Customer(); // default constructor
  Customer(int *task_times, char *officevalue); // constructor
  ~Customer(); // destructor


  void resetQueueTime(); // resets queue time
  void increaseQueueTime(); // increases queue time
  Action *getAction(); // returns action
  int getQueueTime() const; // returns queue time
  bool isDone() const; // returns if the student is done
  void removeAction(); // removes action
  void reduceActionTime(); // reduces action time


};

#endif
