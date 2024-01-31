///@file authenticator.cpp
///@brief secret code
///@author nahuja@chapman.edu

//Inlcudes
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{

//PART ONE------------------------
//declare constants
const char codeChar1 = 'E';
const char codeChar2 = 'C';
const char codeChar3 = 'A';

//declare strings
char firstString;
char secondString;
char thirdString;

//print statements
cout << ("Enter the first character of the message code:")<<endl;
cin >> firstString;
cout << ("Enter the second character of the message code:")<<endl;
cin >> secondString;
cout << ("Enter the third character of the message code:")<<endl;
cin >> thirdString;
cout << endl;

//cocatenating variables
std::string outputOne;
std::string outputTwo;
outputOne += codeChar1;
outputOne += codeChar2;
outputOne += codeChar3;
outputTwo += firstString;
outputTwo += secondString;
outputTwo += thirdString;

//PART TWO---------------------
//Print statements
std::cout << ("Authenticator code: ")<< outputOne <<endl;
std::cout << ("Message code: ") << outputTwo <<endl;

cout << endl;

//If statement to find if message is valid
if (firstString == 'E')
{
    if(secondString == 'C')
    {
        if(thirdString == 'A')
        {
            cout << ("Message is authentic.")<<endl;
        } else {
            cout << ("Message is invalid.")<<endl;
        }
    } else {
        cout << ("Message is invalid.")<<endl;
    }
} else {
        cout << ("Message is invalid.")<<endl;
    }

//PART THREE-------------------
//If statements comparing the cocatenated strings
if (outputOne == outputTwo)
{
    cout << ("Concurrence: message is authentic.")<<endl;
} else {
    cout << ("Concurrence: message is invalid.")<<endl;
}

//PART FOUR--------------------
//declaring variables
const int validCodeCheckSum = 5;
int testCodeCheckSum;

//format
cout << endl;

//find the ASCII
testCodeCheckSum = (int(firstString)+int(secondString)+int(thirdString)) % 7;
int total = (int(firstString)+int(secondString)+int(thirdString));

//more print statments
cout << ("Charecterization of message code")<<endl;
cout <<("---------------------------------")<<endl;
std::cout << ("ASCII values of message code Characters: ")<<(int(firstString))<<(", ")<<(int(secondString))<<(", ")<<(int(thirdString))<<endl;
std::cout<<("Sum of ASCII values for message code characters: ")<<total<<endl;

//FIND IF THE CHECK SUM IS VALID AKA 5
if(testCodeCheckSum == validCodeCheckSum){
    cout<<("Message code check sum is valid: 5")<<endl;
}else {
    cout<<("Message code check sum is invalid: ")<<testCodeCheckSum<<("; expected: 5")<<endl;
}

//FIND IF LETTER REPEATS.... again....
if(firstString != 'E'){
    cout<<("First Characters do not match: Message: ")<<firstString<<("; Authenticator: E")<<endl;
}
if(secondString != 'C'){
    cout<<("Second Characters do not match: Message: ")<<secondString<<("; Authenticator: C")<<endl;
}
if(thirdString != 'A'){
    cout<<("Third Characters do not match: Message: ")<<thirdString<<("; Authenticator: A")<<endl;
}
if(testCodeCheckSum > validCodeCheckSum){
    cout<<("Message code (")<<outputTwo<<(") is lexicorgraphically greater than Authenticator code (")<<outputOne<<(")")<<endl;
}else if(testCodeCheckSum < validCodeCheckSum){
    cout<<("Message code (")<<outputTwo<<(") is lexicorgraphically less than Authenticator code (")<<outputOne<<(")")<<endl;

}else {
    cout<<("")<<endl;
}
}
