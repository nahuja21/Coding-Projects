//author: nikhil Ahuja
//class: data structures
//usage: main file to file processor

//includes
#include "FileProcessor.h"
#include "Translator.cpp"
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

//constructor and destructor
FileProcessor::FileProcessor() {}
FileProcessor::~FileProcessor() {}

void FileProcessor::processFile(string a, string b) {
    //variables
    ifstream input_file;
    string output;
    string test;
    ofstream output_file;
    Translator translator;

    //create html file
    output_file << "<!DOCTYPE html><html><body>";

    //open files
    input_file.open(a);
    output_file.open(b);


    //main code reads from file and writes to new file
    if (!input_file) {
        cout << "Error opening file";
    } else {
        while (std::getline(input_file, output)){
            output_file << "<p><b>" << output << "</b></p>";
            test += translator.translateEnglishSentence(output) + "<br>";
            if (input_file.eof())
                break;
        }
        output_file << "<br><p><i>" << test << "</i></p></body></html>";
        
    }

    //close files
    input_file.close();
    output_file.close();

}


