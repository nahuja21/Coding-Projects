//author: nikhil Ahuja
//class: data structures
//usage: header file for single consonant and vowels

//includes
#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <string>
#pragma once
using namespace std;


//class declaration
class Model
{
    public:
        Model();
        ~Model();
        string translateSingleConsonant(char a);
        string translateSingleVowel(char b);
    private:

};
//constructor and destructor
Model::Model() {}
Model::~Model() {}

#endif
