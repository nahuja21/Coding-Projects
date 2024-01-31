///@file Frequency.cpp
///@brief Frequency calculation
///@author nahuja@chapman.edu
#include <iostream>
#include <math.h>
#include <stdio.h>

//make functions for calculating frequency
double calcFrequency(int x, double y)
{
    return 16.35*(pow(2,x)*pow(2,(y/12)));
}

//make function for calculating wave
double calcWave(int x, double y)
{
    return (34500/calcFrequency(x,y));
}

//main function for printing out
int main()
{
    int octave;
    int sound = 345;
    int halfStep;

     std::cout << "Reference Frequency: 16.35 Hz "<<std::endl;
     std::cout << "Speed of Sound: " << sound << "m's"<<std::endl;
     std::cout << "Note: C0; nu: 0; k: 0; frequency: " << calcFrequency(0, 0) << "hz" << " wavelength: " << calcWave(0, 0) << "cm" << std::endl;
     std::cout << "Note: C#0; nu: 0; k: 1; frequency: " << calcFrequency(0, 1) << "hz"  << " wavelength: " << calcWave(0, 1) << "cm"  << std::endl;
     std::cout << "Note: D0; nu: 0; k: 2; frequency: " << calcFrequency(0, 2) << "hz"  << " wavelength: " << calcWave(0, 2) << "cm"  << std::endl;
     std::cout << "Note: C4; nu: 4; k: 0; frequency: " << calcFrequency(4, 0) << "hz"  << " wavelength: " << calcWave(4, 0) << "cm"  << std::endl;
     std::cout << "Note: D#7; nu: 7; k: 3; frequency: " << calcFrequency(7, 3) << "hz"  << " wavelength: " << calcWave(7, 3) << "cm"  << std::endl;
     std::cout << "Note: C8; nu: 8; k: 0; frequency: " << calcFrequency(8, 0) << "hz"  << " wavelength: " << calcWave(8, 0) << "cm"  << std::endl;

    return 0;
}