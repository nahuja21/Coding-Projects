//Action.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include "Action.h"


Action::Action() // default constructor
    : m_office('\0'), m_waitTime(0), m_complete(false) { 
}

Action::Action(char office, int waitTime) // constructor
    : m_office(office), m_waitTime(waitTime), m_complete(false) {
}

Action::~Action() {} // destructor

void Action::assignOffice(char office) { // assigns office
    m_office = office;
}

int Action::getWaitTime() { // returns wait time
    return m_waitTime;
}

void Action::assignWaitTime(int waitTime) { // assigns wait time
    m_waitTime = waitTime;
}

bool Action::isDone() { // returns if action is done
    return m_complete;
}

char Action::getOffice() { // returns office
    return m_office;
}

void Action::decreaseTime() { // decreases wait time
    if (--m_waitTime <= 0) {
        m_complete = true;
    }
}
