// Description: this program asks an user to input an English sentence and allows them to edit it.
// Student name: Koichi Nakata
// Date: June 30, 2023
// Status: complete

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char chooseMenu(char&);
int searchWord(char[]);
void insertWord(char[]);
void appendWord(char[]);
void deleteWord(char[]);
void replaceWord(char[]);

const int SIZE = 101;

int main() {
  char userInput[SIZE];
  char choice;
  int index;

  cout << "Please input a sentence up to " << SIZE-1
    << " characters here:\n";
  cin.getline(userInput, SIZE);

  do
  {
    chooseMenu(choice);
    
    if (tolower(choice) == 's')
    {
      index = searchWord(userInput);
      if (index != -1)
        cout << "\nFound at the position at " << index << ".\n";
      else
        cout << "\nThe word was not found.\n";
    }
    else if (tolower(choice) == 'i')
    {
      insertWord(userInput);
      cout << "\nUpdated sentence:\n";
      cout << userInput << endl;
    }
    else if (tolower(choice) == 'a')
    {
      appendWord(userInput);
      cout << "\nUpdated sentence:\n";
      cout << userInput << endl;
    }
    else if (tolower(choice) == 'd')
    {
      deleteWord(userInput);
      cout << "\nUpdated sentence:\n";
      cout << userInput << endl;
    }
    else if (tolower(choice) == 'r')
    {
      replaceWord(userInput);
      cout << "\nUpdated sentence:\n";
      cout << userInput << endl;
    }
  } while (tolower(choice) != 'e');
}

char chooseMenu(char &choice) // Pass by reference so that this variable can be used outside of this function.
{
  cout << "\nPlease choose an option below for the sentence:\n";
  cout << "(s: search, i: insert, a: append, d: delete, r: replace, e: exit)\n";
  cin >> choice;
  cin.ignore(256, '\n');
  
  return choice;
}

int searchWord(char str[])
{
  char target[SIZE];
  int found, index = -1;
  
  cout << "\nPlease enter a word to be searched: ";
  cin >> target;
  
  for (int i = 0; i < strlen(str); i++)
    {
      found = strncmp(&str[i], target, strlen(target));
      // &strArray[index] displays all the elements after the index just like when you call name of string, it shows all the elements of the array. strncmp() stops comparing for the length of target.
      if (found == 0)
      {
        index = i;
        break;
        // If found, we don't need to continue searching.
      }
    }
  return index;
}

void insertWord(char str[])
{
  int index, maxChar;
  char updated[SIZE], word[SIZE];

  maxChar = SIZE - strlen(str) - 1;
  
  cout << "\nPlease enter an index where to insert: ";
  cin >> index;
  cin.ignore(256, '\n'); // I don't really understand what number I should put.
  cout << "\nPlease enter a word to be inserted:\n";
  cout << "(Max character: " << maxChar << ")\n";
  cin.getline(word, maxChar);

  strncpy(updated, str, index);
  updated[index] = '\0'; // I have no idea why we need this. Without this, a meaningless character appears at the end.
  strcat(updated, word);
  strcat(updated, " "); // Why is this a double quote?
  strcat(updated, &str[index]);

  strncpy(str, updated, SIZE);
}

void appendWord(char str[])
{
  char word[SIZE];
  int maxChar;

  maxChar = SIZE - strlen(str) - 1;

  cout << "\nPlease enter a word to be appended at the end:\n";
  cout << "(Max character: " << maxChar << ")\n";
  cin.getline(word, maxChar);

  strcat(str, " ");
  strncat(str, word, maxChar);
}

void deleteWord(char str[])
{
  char word[SIZE], updated[SIZE];
  int index, found;

  cout << "\nPlease enter a word to be deleted:\n";
  cin.getline(word, strlen(str));

  for (int i = 0; i < strlen(str); i++)
    {
      found = strncmp(&str[i], word, strlen(word));
      if (found == 0)
      {
        index = i;
        break;
      }
    }

  strncpy(updated, str, index);
  updated[index] = '\0';
  strcat(updated, &str[index+strlen(word)+1]); // Skip the word to be deleted.

  strncpy(str, updated, SIZE);
}

void replaceWord(char str[])
{
  char delWord[SIZE], newWord[SIZE], updated[SIZE];
  int maxChar, found, index;
  
  cout << "\nPlease enter the word to be replaced:\n";
  cin.getline(delWord, SIZE);

  maxChar = SIZE - strlen(str) - strlen(delWord) - 1;
  cout << "\nPlease enter a new word:\n";
  cout << "(Max character: " << maxChar << ")\n";
  cin.getline(newWord, maxChar);

  for (int i = 0; i < strlen(str); i++)
    {
      found = strncmp(&str[i], delWord, strlen(delWord));
      if (found == 0)
      {
        index = i;
        break;
      }
    }
  
  strncpy(updated, str, index);
  updated[index] = '\0';
  strcat(updated, newWord);
  strcat(updated, " ");
  strcat(updated, &str[index+strlen(delWord)]+1);

  strncpy(str, updated, SIZE);
}