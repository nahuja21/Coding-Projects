//main.cpp
//PA4
//Caden Goodwin & Nikhil Ahuja

#include <iostream>
#include "ServiceCenter.h"

int main(int argc, char** argv) {

    int exit_code(0);

    switch(argc) { // check for file name
        case 1: // no file name

            std::cerr << "|ERROR| No file name in arguments" << std::endl;
            exit_code = -1;
            break;

        default: // file name
            ServiceCenter serviceCenter = ServiceCenter(argv[1]);
            serviceCenter.startSim();
            serviceCenter.outputServiceCtr();
    }

    return exit_code;
}