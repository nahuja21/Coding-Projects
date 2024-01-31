#include <iostream>
void doSomethingRecursively(char currLetter){
    if (currLetter == 'a'){
        std::cout<<currLetter << std::endl;
    } else{
        std::cout<<currLetter << " ";
        doSomethingRecursively(currLetter-1);
    }
}

int main() {
    char cLetter = 'f';
    doSomethingRecursively(cLetter);
    return 0;
}