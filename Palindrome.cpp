#include <iostream>
#include <cstring>

using namespace std;

int main(){

  char str[80] = "\0";
  //Citing Zach Tobin for getline operator
  cin.getline(str, 80);
  
  char cleanstr[80] = "\0";
  char cleanstrbackwards[80] = "\0";
  
  int count = 0;
  //strip spaces c++
  for (int i = 0; i < strlen(str); i++){
    
    //https://docs.vultr.com/cpp/standard-library/cctype/isspace
    if (isspace(str[i])){
        //cout << "space";
        count ++;
    }
    //https://www.geeksforgeeks.org/dsa/removing-punctuations-given-string/
    else if (ispunct(str[i])){
        //cout << "Is punct";
        count ++;
    }
    
    else if (isupper(str[i])){
        //cout << (char)tolower(str[i]);
        //cout << "Its upper";
        int len = strlen(cleanstr);
        cleanstr[len] = (char)tolower(str[i]);
    }
    
    else{
        int len = strlen(cleanstr);
        cleanstr[len] = str[i];
    }
    
  }


  cout << "Your unclean word is, " << str << endl;
  cout << "\n" << count << " characters got removed." << endl;
  cout << "\n" << "Your clean word is, " << cleanstr << endl;
  
  cout << "\n" << "Your backwards word is: ";
  for (int i = strlen(cleanstr); i >= 0; i--){
    cout << cleanstr[i];
  }
  
  bool Palindrome = false;

  for (int i = strlen(cleanstr); i >= 0; i--){
    int len = strlen(cleanstrbackwards);
    cleanstrbackwards[len] = cleanstr[i];
  }

  //cout << cleanstrbackwards << endl;
  //cout << cleanstr << endl;
  
  if (strcmp(cleanstr, cleanstrbackwards) == 0){
      Palindrome = true;
      cout << "\n" << "\n" << "Its a Palindrome" << endl;
  }
  
  else{
    Palindrome = false;
    cout << "\n" << "\n" << "Not a Palindrome" << endl;
  }

  
  
  return 0;
}
