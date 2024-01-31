#include "Speakerview.h"
#include <sstream>
#include <iostream>

using namespace std;

Speakerview::Speakerview()
{
    //declare variables on initialization
    rows = 0;
    cols = 0;
    seatsArray = NULL;
}

Speakerview::~Speakerview()
{
    //delete array on destructor 
    delete[] seatsArray;
}

void Speakerview::getRowsAndCols(string input){
    //code to get rows and cols amount
    ifstream fileInStream(input);
    bool firstLine = true;
     while (getline(fileInStream, line)){
         if (!firstLine && !fileInStream.eof()){
             if (rows++ == 0){
                 stringstream test(line);
                 while (test >> item){
                    cols++;
                 } 
             }
             //cout << "Line read is " << line << endl;
         } else firstLine = false;
     }
    fileInStream.close();
    //fillArray(input);


    //cout << "\nFile had " << rows << " rows and " << cols << " columns" << endl;
}

void Speakerview::fillArray(string input)
{
    //code that uses the amount of rows and cols to fill an array with everything from the txt
    ifstream fileInStream(input);
    seatsArray = new double[rows * cols];
    fileInStream.clear();
    fileInStream.seekg(0);
    bool firstLine = true;
    int i = 0;

    while (getline(fileInStream, line)){
        if (!firstLine && !fileInStream.eof()){
            int j = 0;
            stringstream test(line);
            
            while (test >> item){
                seatsArray[i * cols + j] = item;
                j++;
            }

           i++;
        } else firstLine = false;
    } 
    fileInStream.close();  
}

void Speakerview::printSeating()
{
    //code to print the array with txt for the output
for (int j = 0; j < cols; ++j){
        Monostack<double> stack(rows, 'd');

        for (int i = rows - 1; i >= 0; --i){
            stack.push(seatsArray[i * cols + j]);
        }

        cout << endl << stack.size() << " people can see in column " << j + 1 << " Their heights are:  ";
        
        while(!stack.isEmpty()){
            cout << stack.pop() << ", ";
        }
    }
}
