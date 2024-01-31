//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#include "DataBase.h"
using namespace std;

DataBase::DataBase() = default; // Default constructor

DataBase::~DataBase() { // Destructor

    ofstream logFile("runLog.txt");
    logFile << "-----------FACULTY-----------\n";
    logFile << m_facultyInformation << '\n';
    logFile << "-----------STUDENTS----------\n";
    logFile << m_studentInformation << '\n';
}



void DataBase::newStudent() { // Add a new student to the database

    int id;
    int advisor;
    double gpa;
    string name, year, major;
    cout << "----------Enter Student Information----------\n";
    cout << "Enter student ID: \n";
    cin >> id;
    cout << "Enter student's name: \n";
    getline(cin.ignore(), name);
    cout << "Enter student's year (Freshman, Sophomore, Junior, or Senior): \n";
    cin >> year;
    cout << "Enter student's major: \n";
    getline(cin.ignore(), major); // Use getline instead of cin >> major in case the major has a space
    cout << "Enter student's GPA: \n";
    cin >> gpa;
    cout << "Enter their advisor's ID number: ";
    cin >> advisor;
    if (m_facultyInformation.contains(advisor)) {
        m_facultyInformation.find(advisor).newAdvisee(id);
        Student student = {id, name, year, major, gpa, advisor};
        m_studentInformation.insert(student);
    } else {
        cout << "\nStudent could not be added due to no advisor existing with that ID#. Make sure there's an advisor added with the correct ID before adding a student.\n";
    }
}



void DataBase::newFaculty() { // Add a new faculty member to the database
    int id;
    string name, year, department;
    cout << "----------Enter Faculty Information----------\n";
    cout << "Enter faculty ID #: \n";
    cin >> id;
    cin.ignore();
    cout << "Enter faculty's name: \n";
    getline(cin, name);
    cout << "Enter faculty's position (Professor, Dean, Public Safety, etc): \n";
    getline(cin, year);
    cout << "Enter faculty's department: \n";
    getline(cin, department);
    if (!m_facultyInformation.contains(id)) {
        Faculty faculty = {id, name, year, department};
        m_facultyInformation.insert(faculty);
    } else {
        cout << "This faculty member is already in the database.\n";
    }
}

void DataBase::lookupStudent() { // Look up a student in the database
    int id;
    cout << "Enter Student's ID #: \n";
    cin >> id;
    bool studentExists = m_studentInformation.contains(id);
    if (studentExists) { // If the student exists, print their information
        cout << m_studentInformation.find(id) << endl;
    } else {
        cout << "Student not found.\n";
    }
}

void DataBase::lookupFaculty(){ // Look up a faculty member in the database
    int id; 
    cout << "Enter the faculty member's ID #: \n";
    cin >> id;
    if(m_facultyInformation.contains(id)) { // If the faculty member exists, print their information
        cout << m_facultyInformation.find(id) << endl;
    }
    else {
        cout << "Faculty member not found\n";
    }
}

void DataBase::printFacultyInformation(){
    cout << "-----------FACULTY-----------\n";
    m_facultyInformation.printLBT(); 
}

void DataBase::printStudentInformation(){
    cout << "-----------STUDENTS-----------\n";
    m_studentInformation.printLBT(); 
}


void DataBase::changeAdvisor() { // Changes student's advisor

    int studentId;
    int facultyId;
    
    cout << "Enter the Student ID# for the Student that needs an advisor change: ";

    cin >> studentId;

    if (m_studentInformation.contains(studentId)) {
        cout << "Enter their new advisor's ID #: ";
        cin >> facultyId;

        int currentAdvisor = m_studentInformation.find(studentId).findAdvisor();
        m_facultyInformation.find(currentAdvisor).deleteAdvisee(studentId);

        if (m_facultyInformation.contains(facultyId)) { // If the faculty member exists, change the student's advisor

            m_studentInformation.find(studentId).findAdvisor() = facultyId;
            m_facultyInformation.find(facultyId).newAdvisee(studentId);
            cout << "Advisor changed successfully." << endl;

        } else {

            cout << "Faculty member not found." << endl;

        }
    } else {
        cout << "Student not found." << endl;
    }
}

