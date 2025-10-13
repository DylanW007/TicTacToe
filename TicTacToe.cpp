/*
Dylan Waters
10/12/25

Name : TicTacToe C++

Description : Program that will display a 3x3 table. Two players will take
turns placing X or O depending on which player went first.
*/

#include <iostream>
#include <cstdlib> // Needed for exiting program (exit(0);)
using namespace std;

// Will initialize the board.
void printBoard(char board[3][3])
{
  cout << "Printing Board:\n";
  cout << "  1 2 3" << endl;
  for (int i = 0; i < 3; i++){
      cout << i+1 << " ";
    for (int t = 0; t < 3; t++){
        cout << board[i][t] << " ";
    }
    cout << "\n";
  }    
}

// Checks all possible outcomes.
bool hasWon(char board[3][3], char player, int(playerXScore), int(playerOScore))
{
    for (int i = 0; i <= 2; i++){
        // Check horizontal
        if (board[i][0] == player && 
            board[i][1] == player && 
            board[i][2] == player){
 	        cout << "\n" << char(player) << " Wins Across" << endl;
 	        
            if (player == 'X' or player == 'x'){
                playerXScore = playerXScore =+ 1;
            }
            else{
                playerOScore = playerOScore =+ 1;
            }
        
            cout << "Player X: " << playerXScore << " Player O: " << playerOScore << endl;
 	        
 	        return true;
        }
        // Check verticals
        else if (board[0][i] == player && 
                 board[1][i] == player && 
                 board[2][i] == player){
            cout << "\n" << char(player) << " Wins Vertically" << endl;
            
            if (player == 'X' or player == 'x'){
                playerXScore = playerXScore =+ 1;
            }
            else{
                playerOScore = playerOScore =+ 1;
            }
        
            cout << "Player X: " << playerXScore << " Player O: " << playerOScore << endl;
            
            return true;
        }
    }
    
    // Check diagonal
    if (board[0][0] == player && 
        board[1][1] == player && 
        board[2][2] == player){
        cout << "\n" << char(player) << " Wins diagonally" << endl;
        
        if (player == 'X' or player == 'x'){
            playerXScore = playerXScore =+ 1;
        }
        else{
            playerOScore = playerOScore =+ 1;
        }
        
        cout << "Player X: " << playerXScore << " Player O: " << playerOScore << endl;
        return true;
    }
    
    // Check other diagonal
    if (board[0][2] == player && 
        board[1][1] == player && 
        board[2][0] == player){
        cout << "\n" << char(player) << " Wins diagonally" << endl;
        
        if (player == 'X' or player == 'x'){
            playerXScore = playerXScore =+ 1;
        }
        else{
            playerOScore = playerOScore =+ 1;
        }
        
        cout << "Player X: " << playerXScore << " Player O: " << playerOScore << endl;
        
        return true;
    }
    
    // Check tie. Will return true if every spot is filled up.
    if (board[0][0] != '.' && board[0][1] != '.' && board[0][2] != '.' &&
        board[1][0] != '.' && board[1][1] != '.' && board[1][2] != '.' &&
        board[2][0] != '.' && board[2][1] != '.' && board[2][2] != '.'){
            cout << "\n" << "You have tied" << endl;
            
            playerXScore = playerXScore =+ 1;
            playerOScore = playerOScore =+ 1;
        
            cout << "Player X: " << playerXScore << " Player O: " << playerOScore << endl;
            
            return true;
        }
    
    return false;
}

// Checks which letter, X or O the player will place
int askIndex(const char* label)
{
    int index = 0;
    bool check = false;
    while (check == false){
        cout << "What " << label << " would you like to place on? : ";
        cin >> index;

        if (index >= 1 && index <= 3){
            check = true;
        } 
        else{
            cout << endl << label << " is invalid. Try again with a number 1-3." << endl;
            check = false;
        }
    }
    
    return index;
}

// The function to run the whole game.
bool playGame()
{
    // Initialize board
    char board[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    
    int row;
    int column;
    char player;
    
    int playerXScore = 0;
    int playerOScore = 0;
  
    printBoard(board);
  
    // Will make sure letter is the correct one. (X or O). 
    bool lettercheck = false;
    while (lettercheck == false){
        cout << endl << endl << "What player are you? (X or O): ";
        cin >> player;
    
        if (player != 'X' && player != 'x' && player != 'O' && player != 'o')
        {
            cout << endl << "Invalid player type.";
        }
        else
        {
            lettercheck = true;
        }
    }

    bool playing = true;
    while (playing == true)
    {
        bool placecheck = false;
        while (placecheck == false)
        {
            // Ask for row and column index from the player
            row = askIndex("row");
            column = askIndex("column");
    
            // Check if spot is occupied
            if (board[int(row-1)][int(column-1)] != '.')
            {
                cout << "\n" << "Spot is occupied" << endl;
            }
            else{
                placecheck = true;
            }
        }

        if (player == 'X' or player == 'x')
        {
            board[int(row-1)][int(column-1)] = 'X';
        }
        else
        {
            board[int(row-1)][int(column-1)] = 'O';
        }

        printBoard(board);
    
        if (hasWon(board, player, playerXScore, playerOScore))
        {
            char reply = 'n';
            
            cout << "Do you want to play another game? [y/n]: ";
            cin >> reply;
            
            if (reply != 'y')
            {
                cout << "Thanks for playing!" << endl;
                return false;
            }
            else
            {
                return true;
            }
        }
    
        cout << endl << "Current Player: " << ((player == 'X' || player == 'x') ? char('O') : char('X')) << endl;
        player = (player == 'X' || player == 'x') ? 'O' : 'X';
    }

    return false;
}

int main()
{
    bool play = true;
    
    // Main game loop
    while(play)
    {
        // Play game until it returns false
        play = playGame();
    }
  
    return 0;
}
