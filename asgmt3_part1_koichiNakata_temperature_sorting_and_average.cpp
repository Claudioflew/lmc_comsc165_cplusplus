// Description: this program asks an user to input temperatures and sort them. And, it will show the average temperature.
// Student name: Koichi Nakata
// Date: June 18, 2023
// Status: complete

#include <iostream>
#include <iomanip>
using namespace std;

void showArray(int [], int);
void inputArray(int [], int, int &);
void orderAscend(int [], int);
float calcuAverage(int [], int);

int main() {
  int temperature[10], count = 0;

  inputArray(temperature, 10, count);
  cout << "\nYour input was like this:\n";
  showArray(temperature, count);

  orderAscend(temperature, count);
  cout << "\nThis is an array ordered ascendingly:\n";
  showArray(temperature, count);

  cout << "\nThe average temperature:\n";
  cout << fixed << setprecision(2) << showpoint;
  cout << calcuAverage(temperature, count);
}


void showArray(int arr[], int count) {
  for (int i = 0; i < count; i++) {
    cout << arr[i] << endl;
  }
}


void inputArray(int arr[], int size, int &count) {
  // This "count" variable is most important... This has to be used outside this function.
  int val = 0;

  cout << "Please enter a temperature on consective days.\n";
  cout << "When you finish, please input -1:\n";
  while (val != -1 && count < size) {
    // This loop ends when an user enter -1 or reaches 10 entries.
    cout << "Day " << count + 1 << ": ";
    cin >> val;

    if (val != -1) {
      arr[count] = val;
      count++;
      // If an user inputs -1, that -1 won't be added to the array and ends the while loop.
    }
  }
}


void orderAscend(int arr[], int count) {
  for (int outer = 0; outer < (count - 1); outer++) {
    // Make a base which we are going to compare to other numbers in an array.
    for (int inner = outer; inner < count; inner++) {
      if (arr[outer] > arr[inner]) {
        int temp = arr[outer];
        // Anyway we evacuate the original number to a temporary variable so that we can copy to the new number.
        arr[outer] = arr[inner];
        arr[inner] = temp;
      }
    }
  }
}


float calcuAverage(int arr[], int count) {
  int total = 0;

  for (int i = 0; i < count; i++) {
    total += arr[i];
  }

  float average = static_cast<float>(total) / count;
  // Convert int variable to float one so that we can computate float average.
  return average;
}

