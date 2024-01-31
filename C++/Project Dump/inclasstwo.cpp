#include <iostream>


int main()
{
    char* p_cArray = new char[2]; // allocate array of two chars
    //p_cArray[0] = 'A'; // assigns 0 to a
    //p_cArray[1] = '#'; // assigns # to 1

    *(p_cArray + 0) = 'A';
    *(p_cArray + 1) = '#';


    for (int i = 0; i < 2; i++)
    {
        std::cout << "p_cArray[0]: " << p_cArray[i] << std::endl;
    }




}