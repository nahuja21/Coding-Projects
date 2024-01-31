#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class CentralPolygonalNumbers
{

    //create reference
public:
  CentralPolygonalNumbers(){
    m_nMax = 0;
  }
  CentralPolygonalNumbers(int nMax){
    mp_iNumbers = new int[nMax + 1];
    for (int n = 0; n <= nMax; n++){
      int p = (((n * n) + n + 2) / 2);
      mp_iNumbers[n] = p;
      cout << "N: " << n << "  Maximum number of pieces: " << mp_iNumbers[n] << endl;
    }
    
  }
// create the bool save
  bool save(string strFilename, int max){
    ofstream ofsNumbers;
    ofsNumbers.open(strFilename);
    for (int i = 0; i < max + 1; i++){
      ofsNumbers << mp_iNumbers[i] << endl;
    }
    ofsNumbers.close();
  }
  

//dereference
// and delete the mp_iNumbers
  ~CentralPolygonalNumbers(){
    delete [] mp_iNumbers;
    std::cout << "Destructor called " << std::endl;
  }


private:
  int m_nMax;
  int* mp_iNumbers;
};


//main
int main()
{
  CentralPolygonalNumbers cpn(10);
  cpn.save("CPN", 10);
}