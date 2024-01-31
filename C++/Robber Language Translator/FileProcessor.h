//author: nikhil Ahuja
//class: data structures
//usage: header file for the file usage

//includes
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
#pragma once

using namespace std;

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string a, string b);
};

#endif