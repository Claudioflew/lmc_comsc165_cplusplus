// Description: this program asks an user to input a sentence to be encrypted. And then, it converts the original sentence to an encrypted text and also can restore that to the original text. Each sentence is stored in a file respectively.
// Student name: Koichi Nakata
// Date: July 5, 2023
// Status: complete

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototype
string encryptText(string);
string decryptText(string);

int main() {
  string originalText, encryptedText, decryptedText;
  fstream original, encrypted, decrypted;

  cout << "Please write a sentence to be encrypted:\n";
  getline(cin, originalText);

  original.open("originalText.txt", ios::out);
  original << originalText;
  // Keep the original sentence in the memory.

  encryptedText = encryptText(originalText);

  cout << "\nThis is encrypted text:\n";
  cout << encryptedText << endl;

  encrypted.open("encryptedText.txt", ios::out);
  encrypted << encryptedText;
  // Keep the encrypted text in the memory.

  decryptedText = decryptText(encryptedText);

  decrypted.open("restoredText.txt", ios::out);
  decrypted << decryptedText;
  // Store the restored sentence in the memory.

  cout << "\nThis is restored text:\n";
  cout << decryptedText << endl;
  
  original.close();
  encrypted.close();
  decrypted.close();
}

// Encryption algorithm is simple. Just adds 10 to the original character ascii code, paying attention to that the characters appearing at the last part of the ascii code (such as 'x', 'y', 'z') has to be sent to the first part of the ascii code.
string encryptText(string originalText)
{
  string str, encryptedText;
  int asciiCode;
  
  for (int i = 0; i < originalText.length(); i++)
    {
      asciiCode = int(originalText[i]);
      if (asciiCode > 116) // If the ascii code is large
        asciiCode = asciiCode + 10 - 126 + 31;
      else
        asciiCode += 10;
      str = char(asciiCode);
      encryptedText.append(str);
    }

  return encryptedText;
}

string decryptText(string encryptedText)
{
  string str, decryptedText;
  int asciiCode;

  for (int i = 0; i < encryptedText.length(); i++)
    {
      asciiCode = int(encryptedText[i]);
      if (asciiCode >= 32 && asciiCode <= 41)
        asciiCode = asciiCode - 10 + 126 - 31; // This is doing the opposite from encryptText() function.
      else
        asciiCode -= 10;
      str = char(asciiCode);
      decryptedText.append(str);
    }
  return decryptedText;
}

