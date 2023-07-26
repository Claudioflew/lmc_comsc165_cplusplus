// Description: this prgram asks an user to input two numbers and displays swapped numbers.
// Student name: Koichi Nakata
// Date: June 15, 2023
// Status: complete

#include <iostream>
using namespace std;

void swapNums(double&, double&); // Prototype of the function. This function returns nothing.

int main() {
  double first, second;
  
  cout << "Please enter the first number and";
  cout << " then, press Enter: " << endl;
  cin >> first;

  cout << "Next, please enter the second number";
  cout << " and then, press Enter: " << endl;
  cin >> second;

  cout << "\n***Before swapping***\n";
  cout << "First: " << first <<
    ", Second: " << second << endl;
  
  swapNums(first, second);

  cout << "\n***After swapping***\n";
    cout << "First: " << first <<
    ", Second: " << second << endl;
}

void swapNums(double &first, double &second) {
  // Use reference variables because I want to use them outside this function.
  double temp = first;
  first = second;
  second = temp;
}