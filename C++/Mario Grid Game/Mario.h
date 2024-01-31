#ifndef MARIO_H
#define MARIO_H
#include "world.h"
#include "Level.h"

class Mario{
    public:
        Mario(world* worldPtr, int gridSize, Level* levelPtr);
        ~Mario();
        int getLives();
        int getCoins();
        int getPowerLevel();
        int getRow();
        int getCol();
        int enemiesKilled();
        void setMarioPosition(int currLvl, int x, int y);
        void setWarpPipe(int currLvl, int x, int y);
        void setBoss(int currLvl, int x, int y);
        void setCol(int col);
        void setRow(int row);
        void setPL(int PL);
        void playGame();
        void collectCoin();
        void enemyKilled();
        void move();
        void gainLife();
        void loseLife();
        void interact(char element);
        bool gameOver();
        bool gameIsRunning();
        void levelIsComplete();
        void koopaFight();
        void goombaFight();
        void endGame();
        void bossFight();

        Level* m_level;
        world* m_world;

    private:
        int m_size;
        int m_lives;
        int m_coins;
        int m_PL;
        int m_row;
        int m_col;
        int m_posX;
        int m_posY;
        int m_posZ;

        bool m_gameRunning;
        bool m_levelComplete;
        bool m_gameOver;

        int m_currLvl;

        int m_enemiesKilled;




};

#endif