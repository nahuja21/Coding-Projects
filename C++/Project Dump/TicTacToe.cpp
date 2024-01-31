#include <stdio.h>
#include <iostream>

class TicTacToe{
  public:

  char** pp_cGrid = new char*[3];

  TicTacToe(){
    for(int i = 0; i < 3; i++){
      pp_cGrid[i] = new char[3];
    }

    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        pp_cGrid[i][j] = '~';
      }
    }
  }

  ~TicTacToe(){
    for (int i = 0; i < 3; i++) {
        delete[] pp_cGrid[i];
    }
    delete[] pp_cGrid;
  }

   void printGame(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        std::cout << pp_cGrid[i][j] << " ";
      }
      std::cout << std::endl;
    }
  } 

  void tryPlace(){
    int row;
    int column;
    bool checking = true;

    while(checking){

      std::cout << "Please enter grid row number: " << std::endl;
      while(1){
        std::cin >> row;
        if(row >= 0 && row <= 2){
          break;
        }
        else{
          std::cout << "Not acceptable row: " << std::endl;
        }
      }

      

      std::cout << "Please enter grid column number: " << std::endl;
      while(1){
        std::cin >> column;
        if(column >= 0 && column <= 2){
          break;
        }
        else{
          std::cout << "Not acceptable column: " << std::endl;
        }
      }



      if(pp_cGrid[row][column] != '~'){
        std::cout << "Cannot move there, please try again" << std::endl;
      }
      else{
        pp_cGrid[row][column] = 'X';
        checking = false;
      }
    }
  }

  bool checkWin(char player){
    //check horizontal
    for(int i = 0; i < 3; i++){
      if(pp_cGrid[i][0] == player && pp_cGrid[i][1] == player && pp_cGrid[i][2] == player)
      return true;
    }

    //check vertical
    for(int i = 0; i < 3; i++){
      if(pp_cGrid[0][i] == player && pp_cGrid[1][i] == player && pp_cGrid[2][i] == player)
      return true;
    }

    if(pp_cGrid[0][0] == player && pp_cGrid[1][1] == player && pp_cGrid[2][2] == player)
    return true;

    if(pp_cGrid[2][0] == player && pp_cGrid[1][1] == player && pp_cGrid[0][2] == player)
    return true;

    //no one has won yet
    return false;
  }

  void AIPlay(){
    bool checking = true;

    while(checking){
      for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
          if(pp_cGrid[row][column] == '~' && checking){
            pp_cGrid[row][column] = 'O';
            checking = false;
          }
        }
      }
    }
  }

};



int main(){

  int turnCount = 1;
  bool p1Win = false;
  bool p2Win = false;
  TicTacToe game;

  game.printGame();

  while(turnCount <= 9 && !p1Win && !p2Win){
      game.tryPlace();
      turnCount++;
      if(turnCount <= 9){
        game.AIPlay();
        turnCount++;
      }
      game.printGame();


      p1Win = game.checkWin('X');
      p2Win = game.checkWin('O');
  }

  if(p1Win){
    std::cout << "You win!" << std::endl;
  }
  else if(p2Win){
    std::cout << "You lose!" << std::endl;
  }
  else{
    std::cout << "Draw!" << std::endl;
  }

  return 0;
}