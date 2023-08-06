// Description: this program asks an user to input a sentence and check if it is a palindrome or not.
// Student name: Koichi Nakata
// Date: July 11, 2023
// Status: complete

#include <iostream>
#include <string>
#include <cctype> // Want to use toupper()
using namespace std;

// Function prototypes
string removePunc(string);
bool checkPunc(char);
bool checkPalin(string, int, int); // Returns true or false

int main() {
  string userInput, removed;
  int end;

  cout << "\nPlease enter a palindrome sentence here: ";
  getline(cin, userInput);

  removed = removePunc(userInput);
  end = removed.length() - 1; // Don't forget to minus 1

  if (checkPalin(removed, 0, end))
    cout << "\nThe sentence is a palindrome!" << endl;
  else
    cout << "\nThat is not a palindrome..." << endl;

  return 0;
}

// We want to clean the string first so that checking palindrome would be easier. In this function, we are removing '.' ',' and ' '.
string removePunc(string userInput)
{
  string removed;  
  for (int i = 0; i < userInput.length(); i++)
    {
      if (!checkPunc(userInput[i])) // If the character is NOT '.' ',' or ' '
        removed += toupper(userInput[i]);
    }
  return removed;
}

bool checkPunc(char c)
{
  if (c == ' ' || c == '.' || c == ',')
    return true;
  return false;
}

// We want to compare the first and last characters. If they are identical, we move each index inside. If the indexes come to the same place (base case 1), or next to each other and they are the same characters (base case 2), that means the sentence is a palindrome.
bool checkPalin(string removed, int start, int end)
{
  if (start == end) // Base case 1
    return true;
  else
  {
    if (removed[start] == removed[end])
    { 
      if (start+1 == end) // Base case 2
        return true;
      else
        return checkPalin(removed, start+1, end-1); // The function must be called as a return otherwise each recursion doesn't have any conclusion (return).
    }
    else // If the characters are not identical
      return false;
  }
}