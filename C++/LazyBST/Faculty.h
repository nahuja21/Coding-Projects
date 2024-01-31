//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja


#ifndef FACULTY_H
#define FACULTY_H

#include "Info.h"

class Faculty: public Info{

public:

    Faculty(int id, string name, string year, string department);
    ~Faculty();

    Faculty(const int& id = 0){
        m_id = id;
        m_adviseesList = nullptr;
        m_totalAdvisees = 0;    
    }

    friend ostream &operator << (ostream &logFile, const Faculty &faculty){ //logFile is the file we are writing to

        logFile << "ID#: " << faculty.m_id << endl;
        logFile << "Name: " << faculty.m_name << endl;
        logFile << "Year: " << faculty.m_year << endl;
        logFile << "Department: " << faculty.m_department << endl;
        logFile << "Advisees: [ ";

        for (int i = 0; i < faculty.m_totalAdvisees; i++)logFile << faculty.m_adviseesList[i] << " "; //prints out all advisees

        logFile << " ]\n-----------------------------------------------\n";
        return logFile;
    }

    int getFacultyID();
    void deleteAdvisee(int id);
    int getAllAdvisees();
    void newAdvisee(int id);


private:

    int *m_adviseesList;
    int m_totalAdvisees;

    string m_department;

};


#endif
