//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja


#include "Faculty.h"

using namespace std;

Faculty::Faculty(int id, string name, string year, string department): Info(id, name, year){

    m_totalAdvisees = 0;
    m_adviseesList = nullptr;
    m_department = department;

}

Faculty::~Faculty()
{
    delete[] m_adviseesList;
}

int Faculty::getAllAdvisees() { return m_totalAdvisees; } //returns the number of advisees
int Faculty::getFacultyID() { return m_id; } //returns the faculty ID


void Faculty::deleteAdvisee(int id){
    int i;
    for (i = 0; i < m_totalAdvisees; i++){ //finds the advisee
        if (m_adviseesList[i] == id) break; //breaks when found
    }
    if (i < m_totalAdvisees){ //if the advisee is found
        m_totalAdvisees--; //decrement the number of advisees
        int *temp = new int[m_totalAdvisees]; //create a new array
        for(int j = 0, k = 0; j < m_totalAdvisees + 1; j++){ //copy the old array into the new array
            if (j != i) { //except for the advisee to be deleted
                temp[k++] = m_adviseesList[j]; //copy the old array into the new array
            }
        }
        delete[] m_adviseesList; //delete the old array
        m_adviseesList = temp; //set the old array to the new array
    }
}

void Faculty::newAdvisee(int id){
    int *temp = new int[m_totalAdvisees + 1]; //create a new array
    for(int i = 0; i < m_totalAdvisees; i++) {
        temp[i] = m_adviseesList[i]; //copy the old array into the new array
    }
    delete[] m_adviseesList;
    temp[m_totalAdvisees] = id;
    m_adviseesList = temp;
    m_totalAdvisees++; //increment the number of advisees
}
