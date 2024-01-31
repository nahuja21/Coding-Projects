//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja

#ifndef INFO_H
#define INFO_H

#include <fstream>
#include <sstream>

using namespace std;

// student and staff record information

class Info {
protected:
    string m_year;
    string m_name;

    int m_id;

public:
    Info();
    Info(int id, string name, string year);

    bool operator != (const Info& otherInfo) {
        return !(*this == otherInfo);
    }

    bool operator == (const Info& otherInfo) {
        return m_id == otherInfo.m_id;
    }

    bool operator >= (const Info& otherInfo) {
        return m_id >= otherInfo.m_id; 
    }

    bool operator < (const Info& otherInfo) {
        return m_id < otherInfo.m_id;
    }

    bool operator > (const Info& otherInfo) {
        return m_id > otherInfo.m_id;
    }

    bool operator <= (const Info& otherInfo) {
        return m_id <= otherInfo.m_id;
    }

    bool operator < (const int& id) {
        return m_id < id;
    }

    bool operator > (const int& id) {
        return m_id > id;
    }

    bool operator != (const int& id) {
        return !(*this == id);
    }

    bool operator <= (const int& id) {
        return m_id <= id;
    }

    bool operator >= (const int& id) {
        return m_id >= id;
    }

    bool operator == (const int& id) {
        return m_id == id;
    }

    friend bool operator != (const int& id, const Info& otherInfo) {
        return !((Info)otherInfo == id);
    }

    friend bool operator < (const int& id, const Info& otherInfo) {
        return otherInfo.m_id < id;
    }

    friend bool operator > (const int& id, const Info& otherInfo) {
        return otherInfo.m_id > id;
    }

    friend bool operator <= (const int& id, const Info& otherInfo) {
        return otherInfo.m_id <= id;
    }

    friend bool operator == (const int& id, const Info& otherInfo) {
        return otherInfo.m_id == id;
    }

    friend bool operator >= (const int& id, const Info& otherInfo) {
        return otherInfo.m_id >= id;
    }

    //Returns the id of the student or staff
};

#endif
