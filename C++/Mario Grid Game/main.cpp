#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Level.h"
#include "Mario.h"
#include "world.h"

using namespace std;

int main(const int argc, const char* argv[]){
    std::srand(std::time(nullptr));
    int lvlIndex = 0;
    Level castle;
    world war(castle);
    int startRow = std::rand() % castle.getGridSize();
    int startCol = std::rand() % castle.getGridSize();
    int m_warpPipex = std::rand() % castle.getGridSize();
    int m_warpPipey= std::rand() % castle.getGridSize();
    int m_BossX = std::rand() % castle.getGridSize();
    int m_BossY = std::rand() % castle.getGridSize();
    int gridSize = castle.getGridSize();
    Mario mar(&war, lvlIndex, &castle);


    //BEGIN CODE FROM SOURCE: https://en.cppreference.com/w/cpp/io/basic_ios/rdbuf
    std::ofstream outputFile(argv[2]);
    std::streambuf* origCoutBuff = std::cout.rdbuf(outputFile.rdbuf());
    //END CODE FROM SOURCE: https://en.cppreference.com/w/cpp/io/basic_ios/rdbuf
    castle.populateGrid();
    war.setElement(lvlIndex, m_warpPipex, m_warpPipey, 'w');
    war.setElement(lvlIndex, m_BossX, m_BossY, 'b');
    war.setElement(lvlIndex, startRow, startCol, 'H');
    castle.printGrid(); 
    war.copyGrid(castle.getGrid());
    cout << endl;

    war.printGrid(lvlIndex);
    mar.playGame();

    std::cout.rdbuf(origCoutBuff);

    outputFile.close();

    return 0;
}