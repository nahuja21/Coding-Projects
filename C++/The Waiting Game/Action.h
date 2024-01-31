//Action.h
//PA4
//Caden Goodwin & Nikhil Ahuja
//tets
#ifndef ACTION_H
#define ACTION_H

class Action {

private:
    bool m_complete; //returns true after the visit is complete
    char m_office; //the office the student is visiting
    int m_waitTime; //wait time

public:
    Action(); // default constructor
    Action(char office, int waitTime); // constructor
    ~Action(); // destructor
    bool isDone(); // returns if action is done
    void assignWaitTime(int waitTime); // assigns wait time
    char getOffice(); // returns office
    void decreaseTime(); // decreases wait time
    int getWaitTime(); // returns wait time
    void assignOffice(char office); // assigns office


};

#endif
