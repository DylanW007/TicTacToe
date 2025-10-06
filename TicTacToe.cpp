#include <iostream>
using namespace std;

int main(){

  char board[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};

  int i, t;
  
  cout << "Printing Board: \n";
  for (i = 0; i < 3; i++){
    for (t = 0; t < 3; t++){
      cout << "\t" << board[i][t];
    }
  }
  
  return 0;
}
