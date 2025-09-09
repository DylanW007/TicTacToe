#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int RandomNumber() {
  int randomnumber;
  randomnumber = srand();
  
  return randomnumber;
}

int NumberGuess() {
  int numberguess;
  cout << "Your number?: ";
  cin >> numberguess;
  return numberguess;
}


int main() {

  cout << "Guess a number and I will tell you if its too high or low.";
  cout << "\n";

  int randomnumber = RandomNumber();  
  int numberguess = NumberGuess();
  
  if (numberguess < randomnumber) {
    cout << "Wrong answer! The random number " << numberguess << ", is low." << endl;
  }
  else if (numberguess > randomnumber) {
    cout << "Wrong answer! The random number " << numberguess << ", is high." << endl; 
  }
  else if (numberguess = randomnumber) {
    cout << "You guessed it!" << endl;
  }

  return 0;
}
