// Description: this program tallys how many days the tellers in the bank got sick days off.
// Student name: Koichi Nakata
// Date: June 14, 2023
// Status: complete
#include <iostream>
using namespace std;

int main() {
  int num;
  int total = 0; // Tally the total sick leaves

  cout << "How many tellers worked at Nation’s Bank ";
  cout << "during the last three years?\n";
  cin >> num;

  int sickDaysArray[num * 3];
  // Make an empty array so we insert sick days for each teller. Because we
  // can't make a two dimension array, we make a linear array (each teller * 3
  // years).

  for (int teller = 0; teller < num; teller++) {
    // Outer loop is for each teller.
    for (int year = 0; year < 3; year++) {
      // Inter loop is for each teller's year entry.
      cout << "How many days was teller " << teller + 1
           << " out sick during year " << year + 1 << endl;
      int index = (teller * 3) + year;
      // Each teller's first entry starts from multiple of 3.
      cin >> sickDaysArray[index];
    }
  }
  for (int ctr = 0; ctr < num * 3; ctr++) {
    total += sickDaysArray[ctr];
  }
  cout << "The " << num << " tellers were out sick for"
       << " a total of " << total << " days during "
       << "the last three years.";
}