void DataBase::startDB() {
    int menuSelection;
    bool isFinished = false;
    const int max_stream_size = 1000; // Custom maximum value for input stream size
    //used for making sure the user enters a valid input for the menu. Accounts for if a user enters a string instead.
    do {
        cout << "\n\n-------------UNIVERSITY STUDENT & FACULTY DATABASE-------------\n\n";
        cout << "1.  Print all students and their information (in ascending ID #) \n";
        cout << "2.  Print all faculty and their information (in ascending ID #)\n";
        cout << "3.  Find and display student information via student's ID #\n";
        cout << "4.  Find and display faculty information via faculty's ID #\n";
        cout << "5.  Add a new student to the database\n";
        cout << "6.  Delete a student from the database via their ID #\n";
        cout << "7.  Add a new faculty member to the database\n";
        cout << "8.  Delete a faculty member via their ID #\n";
        cout << "9.  Change a student's advisor via their student ID and the new faculty's ID #\n";
        cout << "10. Delete an advisee from a faculty member given their ID #\n";
        cout << "11. Exit the database and create a log file\n\n";

        cout << "Enter 1 - 11:\n";
        while(!(cin >> menuSelection) || menuSelection < 1 || menuSelection > 11) { // If the user enters a string or a number outside of the range, prompt them to enter a valid input
            cout << "That wasn't a valid input. Please enter a number between 1 and 11:\n";
            cin.clear();
            cin.ignore(max_stream_size, '\n');
        }

        switch (menuSelection) {
            case 1: printStudentInformation(); break;
            case 2: printFacultyInformation(); break;
            case 3: lookupStudent(); break;
            case 4: lookupFaculty(); break;
            case 5: newStudent(); break;
            case 6: deleteStudent(); break;
            case 7: newFaculty(); break;
            case 8: deleteFaculty(); break;
            case 9: changeAdvisor(); break;
            case 10: deleteAdvisee(); break;
            case 11: isFinished = true; break;
            default: cout << "Enter a valid numerical input" << endl; break;
        }

        if (!isFinished) {
            cout << "\n\n1. Return to menu\n2. Exit the database\nEnter 1 or 2:\n";
            while(!(cin >> menuSelection) || menuSelection < 1 || menuSelection > 2) { // If the user enters a string or a number outside of the range, prompt them to enter a valid input
                cout << "Invalid input. Enter 1 or 2:\n";
                cin.clear();
                cin.ignore(max_stream_size, '\n');
            }
            isFinished = (menuSelection == 2);
        }
    } while (!isFinished);
}

void DataBase::deleteStudent() {
    int id;
    cout << "Enter the ID of the student you would like to delete: \n";
    cin >> id;
    if (m_studentInformation.contains(id)) { // If the student exists, delete them from the database
        Student found_student = m_studentInformation.find(id);
        int advisor = found_student.findAdvisor();
        if (m_facultyInformation.contains(advisor)) { // If the student has an advisor, delete them from the advisor's list of advisees
            Faculty found_faculty = m_facultyInformation.find(advisor);
            found_faculty.deleteAdvisee(id);
        }
        m_studentInformation.remove(id);
        cout << "Student deleted successfully.\n";

    } else {
        cout << "No student found.\n";
    }
}


void DataBase::deleteFaculty() {
    int id;
    cout << "Enter the ID of the faculty member you would like to delete: \n";
    cin >> id;
    bool isContained = m_facultyInformation.contains(id);
    if (isContained) { // If the faculty member exists, delete them from the database
        int totalAdvisees = m_facultyInformation.find(id).getAllAdvisees();
        if (!totalAdvisees) {
            m_facultyInformation.remove(id);
        } else {
            cout << "This faculty member's advisees (their students) must be assigned a new advisor before this faculty member can be deleted\n";
        }
    } else {
        cout << "Faculty member not found.\n";
    }
}


void DataBase::deleteAdvisee() {
    int studentId;
    int facultyId;
    cout << "Enter the ID # of the faculty member you want to delete. \n";
    cin >> facultyId;

    if (m_facultyInformation.contains(facultyId)) { // If the faculty member exists, delete the advisee
        cout << "Enter student ID for advisee you want to delete: \n";
        cin >> studentId;

        if (m_studentInformation.contains(studentId)) { // If the student exists, delete them from the faculty member's list of advisees
            m_studentInformation.find(studentId).findAdvisor() = -1;
            m_facultyInformation.find(facultyId).deleteAdvisee(studentId);
            m_studentInformation.remove(studentId);
        } else {
            cout << "Student not found.\n";
        }
    } else {
        cout << "Faculty member not found.\n";
    }
}
