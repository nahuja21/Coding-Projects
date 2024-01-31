#include "world.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

world::world(Level& l) : m_level(l){
    numLevels = m_level.getNumLevel();
    m_L = numLevels;
    m_N = m_level.getGridSize();

    m_world = new char**[m_L];
    for (int i = 0; i < m_N; i++) {
        m_world[i] = new char*[m_N];
        for (int j = 0; j < m_N; j++) {
            m_world[i][j] = new char[m_N];
        }
        
    }
}

world::~world(){
    // for (int i = 0; i <= m_L; i++) {
    //     for (int j = 0; j < m_N; j++) {
    //         delete[] m_world[i][j];
    //     }
    //     delete[] m_world[i];
    // }
    // delete[] m_world;
}


void world::copyGrid(char** grid){
    for (int i = 0; i < m_L; i++) {
        for (int j = 0; j < m_N; j++) {
            for (int k = 0; k < m_N; k++) {
                m_world[i][j][k] = grid[j][k];
            }
        }
    }
}

void world::printGrid(int level){
    if (level >= 0){
        bool clear = true;
        for (int j = 0; j <= m_L; j++){
            for (int k = 0; k <= m_L; k++){
                if (!(levelClear(level))){
                    clear = false;
                    break;
                }
            }
            if (!clear){
                break;
            }
        }
        cout << "Level " << level << endl;
        for (int j = 0; j <= m_L; j++){
            for (int k = 0; k <= m_L; k++){
                cout << m_world[level][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

char world::getElement(int i, int j, int k){
    return m_world[i][j][k];
}

void world::setElement(int currLvl, int i, int j, char k){
    m_world[currLvl][i][j] = k;
}

int world::getNumLevels(){
    return numLevels;  
}

char** world::getLevel(int index){
    return m_world[index];
}

char*** world::getWorldGrid(){
    return m_world;
}

bool world::levelClear(int levelIndex){
    for (int i = 0; i < m_N; i++) {
        for (int j = 0; j < m_N; j++) {
            if (m_world[levelIndex][i][j] == 'b' || m_world[levelIndex][i][j] == 'w') { // Check if the boss is left or warpipe is still present
                return false;
            }
        }
        return true;
}
}

void world::clearGrid(){
    for (int i = 0; i < m_L; i++) {
        for (int j = 0; j < m_N; j++) {
            for (int k = 0; k < m_N; k++) {
                m_world[i][j][k] = 'x';
            }
        }
    }
}