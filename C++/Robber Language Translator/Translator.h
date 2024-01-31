//author: nikhil Ahuja
//class: data structures
//usage: header file for translator

//includes
#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <string>
#pragma once

//class declaration
class Translator
{
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string a);
        string translateEnglishSentence(string a);
    private:
};

//constructor and destructor
Translator::Translator() {}
Translator::~Translator() {}


#endif