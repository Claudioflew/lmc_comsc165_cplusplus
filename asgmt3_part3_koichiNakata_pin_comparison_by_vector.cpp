// Description: this program compares two vectors if they are identical or not.
// Student name: Koichi Nakata
// Date: June 19, 2023
// Status: complete

#include <iostream>
#include <vector>
using namespace std;

bool testPIN(const vector<int>, const vector<int>);

int main() 
{
  const int NUM_DIGITS = 7;
  vector<int> pin1(NUM_DIGITS);
  vector<int> pin2(NUM_DIGITS);
  vector<int> pin3(NUM_DIGITS);
  
  pin1 = {2, 4, 1, 8, 7, 9, 0};
  pin2 = {2, 4, 6, 8, 7, 9, 0};
  pin3 = {1, 2, 3, 4, 5, 6, 7};
  
  if (testPIN(pin1, pin2))
    cout << "ERROR: pin1 and pin2 report to be the same.\n";
  else
    cout << "SUCCESS: pin1 and pin2 are different.\n";
  
  if (testPIN(pin1, pin3))
    cout << "ERROR: pin1 and pin3 report to be the same.\n";
  else
    cout << "SUCCESS: pin1 and pin3 are different.\n";
  
  if (testPIN(pin1, pin1))
    cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
  else
    cout << "ERROR: pin1 and pin1 report to be different.\n";
  
  return 0;
}


bool testPIN(const vector<int> custPIN, const vector<int> databasePIN)
// We don't need to pass "size" of the vector as a parameter because the vector has the method .size() to tell its size.
{
  for (int index = 0; index < custPIN.size(); index++) 
  {
    if (custPIN[index] != databasePIN[index]) 
      return false;
  }
  return true;
}