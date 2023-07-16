// Description: this program tallys votes on favorite beverages.
// Student name: Koichi Nakata
// Date: June 14, 2023
// Status: complete

#include <iostream>
using namespace std;

int main() {
  int ctr, choice, valid, coffee, tea, coke, orangeJuice;
  ctr = 0; // This counts the number of voting
  choice = 0;
  valid = 1;
  coffee = tea = coke = orangeJuice = 0; // Initialize the tally

  cout << "\n*** Drink Menu ***\n";
  cout << "1. Coffee 2. Tea 3. Coke 4. Orange Juice\n\n";

  while (choice != -1) {
    cout << "\nPlease input the favoite beverage of person #" << ctr
         << ": Choose from 1, 2, 3, or 4 from the above menu"
         << " or -1 to exit the program: ";
    cin >> choice;

    while ((choice > 4) || (choice == 0) || (choice < -1)) {
      cout << "\nInvalid entry.. Please input an integer from ";
      cout << "1 to 4, or -1: ";
      cin >> choice;
    }

    if (choice == 1) {
      coffee++;
      ctr++;
    } else if (choice == 2) {
      tea++;
      ctr++;
    } else if (choice == 3) {
      coke++;
      ctr++;
    } else if (choice == 4) {
      orangeJuice++;
      ctr++;
    } else if (choice == -1) {
      cout << "\n\nThe total number of people surveyed is " << ctr
           << ". The result is as followed.\n";
      cout << "\nFavorite Beverage Survey Result\n";
      cout << "*******************************\n";
      cout << "Coffee: " << coffee << "\nTea: " << tea << "\nCoke: " << coke
           << "\nOrange Juice: " << orangeJuice;
    }
  }
}