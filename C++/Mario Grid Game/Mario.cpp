#include "Mario.h"
#include "world.h"
#include "Level.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Mario::Mario(world* worldPtr, int currLvl, Level* levelPtr){
    std::srand(std::time(nullptr));
    m_world = worldPtr;
    m_level = levelPtr;
    m_size = m_level->getGridSize();
    m_row = std::rand() % m_size;
    m_col = std::rand() % m_size;  
    m_currLvl = currLvl;
    m_lives = m_level->getNumLives();
    m_PL = 0;
    m_coins = 0;
    m_gameRunning = true;
    m_levelComplete = false;
    m_gameOver = false;
}

Mario::~Mario()
{

}

int Mario::getPowerLevel()
{
    return m_PL;
}

int Mario::getCoins()
{
    return m_coins;
}

int Mario::getLives()
{
    return m_lives;
}

int Mario::getRow()
{
    return m_row;
}

int Mario::getCol()
{
    return m_col;
}

int Mario::enemiesKilled(){
    return m_enemiesKilled;
}

void Mario::enemyKilled(){
    m_enemiesKilled++;
    if (m_enemiesKilled  == 7){
        gainLife();
        m_enemiesKilled = 0;
    }
}

void Mario::setCol(int col)
{
    //if you move down put a -1
   m_col = m_col + col;
}

void Mario::setRow(int row)
{
    //if you move left put a -1
    m_row = m_row + row;

}

void Mario::setPL(int PL)
{
    //make sure the PL doesn't go above 3
    if (m_PL == 0 && PL < 0)
    {
        loseLife();
    } else if (m_PL > 2)
    {
        if (PL < 0)
        {
            m_PL += PL;
        }
    } else if (m_PL < 4)
    {
        m_PL += PL;
    }
}

void Mario::setMarioPosition(int currLvl, int x, int y){
    m_world->setElement(currLvl, x, y, 'H');
    cout << "Mario is at position (" << x << ", " << y << ")" << endl;
}

void Mario::setWarpPipe(int currLvl, int x, int y){
    m_world->setElement(currLvl, x, y, 'w');
}

void Mario::setBoss(int currLvl, int x, int y){
    m_world->setElement(currLvl, x, y, 'b');
}

void Mario::collectCoin()
{
    //Collects coins
    m_coins = m_coins + 1;
    //if mario has 20 coins, he gets an extra life (loses 20 coins)
    if (m_coins == 20)
    {
        gainLife();
        m_coins = 0;
    }
}

