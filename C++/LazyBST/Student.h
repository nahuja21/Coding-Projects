//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#ifndef STUDENT_H
#define STUDENT_H

#include "Info.h"

class Student : public Info {

public:

    Student(const int& id = -1)
    {

        m_id = id;
        m_gpa = -1;
        m_advisor = -1;
    }

    Student(int id, string name, string year, string major, double gpa, int advisor);

    int getStudentID();
    int& findAdvisor();



private:

    double m_gpa;
    string m_major;
    int m_advisor;



friend ostream& operator<<(ostream& logFile, const Student& student) //logFile is the file we are writing to, student is the student we are writing to the file
{
    logFile << "ID: " << student.m_id << endl
        << "Name: " << student.m_name << endl
        << "Year: " << student.m_year << endl
        << "Major: " << student.m_major << endl
        << "GPA: " << student.m_gpa << endl
        << "Advisor: " << student.m_advisor << endl
        << "-----------------------------------------------\n";

    return logFile;

}

};

#endif
