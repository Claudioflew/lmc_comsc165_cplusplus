// Description: this program asks an user to input integers and display them in ascending order. And then, it requests an integer they wish to search for the array and show the mean of the integers in the array.
// Student name: Koichi Nakata
// Date: June 21, 2023
// Status: complete

#include <iostream>
#include <iomanip>
using namespace std;

// function prototype
void makeArray(int [], int &);
void sortArray(int [], int);
void showArray(int [], int);
int searchNum(int [], int, int);
double calcuMean(int [], int);

int main() 
{
  int arr[50]; // Make an empty array
  int count = 0; // Counts the number of elements
  int target;

  makeArray(arr, count);

  cout << "\nThis is what you entered: \n";
  showArray(arr, count);

  sortArray(arr, count);

  cout << "\nThis is the sorted array of the integers you entered: \n";
  showArray(arr, count);

  cout << "\nPlease enter the integer you wish to search for: ";
  cin >> target;

  int result = searchNum(arr, count, target);

  if (result == -1)
    cout << "\nSorry, we don't have that integer in the array.." << endl;
  else
  {
    cout << "\nWe found the number " << target <<  " at element " <<
    result << " in the array." << endl;
  }

  cout << fixed << showpoint << setprecision(2);
  cout << "\nThe mean of the integers in the array: " <<
    calcuMean(arr, count) << endl;
  
  return 0;
}


void makeArray(int arr[], int &count)
{ 
  char again = 'Y'; // Sentinel variable
  do
    {
      cout << "Please enter an integer here: ";
      cin >> arr[count];
      count++;
      cout << "Do you want to add more? Y or N: ";
      cin >> again;
    } while (again != 'N' && again != 'n');
}

void sortArray(int arr[], int count)
// This does selection sort
{
  for (int outer = 0; outer < count-1; outer++)
    {
      for (int inner = outer+1; inner < count; inner++)
        {
          if (arr[outer] > arr[inner])
          {
            int temp = arr[outer];
            arr[outer] = arr[inner];
            arr[inner] = temp;
          }
        }
    }
}

void showArray(int arr[], int count)
{
  for (int i = 0; i < count; i++)
    cout << arr[i] << endl;
}

int searchNum(int arr[], int count, int target)
{
  int first = 0, last = count-1, middle;
  bool found = false;

  while (!found && first <= last)
    {
      middle = (first + last) / 2;
      if (arr[middle] == target)
      {
        found = true;
        return middle;
      }
      else if (target < arr[middle])
        last = middle - 1;
      else
        first = middle + 1;
    }
  return -1;
}

double calcuMean(int arr[], int count)
{
  double total = 0, mean;

  for (int i = 0; i < count; i++)
    total += arr[i];

  mean = total / count;
  return mean;
}