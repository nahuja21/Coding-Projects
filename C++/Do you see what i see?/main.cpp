#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Monostack.h"
#include "Speakerview.h"
using namespace std;

int main(int argc, char *argv[])
{
    Speakerview* view = new Speakerview();
    view->getRowsAndCols(argv[1]);
    view->fillArray(argv[1]);
    view->printSeating();
    delete view;
    return 0;
}