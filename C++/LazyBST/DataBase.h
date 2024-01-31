//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja


#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <sstream>
#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"

class DataBase{

public:

    void startDB();

    DataBase();
    ~DataBase();


private:

    void newStudent();
    void deleteAdvisee();
    void printStudentInformation();
    void deleteFaculty();
    void newFaculty();
    void lookupFaculty();
    void lookupStudent();
    void deleteStudent();
    void changeAdvisor();
    void printFacultyInformation();

    LazyBST<Faculty> m_facultyInformation;
    LazyBST<Student> m_studentInformation;




};


#endif