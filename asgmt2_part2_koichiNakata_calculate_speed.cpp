// Description: this program calculate a speed.
// Student name: Koichi Nakata
// Date: June 15, 2023
// Status: complete

#include <iostream>
#include <iomanip>
using namespace std;

double calculateSpeed(double, double, double&);

int main() {
  double miles, hours, milesPerHour;
  
  cout << "Please enter the miles traveled:\n";
  cin >> miles;
  cout << "Please enter the hours traveled:\n";
  cin >> hours;

  calculateSpeed(miles, hours, milesPerHour);
  
  cout << setprecision(2) << fixed; // Setup for the proper display.

  cout << "Your speed is " << milesPerHour <<
    " miles per hour.";
}

double calculateSpeed(double miles, double hours, double &milesPerHour) {
  milesPerHour = miles / hours;
  return milesPerHour;
}