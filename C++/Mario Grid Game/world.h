/* What we need
world
    - L = # of levels
        - L level has final boss
    - To finish the game Mario navigates from level 1 to L
make an interact method for each object
or just for mario 
*/

#ifndef WORLD_H
#define WORLD_H
#include "Level.h"

class world{
    public:
        world(Level& l);
        ~world();

        int numLevels;
        int levelIndex;
        char*** m_world;
        bool levelClear(int levelIndex); //checker to only print out the grid of the level you are on
        // bool gameIsRunning(); //conditional that starts the simulation at runtime adds mario and warpipe elements to level
        void copyGrid(char** grid);
        void setWarp();
        char getElement(int i, int j, int k);
        void printGrid(int level);   
        void setElement(int currLvl, int i, int j, char k); 
        int getNumLevels();
        char** getLevel(int index);
        char*** getWorldGrid();
        void resetGrid();
        void nextLevel();
        bool gameIsRunning();
        bool levelHasInteractables(int level);
        void clearGrid();

    private:
        Level& m_level;
        int m_L;
        int m_N;
        int currentLevel;
        
};









#endif