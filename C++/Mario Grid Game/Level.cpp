#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Level.h"

using namespace std;

Level::Level(){
    ifstream gameFile;
    gameFile.open("variables.txt");
    if (!gameFile.is_open()){
        cout << "Error: Unable to open file" << endl; 
    }
    gameFile >> m_numLevels;
    gameFile >> m_gridSize;
    gameFile >> m_numLives;
    gameFile >> m_perCoins;
    gameFile >> m_perNothing;
    gameFile >> m_perGoomba;
    gameFile >> m_perKoopa;
    gameFile >> m_perMushrooms;

    gameFile.close();

    m_grid = new char*[m_gridSize];

    //dynamically create a 2D array with NxN dimensions
    for (int i = 0; i < m_gridSize; i++){
        m_grid[i] = new char[m_gridSize];
    }
    for (int i = 0; i < m_gridSize; i++) {
        for (int j = 0; j < m_gridSize; j++) {
            m_grid[i][j] = 'X';
        }
    }

}

Level::~Level(){
    for (int i = 0; i < m_gridSize; i++){
        delete[] m_grid[i];
    }
    delete[] m_grid;
}

//Getters
int Level::getNumLevel(){
    return m_numLevels;
}

int Level::getGridSize(){
    return m_gridSize;
}

char** Level::getGrid(){
    return m_grid;
}

int Level::getNumLives(){
    return m_numLives;
}

int Level::getNumCoins(){
    int num_coins = (m_perCoins * m_gridSize * m_gridSize) / 100;
    return num_coins;
}
int Level::getNumNothing(){
    int num_nothing = (m_perNothing * m_gridSize * m_gridSize) / 100;
    return num_nothing;
}

int Level::getNumMushrooms(){
    int num_mushrooms = (m_perMushrooms * m_gridSize * m_gridSize) / 100;
    return num_mushrooms;
}

int Level::getNumGoombas(){
    int num_goombas = (m_perGoomba * m_gridSize * m_gridSize) / 100;
    return num_goombas;
}

int Level::getNumKoopas(){
    int num_koopas = (m_perKoopa * m_gridSize * m_gridSize) / 100;
    return num_koopas;
}


//Setters
void Level::setNumLevel(int numLevels){
    m_numLevels += numLevels;
}

void Level::setGridSize(int numGridSize){
    m_gridSize = numGridSize;
}

void Level::setNumLives(int numLives){
    m_numLives += numLives;
}

void Level::setNumCoins(int numCoins) {
    m_perCoins += numCoins;
}

void Level::setNumMushrooms(int numMushrooms) {
    m_perMushrooms += numMushrooms;
}

void Level::setNumKoopas(int numKoopas) {
    m_perKoopa = numKoopas;
}

void Level::setNumGoombas(int numGoombas) {
    m_perGoomba = numGoombas;
}

//Methods
void Level::populateGrid(){
    // BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/29783054/is-using-stdtime-with-stdsrand-valid-code //
    std::srand(std::time(nullptr));
    // END OF CODE FROM SOURCE: https://stackoverflow.com/questions/29783054/is-using-stdtime-with-stdsrand-valid-code //
    int placedObjects = 0;
    while (placedObjects < getNumCoins()){
        int x = std::rand() % m_gridSize;
        int y = std::rand() % m_gridSize;
        if (m_grid[x][y] == 'X'){
            m_grid[x][y] = 'c';
            placedObjects++;
    }
    }

    placedObjects = 0;
    while (placedObjects < getNumNothing()){
        int x = std::rand() % m_gridSize;
        int y = std::rand() % m_gridSize;
        if (m_grid[x][y] == 'X'){
            m_grid[x][y] = 'x';
            placedObjects++;
        }
    }
    
    placedObjects = 0;
    while (placedObjects < getNumGoombas()){
        int x = std::rand() % m_gridSize;
        int y = std::rand() % m_gridSize;
        if (m_grid[x][y] == 'X'){
            m_grid[x][y] = 'g';
            placedObjects++;
        }
    }
    placedObjects = 0;
    while (placedObjects < getNumKoopas()){
        int x = std::rand() % m_gridSize;
        int y = std::rand() % m_gridSize;
        if (m_grid[x][y] == 'X'){
            m_grid[x][y] = 'k';
            placedObjects++;
        }
    }
    placedObjects = 0;
    while (placedObjects < getNumMushrooms()){
        int x = std::rand() % m_gridSize;
        int y = std::rand() % m_gridSize;
        if (m_grid[x][y] == 'X'){
            m_grid[x][y] = 'm';
            placedObjects++;
        }
    }
    int x = std::rand() % m_gridSize;
    int y = std::rand() % m_gridSize;
    m_grid[x][y] = 'b';

    int x2 = std::rand() % m_gridSize;
    int y2 = std::rand() % m_gridSize;
    m_grid[x2][y2] = 'w';

}


void Level::printGrid(){
    for (int i = 0; i < m_gridSize; i++) {
        for (int j = 0; j < m_gridSize; j++) {
            cout << m_grid[i][j];
            cout << " ";
        }
        std::cout << std::endl;
    }
}

void Level::setElement(int x, int y, char value){
    m_grid[x][y] = value;
}

char Level::getElement(int x, int y){
    char element = m_grid[x][y];
    return element;
}

void Level::resetLevel() {
    // Loop through each element in the grid and set it to its initial state
    for (int i = 0; i < m_gridSize; i++) {
        for (int j = 0; j < m_gridSize; j++) {
            m_grid[i][j] = m_initialGrid[i][j];
        }
    }
}

void Level::clearGrid(){
    for (int i = 0; i < m_gridSize; i++){
        for (int j = 0; j < m_gridSize; j++){
            m_grid[i][j] = 'X';
        }
    }
}
