#include <iostream>
using namespace std;

void randomnumber(){
  //cout << rand();

  int RandomNumber;
  cout << ("Enter your random number for now: ");
  cin >> RandomNumber;

  cout << "\n";
}

void numberguess(){
  int NumberGuess;
  cout << ("Your number?: ");
  cin >> NumberGuess;

}

int main(){
  
  cout << "Guess a number and I will tell you if its too high or low.";
  cout << "\n";

  randomnumber();
  numberguess();

  return 0;

}