void Mario::move(){
    int dir = rand() % 4;
    // int dir = 0;
        switch (dir) {
        case 0: // Move up
            m_world->setElement(m_currLvl, m_row, m_col, 'x');
            if (m_row <= 0) {
                cout << "Mario moved UP. ";
                m_row = m_level->getGridSize() - 1;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            else if (m_row > 0){
                cout << "Mario moved UP. ";
                m_row--;
                interact(m_level->getElement(m_row, m_col));
            }
            setMarioPosition(m_currLvl, m_row, m_col);
            m_world->setElement(m_currLvl, m_row, m_col, 'H');
            m_world->printGrid(m_currLvl);
            break;

        case 1: // Move down
            m_world->setElement(m_currLvl, m_row, m_col, 'x');
            if (m_row >= m_level->getGridSize() - 1) {
                cout << "Mario moved DOWN. ";
                m_row = 0;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            else if (m_row < m_level->getGridSize() - 1){
                cout << "Mario moved DOWN. ";
                m_row++;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            setMarioPosition(m_currLvl, m_row, m_col);
            m_world->setElement(m_currLvl, m_row, m_col, 'H');
            m_world->printGrid(m_currLvl);
            break;
        
        case 2: // Move left
            m_world->setElement(m_currLvl, m_row, m_col, 'x');
            if (m_col <= 0) {
                cout << "Mario moved LEFT. ";
                m_col = m_level->getGridSize() - 1;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            else if (m_col > 0){
                cout << "Mario moved LEFT. ";
                m_col--;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            setMarioPosition(m_currLvl, m_row, m_col);
            m_world->setElement(m_currLvl, m_row, m_col, 'H');
            m_world->printGrid(m_currLvl);
            break;
        case 3: // Move right
            m_world->setElement(m_currLvl, m_row, m_col, 'x');
            if (m_col < m_level->getGridSize() - 1) {
                cout << "Mario moved RIGHT. ";
                m_col++;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            else if (m_col >= m_level->getGridSize() -1){
                cout << "Mario moved RIGHT. ";
                m_col = 0;
                interact(m_world->getElement(m_currLvl, m_row, m_col));
            }
            setMarioPosition(m_currLvl, m_row, m_col);
            m_world->setElement(m_currLvl, m_row, m_col, 'H');
            m_world->printGrid(m_currLvl);
            break;

        default:
            break;
    }
}

void Mario::interact(char element){
    int goombaPer = rand() % 4;
    int koopaPer = rand() % 100;
    int bossPer = rand() % 2;
    switch (element){
        case 'c': //if mario interacts with coin
            cout << "Mario collected a coin! ";
            collectCoin();
            cout << "Mario has " << getCoins() << " coins! ";
            cout << "Mario is at PL " << getPowerLevel() << ". "; 
            cout << "Mario has " << getLives() << " lives left. ";
            break;

        case 'g':
            cout << "Mario encountered a goomba! ";
            goombaFight();
            break;

        case 'k':
            cout << "Mario encountered a koopa! ";
            cout << "Mario has " << getLives() << " lives left. ";
            koopaFight();
            break;
        
        case 'm':
            cout << "Mario ate a mushroom! ";
            setPL(1);
            cout << "Mario is at PL " << getPowerLevel() << ". ";
            cout << "Mario has " << getLives() << " lives left. ";
            break;

        case 'x':
            cout << "Mario visited an empty space. ";
            cout << "Mario is at PL " << getPowerLevel() << ". "; 
            cout << "Mario has " << getLives() << " lives left. ";
            break;
        
        case 'w':
            cout << "Mario is at PL " << getPowerLevel() << ". "; 
            cout << "Mario found a warp pipe! ";
            cout << "Mario will warp. ";
            cout << "Mario has " << getLives() << " lives left. ";
            m_levelComplete = true;
            m_currLvl++;
            levelIsComplete();
            break;

        case 'b': //problem here infinite looping
            cout << "Mario encountered a BOSS. ";
            cout << "Mario is at PL " << getPowerLevel() << ". "; 
            cout << "Mario has " << getLives() << " lives left. " << endl;
            bossFight();
            break;
        }
    }

void Mario::gainLife(){
        m_lives++;
    }

void Mario::loseLife(){
    if (m_lives <= 0){
        endGame();
    }
    m_lives--;
    m_enemiesKilled = 0;
}

bool Mario::gameOver(){
    return !m_gameRunning;
}

void Mario::levelIsComplete() {
    if (m_levelComplete){
        m_level->clearGrid();   
        m_level->populateGrid();
        // m_world->copyGrid(m_level->getGrid());
        // m_world->printGrid(m_currLvl);
        cout << endl;
        cout << "Level " << m_currLvl << " complete!" << endl;
        m_levelComplete = false;
        if (m_currLvl + 1 >= m_world->getNumLevels()) {
                cout << "Congratulations, you beat the game!" << endl;
                m_gameOver = true;
            } 
    }
    
}

void Mario::endGame()
{
    m_gameRunning = false;
}

void Mario::playGame() {
    while (m_gameRunning) {
        // move Mario
        move();

        // check if game over
        if (m_gameOver) {
            cout << "Game over!" << endl;
            m_gameRunning = false;
            break;
        }
    }
}

void Mario::koopaFight()
{
    int koopaPer = rand() % 100;
    if (koopaPer <= 65){
        cout << "Mario has beat the koopa. ";
        enemyKilled();
    } else {
            if (m_PL <= 0){
            loseLife();
            } else {
                setPL(-1);
            }
            cout << "Mario lost to the koopa. And lost a PL. ";
            cout << "Mario has " << getLives() << " lives left. ";
            cout << "Mario is at PL " << getPowerLevel() << ". ";
            cout << "Mario will try again!" << endl;
            if (m_lives > 0)
            {
                koopaFight();
            } else {
                cout << ("mario ran out of lifes and Pl's") << endl;
                endGame();
            }
        }
}

void Mario::goombaFight()
{
    int goombaPer = rand() % 4;
    if (goombaPer == 0){ //mario loses
        setPL(-1);
        cout << "Mario has " << getLives() << " lives left. ";
        cout << "Mario lost to the goomba. ";
        cout << "Mario is at PL " << getPowerLevel() << ". "; 
        cout << "Mario will try again!" << endl;
        if (m_lives > 0)
        {
            goombaFight();
        }else{
            cout << ("mario ran out of lifes and Pl's") << endl;
            endGame();

        }
    }
    else { //mario wins against goomba
        cout << "Mario beat the goomba! ";
        enemyKilled();
        cout << "Mario is at PL " << getPowerLevel() << ". ";
        cout << "Mario has " << getLives() << " lives left. ";
    }

}

void Mario::bossFight()
{
    int bossPer = rand() % 2;
    if (bossPer == 0){ //Mario wins
        if (m_currLvl >= m_world->getNumLevels()){
            gameOver();
            cout << ("mario is a champion") << endl;
        }
        cout << "Mario beat the boss! ";
        m_levelComplete = true;
        m_currLvl++;
        levelIsComplete();
        } else { //Mario loses
        if (m_PL >= 2)
        {
            setPL(-2);
            cout << "Mario lost against the boss... Trying again! ";
            cout << "Mario is at PL " << getPowerLevel() << ". ";
            cout << "Mario has " << getLives() << " lives left. ";
            bossFight();

        }
        if (m_PL == 1){
            setPL(-1);
            loseLife();
            cout << "Mario is at PL " << getPowerLevel() << ". ";
            cout << "Mario has " << getLives() << " lives left. ";
            bossFight();
        } else if (m_PL == 0){
            cout << "Mario lost against the boss... Trying again! ";
            cout << "Mario is at PL " << getPowerLevel() << ". ";
            cout << "Mario has " << getLives() << " lives left. ";
            loseLife();
            bossFight();
        } else if (m_lives <= 0){
            cout << ("mario doesnt have enough lifes and Pl's to continue") << endl;
            endGame();
        }
    }

}