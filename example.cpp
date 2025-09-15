/*
Guessing Game
Dylan Waters

Three Rules:

1. You will be practicing a lot of parameters in this class. It is also bad style to have global variables that other programmers could mess with while they are using your code. (The goal is to make code error free even if other people are using it.)

2. We are learning A LOT about how memory works in this class, and cstrings lead to a stronger understanding of how this all works. Strings hide a lot of this functionality. Plus, strings are a higher level concept that don't exist in some C libraries.

3. We're learning C++, not the older language C that it is built on. Technically the commands from C will work (like malloc) but we don't want to use them.

*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits> // Required for numeric_limits

using namespace std;

int RandomNumber() {
    int randomnumber;
    randomnumber = rand()% 100; // Call for the random number here.
  
    return randomnumber;
}


int NumberGuess() {
  int numberguess;

while (!(cin >> numberguess))
  {
      cout << "Not a number! Please enter a number." << endl;
      
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
      cout << "Your number?: ";  cout << "Your number?: ";
      // Citing google, searched "how to check for digits on an input c++" 
  }
  
  return numberguess;
}

int main() {
    
    srand(time(NULL)); //Initalize the seed
    
    int guesses = 0;

    bool keepplaying = true;
    
    // main game loop where each iteration is a single game
    while(keepplaying) {
        // generate a new random number per game
        int randomnumber = RandomNumber(); 
        
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
                guesses = guesses += 1;
    	        cout << "\n" << "You guessed it in " << guesses << " guesses!" << endl;
                //cout << randomnumber << endl; //To cheat if you want to know the number
                check = false;
            }
        }
        
        char answer;
        cout << "Do you want to keep playing (Y/N)?" << endl;
        cin >> answer;
        if (answer == 'Y' | answer== 'y') { // https://www.pcmag.com/encyclopedia/term/vertical-bar
            keepplaying = true;
        }
	else
	  keepplaying = false;
        }
        
        guesses = 0; //Reset guesses if player continues
        cout << "Thanks for playing!" << endl;
    
    return 0;

}
