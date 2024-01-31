//ServiceCenter.h
//PA4
//Caden Goodwin & Nikhil Ahuja

#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

class ServiceCenter{

    private:
        Office** m_allOffices; //array of offices
        DblList<ListQueue<Customer*>*>* m_totalCustomers; //list of all customers
        bool initializeSC(); //initializes the service center
        int m_currentTime; //current time
        void assignToOffice(Customer* student); //assigns student to office
        char* m_scSpecs; //service center specs

    public:
        ServiceCenter(); //default constructor
        ServiceCenter(char* cspecs); //constructor
        ~ServiceCenter(); //destructor

        bool startSim(); //starts the simulation
        static bool parseFile(char* filename, int*params_office, DblList<ListQueue<Customer*>*>* allCustomers); //parses the file
        void outputServiceCtr(); //outputs the service center


};

#endif