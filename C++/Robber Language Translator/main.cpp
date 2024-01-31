//author: nikhil Ahuja
//class: data structures
//usage: main file to run the program

//includes
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
#include "FileProcessor.h"
#include "FileProcessor.cpp"

using namespace std;

//main function
int main(int argc, char const *argv[])
{
    FileProcessor fileProcessor;
    fileProcessor.processFile("input.txt", "output.html");
    return 0;
}
