#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int RandomNumber() {
    int randomnumber;
    randomnumber = rand()% 100; //Call for the random number here.
  
    return randomnumber;
   }

int NumberGuess() {
  int numberguess;

  cout << "Your number?: ";
  cin >> numberguess;    
  return numberguess;
}

int main() {
    
    srand(time(NULL)); //Initalize the seed
    int randomnumber = RandomNumber(); 
    
    int guesses = 0; //Starts off with 1

    bool check = true;
    while (check == true) {
        cout << "Guess a number and I will tell you if its too high or low." << "\n";

        int numberguess = NumberGuess();
  
        if (numberguess < randomnumber) {
	    guesses = guesses += 1;
	    //cout << "\n" << "You have " << guesses << " guesses." << endl;
	    cout << "\n" << "Wrong answer! The number " << numberguess << ", is low." << endl << "\n";
            //cout << randomnumber << endl; //To cheat if you want to know the number
        }
        else if (numberguess > randomnumber) {
	    guesses = guesses += 1;
	    //cout << "\n" << "You have " << guesses << " guesses." << endl; 
	    cout << "\n" << "Wrong answer! The number " << numberguess << ", is high." << endl << "\n"; 
            //cout << randomnumber << endl; //To cheat if you want to know the number
        }
        else if (numberguess = randomnumber) {
	  cout << "\n" << "You guessed it in " << guesses << " guesses!" << endl;
            //cout << randomnumber << endl; //To cheat if you want to know the number
            check = false;
        }
    }
    return 0;
}
