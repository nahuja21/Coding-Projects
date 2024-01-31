#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <cstdlib>

class Level{
    public:
        Level();
        ~Level();

        int getNumLevel();
        int getGridSize();
        int getNumLives();
        int getNumCoins();
        int getNumMushrooms();
        int getNumKoopas();
        int getNumGoombas();
        int getNumNothing();

        void setElement(int x, int y, char value);
        char getElement(int x, int y);

        void setNumLevel(int numLevels);
        void setGridSize(int numGridSize);
        void setNumLives(int numLives);
        void setNumCoins(int numCoins);
        void setNumMushrooms(int numMushrooms);
        void setNumKoopas(int numKoopas);
        void setNumGoombas(int numGoombas);
        void setNumNothing(int numNothing);
        char** getGrid();
        void initializeGrid();
        void populateGrid();
        void printGrid();
        void resetLevel();
        void clearGrid();
        int m_gridSize;
        int m_numLevels;
        char** m_grid;  
    
    private:
        int m_currLevel;
        int m_numLives;
        int m_perNothing;
        int m_perCoins;
        int m_perMushrooms;
        int m_perGoomba;
        int m_perKoopa;
        int m_warpPipex;
        int m_warpPipey;
        int m_BossX;
        int m_BossY;
        char** m_initialGrid;
        
};

#endif