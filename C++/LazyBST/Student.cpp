//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#include "Student.h"
using namespace std;

Student::Student(int id, string name, string year, string major, double gpa, int advisor)
    : Info(id, name, year), m_major(major), m_gpa(gpa), m_advisor(advisor) {} // constructor


int Student::getStudentID() { return m_id; }
int& Student::findAdvisor() { return m_advisor; }



