// Description: this program asks an user to input some floating point numbers and display the maximum, minimum, and the average, using technique of class.
// Student name: Koichi Nakata
// Date: July 17, 2023
// Status: complete

#include <iostream>
#include <iomanip>
#include "NumArray.h"
using namespace std;

int main() {
  int size;
  cout << "\nHow many numbers do you wish to store? ";
  cin >> size;

  NumArray userArray(size);
  userArray.setArray();
  userArray.displayNum();

  cout << "\nMaximum number: " << userArray.findMax();
  cout << "\nMinimum number: " << userArray.findMin();
  cout << setprecision(2) << fixed;
  cout << "\nThe average of the numbers: " << userArray.getAverage();

  return 0;
}