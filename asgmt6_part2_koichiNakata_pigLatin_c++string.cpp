// Description: this prgram accept a sentence as a string and translate it into a specific language.
// Student name: Koichi Nakata
// Date: June 29, 2023
// Status: complete

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string translateIntoPig(string);

int main() {
  string original;

  cout << "Please input a sentence that you want to translate into Pig Latin:\n";
  getline(cin, original);

  cout << "\nThis is translated sentence into Pig Latin:\n";
  cout << translateIntoPig(original);

  return 0;
}

string translateIntoPig(string str)
{
  string strArray[str.length()];
  // Make a empty array to store each word of the string sentence. The size should be enough with the size of the original string.
  string pigLatin;
  int index = 0;
  // This index will be the index for the array which will store each word.
  
  for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == ' ')
        index++;
        // If the program finds a whitespace, we will move on to the next index of the array.
      else
        strArray[index] += str[i];
      // We will store a character until the program finds a whitespace.
    }

  for (int j = 0; j < index+1; j++)
    {
      strArray[j] += strArray[j].at(0);
      // Add the first character to the last
      strArray[j].append("AY");
      // Add "AY" to the last
      strArray[j].erase(0, 1);
      // Delete the first character
    }
  
  for (int ctr = 0; ctr < index+1; ctr++)
    {
      pigLatin += strArray[ctr];
      if (ctr != index)
        pigLatin += ' ';
      // We don't need a whitespace at the end of the sentence.
    }
  return pigLatin;
}