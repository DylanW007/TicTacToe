#include <iostream>
#include <cstdlib> //Needed for exiting program (exit(0);)
using namespace std;

int main(){

  /*
  bool end = false;
  while (false){
      char ch = 'e';
      if (ch == 101){
	cout << "It's ESC" << endl;
	exit(0);
      }
  }
  */
  
  //----------------------------------------------------------------------------
  char board[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};

  int i, t;
  
  cout << "Printing Board:" << "\n";
  for (i = 0; i < 3; i++){
    cout << "\n";
    for (t = 0; t < 3; t++){
      cout << board[i][t];
    }
  }
  //-----------------------------------------------------------------
  
  char player;
  
  cout << "\n\n" << "What player are you? (X or Y): ";
  cin >> player;
  
  //----------------------------------------------------------------------------
  int row;
  int column;
  
  bool game = true;
  
  while (game == true){
  
    bool rowcheck = false;
  
    while (rowcheck == false){
        cout << "\n" << "What row would you like to place on? : ";
        cin >> row;
  
        if (row <= 3){
            rowcheck = true;
        }
        else{
            cout << "\n" << "Row too high. Try again with a number 1-3" << endl;
            rowcheck = false;
        }
    }
    
    bool columncheck = false;
  
    while (columncheck == false){
        cout << "What column would you like to place on? : ";
        cin >> column;
    
        if (column <= 3){
            columncheck = true;
        } 
        else{
            cout << "\n" << "Column too high. Try again with a number 1-3" << endl;
            columncheck = false;
        }
    }
  //----------------------------------------------------------------------------
  
    if (player == 'X' or player == 'x'){
        board[int(row-1)][int(column-1)] = 'X';
        player = int(player + 1);
    }
    else{
        board[int(row-1)][int(column-1)] = 'O';
        player = int(player - 1);
    }
  
    cout << "\n" << "Printing Board:" << "\n";
    for (i = 0; i < 3; i++){
        cout << "\n";
        for (t = 0; t < 3; t++){
            cout << board[i][t];
        }
    }
    cout << "\n";
 

 //---------------------------------------------------------------------------
  
    for (int i = 0; i <= 2; i++){
      cout << player;
      //cout << int(i);
      if (board[i][0] == player and board[i][1] == player and board[i][2] == player){
     	cout << "Win Across";
      }
      else if (board[0][i] == player and board[1][i] == player and board[2][i] == player){
	cout << "Win Vertically";
      }
    }
    
  }
  
  return 0;
}
