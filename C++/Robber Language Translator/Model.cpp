//author: nikhil Ahuja
//class: data structures
//usage: file that changes the individual chars

//includes
#include "Model.h"
#include <cctype>
#include <string>

//translates conssonant to robber language
string Model::translateSingleConsonant(char a) {
    string test = "";
    test.push_back(a);
    test.push_back('o');
    test.push_back(a);
    return test;
} 

//translates vowel to robber language
string Model::translateSingleVowel(char b) {
    string test = "";
    test.push_back(b);
    return test;
}

