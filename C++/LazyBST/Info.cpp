//PA5 - Lazy Balanced Trees
//Caden Goodwin & Nikhil Ahuja


#include "Info.h"

// student and staff record information

using namespace std;

Info::Info() {
    m_id = -1;
    m_name = "";
    m_year = "";
}

Info::Info(int id, string name, string year) {
    m_id = id;
    m_name = name;
    m_year = year;
}
