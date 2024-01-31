//ServiceCenter.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include "ServiceCenter.h"
using namespace std;

ServiceCenter::ServiceCenter() // default constructor
    : m_scSpecs(nullptr), // file name
      m_allOffices(nullptr), // array of offices
      m_totalCustomers(nullptr), // list of all customers
      m_currentTime(1) { // current time
}


ServiceCenter::ServiceCenter(char* cspecs) // constructor
    : m_allOffices(new Office*[3]), // array of offices
      m_currentTime(1), // current time
      m_scSpecs(cspecs), // file name
      m_totalCustomers(new DblList<ListQueue<Customer*>* >()) { // list of all customers
}


ServiceCenter::~ServiceCenter() { // destructor

    for (int i(0); m_allOffices != nullptr && i < 3; i++) { // delete offices
        delete m_allOffices[i];
    }

    delete[] m_allOffices;
    delete m_totalCustomers;
}

void ServiceCenter::outputServiceCtr() { // outputs the service center
    int longWaitTimes(0);
    int longIdleTimes(0);

    for (int i(0); i < 3; i++) {
        switch (i) {
            case 0:
                std::cout << "Cashier's ";
                break;
            case 1:
                std::cout << "Financial Aid ";
                break;
            case 2:
                std::cout << "Registrar's ";
                break;
            default:
                std::cout << "|ERROR| No office type ";
                break;
        }
        std::cout << "Office:" << std::endl;
        m_allOffices[i]->outputSummary();

        longWaitTimes += m_allOffices[i]->getLongWait(); //Over 10
        longIdleTimes += m_allOffices[i]->getLongIdle(); //Over 5
    }

    std::cout << "Number of students waiting over 10 minutes across all offices: " << longWaitTimes << " tick(s)" << std::endl;
    std::cout << "Number of windows idle for over 5 minutes across all offices: " << longIdleTimes << " tick(s)" << std::endl;
}


bool ServiceCenter::startSim() { // starts the simulation
    bool completed(true);
    if (!initializeSC()) {
        std::cerr << "|ERROR| Cant start the service center" << std::endl;
        completed = false;
    } else {
        do {
            ListQueue<Customer *> *currentCustomers(nullptr);
            if (m_currentTime - 1 < m_totalCustomers->numNodes()) {
                currentCustomers = m_totalCustomers->get(m_currentTime - 1);
            }

            while (currentCustomers && currentCustomers->count() != 0) {
                Customer *student = currentCustomers->pop();
                assignToOffice(student);
            }

            for (int i(0); i < 3; i++) {
                ListQueue<Customer *> *finished = m_allOffices[i]->getProcessedCustomers();
                int numFinished(finished->count());
                for (int j(0); j < numFinished; j++) {
                    assignToOffice(finished->pop());
                }
            }

            if ((m_allOffices[0]->getActiveCount() == 0) && (m_allOffices[1]->getActiveCount() == 0) &&
                (m_allOffices[2]->getActiveCount() == 0)) {
                break;
            }

            for (int i(0); i < 3; i++) {
                m_allOffices[i]->processCustomers();
            }
            m_currentTime++;
        } while (true);
    }
    return completed;
}




bool ServiceCenter::parseFile(char *inputFileName, int *params_office, DblList<ListQueue<Customer *> *> *allCustomers) //parses the file
{
    bool openFile = true;
    ifstream fileIn(inputFileName, ios::in);

    if (!fileIn)
    {
        cerr << "|ERROR| cant open file " << inputFileName << "." << endl;
        openFile = false;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            string buff;
            getline(fileIn, buff);
            params_office[i] = stoi(buff);
        }

        int listIndex = 0;
        string ticks;
        while (getline(fileIn, ticks))
        {
            if (isdigit(ticks[0]))
            {
                ListQueue<Customer *> *currentCustomers = new ListQueue<Customer *>;

                while (stoi(ticks) - 1 != listIndex)
                {
                    ListQueue<Customer *> *empty = nullptr;
                    allCustomers->append(empty);
                    listIndex++;
                }
                string numOfCust;
                getline(fileIn, numOfCust);
                int times[3] = {0, 0, 0};
                char offices[3] = {'\0', '\0', '\0'};

                for (int i = 0; i < stoi(numOfCust); i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        string cTime;
                        getline(fileIn, cTime, ' ');
                        times[j] = stoi(cTime);
                    }
                    string cOffice;
                    getline(fileIn, cOffice);

                    for (int f = 0, u = 0; f < 6 && u < 3; f += 2, u++)
                    {
                        offices[u] = cOffice[f];
                    }

                    Customer *newCust = new Customer(times, offices);
                    currentCustomers->push(newCust);
                }
                allCustomers->append(currentCustomers);
                listIndex++;
            }
            else
            {
                break;
            }
        }
        fileIn.close();
    }

    return openFile;
}

bool ServiceCenter::initializeSC() { // initializes the service center
    bool completed = true;
    int params_office[] = {0, 0, 0};

    if (! ServiceCenter::parseFile(m_scSpecs, params_office, m_totalCustomers)) {
        std::cerr << "|ERROR| cant parse the file" << m_scSpecs << "." << std::endl;
        completed = false;
    } else {
        m_allOffices[0] = new Office(params_office[1]);
        m_allOffices[1] = new Office(params_office[2]);
        m_allOffices[2] = new Office(params_office[0]);
    }
    return completed;
}

void ServiceCenter::assignToOffice(Customer* student) { // assigns a customer to an office
    if (!student->isDone()) { // if the student is not done
        Action* nextAction = student->getAction();
        char office = nextAction->getOffice();
        if (office == 'C') {
            m_allOffices[0]->enqueueCustomer(student);
        } else if (office == 'F') {
            m_allOffices[1]->enqueueCustomer(student);
        } else if (office == 'R') {
            m_allOffices[2]->enqueueCustomer(student);
        } else {
            std::cerr << "|ERROR| Office not found" << std::endl;
        }
    } else { // if the student is done
        delete student;
    }
}
