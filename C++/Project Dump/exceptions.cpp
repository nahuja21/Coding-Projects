/// @file Exceptions.cpp
/// @brief Exceptions for final project
/// @author nahuja.student@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma (unsigned long x){
  unsigned long sum = 0;

  try
  {
    if (x < 1){
      throw std::runtime_error("Precondition n>=1 violated: invalid value for argument x: ");
    }
    for (int i = 1; i <= x; i++){
        sum += i;
      }
    if (sum != (x * (x + 1) / 2)){
      throw std::runtime_error("Postcondition not met: sum must equal n(n+1)/2");
    }
  }

  catch (std::runtime_error & ex){
    std::cout << "Exception: " << ex.what() << std::endl;
    std::cout << "Cannot compute sum; returning 0" << std::endl;
    //sum = 0;
  }

  return sum;
}

int main() {
  int sum = sigma(5);
  std::cout << "sigma(5) = " << sum << std::endl;
  sum = sigma(0);
  std::cout << "sigma(0) = " << sum << std::endl;

  return 0;
}