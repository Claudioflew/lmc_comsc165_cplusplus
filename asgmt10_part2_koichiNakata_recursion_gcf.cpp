// Decsription: this program asks an user to input two integers and check the GCF.
// Student name: Koichi Nakata
// Date: July 11, 2023
// Status: complete

#include <iostream>
#include <cctype>
using namespace std;

// Function prototype
int calcGCF(int, int);

int main() {
  int big, small, gcf;
  char repeat;
  do
    {
      cout << "\nPlease enter two integers to check the GCF. Larger number should be input first.\n";
      cout << "\nLarger number: ";
      cin >> big;
      cout << "Smaller number: ";
      cin >> small;

      gcf = calcGCF(big, small);
      if (gcf == 1) // This means there is no gcf.
        cout << "\nThere is no GCF between those numbers.." << endl;
      else
        cout << "\nThe GCF of " << big << " and " << small << " is " << gcf << endl;

      cout << "\nDo you want to check another numbers? (Y/N): ";
      cin >> repeat;
    } while (toupper(repeat) == 'Y');
}

int calcGCF(int b, int s)
{
  int r = b % s;
    
  if (r == 0)
    return s;
  else
    return calcGCF(s, r); // The recursive function should be called as a return, otherwise each recursion doesn't teminate.
}