#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include <fstream>
#include "Monostack.h"

using namespace std;


class Speakerview
{
    public:
    Speakerview();
    ~Speakerview();
    void getRowsAndCols(string input);
    void fillArray(string input);
    void printSeating();



    private:
    int rows;
    int cols;
    double* seatsArray;
    string line;
    double item;
    //double** testArray;
    
};

#endif