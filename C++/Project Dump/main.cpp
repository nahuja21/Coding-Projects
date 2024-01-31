#include <iostream>
#include <random>
#include <ctime>

using namespace std;


class TicTacToe
{
public:
    TicTacToe();
    void createBoard();
	void gameOver();
    void printBoard();
    void getMove();
    bool isValidMove(int&, int&);
    void aiMove();
    bool isGameOver();
    ~TicTacToe();

//holds vars for game to end
private:
    char** board;
    int result = -1; // -1 = game not over, 0 = tie, 1 = player wins, 2 = ai wins
};

//gameover reference with outputs
void TicTacToe::gameOver()
{
    if (result == 0)
    {
        cout << "Tie!" << endl;
    }
    else if (result == 1)
    {
        cout << "You win!" << endl;
    }
    else if (result == 2)
    {
        cout << "You lose!" << endl;
    }
}
//called at start to create
TicTacToe::TicTacToe()
{
    createBoard();
}

//creates board
void TicTacToe::createBoard()
{
    board = new char*[3];
    board[0] = new char[3];
    board[1] = new char[3];
    board[2] = new char[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '~';
        }
    }
}

//prints the board for user to see
void TicTacToe::printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

//Checks if they can move there
bool TicTacToe::isValidMove(int &row, int &col)
{
    if (row > 2 || row < 0 || col > 2 || col < 0)
    {
        return false;
    }
    else if (board[row][col] == '~')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//get user moves check to see if its even in the array
void TicTacToe::getMove()
{
    int row, col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter col: ";
    cin >> col;
    if (!isValidMove(row, col))
    {
        while (!isValidMove(row, col))
        {
            cout << "Invalid move. Try again." << endl;
            cout << "Enter row: ";
            cin >> row;
            cout << "Enter col: ";
            cin >> col;
        }
    }

    board[row][col] = 'X';
    
    printBoard();
    if (isGameOver() && result == -1)
    {
        cout << "You Win! " << endl;
        result = 1;
        return;
    }

    aiMove();
    if (isGameOver() && result == -1)
    {
        cout << "AI Wins! " << endl;
        result = 2;
        return;
    }
    else if (isGameOver() && result == 0)
    {
        cout << "Tie! " << endl;
        return;
    }
    else
    {
        return;
    }
}

//How the Ai Moves
void TicTacToe::aiMove()
{
    int row, col;
    row = rand() % 3;
    col = rand() % 3;
    if (!isValidMove(row, col))
    {
        while (!isValidMove(row, col))
        {
            row = rand() % 3;
            col = rand() % 3;
        }
    }

    cout << "AI move: " << row << ", " << col << endl;
    board[row][col] = 'O';
    printBoard();
}


//check for a game over then change that var
bool TicTacToe::isGameOver()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '~'
        ||
        board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '~'
        ||
        board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '~'
        ||
        board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '~'
        ||
        board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '~'
        ||
        board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '~'
        ||
        board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '~'
        ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '~')
    {
        return true;
    }
    else
    {
        for(int r = 0; r < 3; r++)
        {
            for(int c = 0; c < 3; c++)
            {
                if(board[r][c] == '~')
                {
                    return false;
                }
            }
        }
        result = 0;
        cout << "Tie!";
        return true;
    }
}

//dereferencer deletes board
TicTacToe::~TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

//main executable 
int main()
{
    srand(time(NULL));
    TicTacToe *game = new TicTacToe();    
    game->printBoard();
    
    while(!game->isGameOver())
    {
        game->getMove();
    }

    return 0;
}