//author: nikhil Ahuja
//class: data structures
//usage: uses the model.cpp to translate words and sentences

//includes
#include "Model.cpp"
#include "Translator.h"
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//translates word to robber language
string Translator::translateEnglishWord(string a) {
    Model model;
    Translator translator;
    string testOne = "";
    string test = "";
    for (int i = 0; i<a.length(); i++){
        if (isalpha(a[i])) {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
                test = model.translateSingleVowel(a[i]);
                testOne = testOne + test;
            } else {
                test = model.translateSingleConsonant(a[i]);
                testOne = testOne + test;
            }
        }
    }
    return testOne;
}

//translates sentence to robber language
string Translator::translateEnglishSentence(string a) {
    Model model;
    Translator translator;
    string test = "";
    int i = 0;
    char x = a.length();
    while (i < x){
        if (a[i] == ' ') {
            test = test + " ";
        } else {
            test = test + translateEnglishWord(std::string()+(a[i]));
        }
        i++;
    }
    return test;
}
