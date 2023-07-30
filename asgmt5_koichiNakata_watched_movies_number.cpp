// Description: this set of programs demonstartes the usage of pointers. Detailed description is written besides each function.
// Student name: Koichi Nakata
// Date: June 27, 2023
// Status: complete

#include <iostream>
#include <iomanip>
using namespace std;

int* makeSurveyArray(int);
void sortArray(int*, int);
void showArray(int*, int);
double calcuAverage(int*, int);
double calcuMedian(int*, int);
int calcuMode(int*, int);

int main() {
  int studentsNum;
  int* surveyArray = nullptr; // Set the address null
  
  cout << "How many students did you survey? ";
  cin >> studentsNum;

  cout << "\nPlease enter how many movies each students watched.\n\n";
  surveyArray = makeSurveyArray(studentsNum);
  
  cout << "\nThis is the result:\n";
  showArray(surveyArray, studentsNum);

  cout << fixed << showpoint << setprecision(2);
  cout << "\nThe average number of the movies: ";
  cout << calcuAverage(surveyArray, studentsNum) << endl;

  cout << "\nThis is the sorted result in ascending order:\n";
  // To find the median, we need to sort the array first.
  sortArray(surveyArray, studentsNum);
  showArray(surveyArray, studentsNum);

  cout << "\nThe median of the number of the movies: ";
  cout << calcuMedian(surveyArray, studentsNum) << endl;

  int mode = calcuMode(surveyArray, studentsNum);
  if (mode == -1) // If not found the mode
    cout << "\nThere was no mode in the survey." << endl;
  else // If found the mode
  {
    cout << "\nThe mode of the number of the movie: ";
    cout << mode;
  }
  
  delete [] surveyArray;
  surveyArray = 0;

  return 0;
}

int* makeSurveyArray(int num)
// This function asks an user how many movies each student watched, and create and return an array.
{
  int* arr = nullptr;
  arr = new int[num]; // Dynamically alocate an empty array

  for (int ctr = 0; ctr < num; ctr++)
    {
      cout << "Student " << ctr+1 << ": ";
      cin >> *(arr + ctr); // Use pointer notation
    }
  return arr;
}


double calcuAverage(int* arr, int num)
// This function just tally the total of the number of the watched movie and divide the total by the number of the students surveyed.
{
  double total = 0, average;

  for (int i = 0; i < num; i++)
    total += *(arr + i); // Use pointer notation

  average = total / num;
  return average;
}

void sortArray(int* arr, int num)
// This function does selection sorting, using pointer notation.
{
  for (int outer = 0; outer < (num-1); outer++)
    {
      for (int inner = (outer+1); inner < num; inner++)
        {
          if (*(arr + inner) < *(arr + outer))
          {
            int temp = *(arr + outer);
            *(arr + outer) = *(arr + inner);
            *(arr + inner) = temp;
          }
        }
    }
}

double calcuMedian(int* arr, int num)
// This function finds and returns the median in the array.
{
  int middle; // This will be the index of the median.
  double median;
  
  if (num % 2 == 1) // If the array size is odd
  {
    middle = (num - 1) / 2;
    median = *(arr + middle);
  }
  else // If the array size is even
  {
    middle = num / 2;
    median = (*(arr + middle) + *(arr + (middle-1))) / 2.00;
  }
  return median;
}

int calcuMode(int* arr, int num)
// This function wants to tally the appearance of each number of the watched movies and make a 2D array i.e. watched movies once: 2 students, twice: 1 student, three times: 4 students...
// And finds the biggest frequency and returns the value which appears most.
{
  int mode[num][2]; // Make an empty (num)x2 array
  int index = 0; // Set the 2D array's index 0
  bool noMode = true; // Flag variable

  mode[index][0] = *(arr);
  mode[index][1] = 1;
  // First of all, it inserts the first element.

  for (int i = 1; i < num; i++) // We start from the second element.
  {
    if (*(arr + i) != *(arr + (i-1)))
    // If the element is different from the element one index before, that means the occurance of the number ends.
    {
      index++;
      mode[index][0] = arr[i];
      mode[index][1] = 1;
    }
    else
    // If the element is the same as the element one index before, we need to add 1 to that value.
    {
      mode[index][1]++;
      noMode = false;
    }
  }
  
  if (noMode)
    return -1;
  else
  {
    int modeNum = mode[0][0]; // Temporary maximum
    int max = mode[0][1]; // Temporary mode
    for (int j = 0; j < (index+1); j++)
      {
        if (mode[j][1] > max)
        {
          max = mode[j][1];
          modeNum = mode[j][0];
        }
      }
    return modeNum;
  }
}


void showArray(int* arr, int num)
// This function just shows the current look of the array.
{
  cout << "[";
  for (int i = 0; i < num; i++)
    {
      cout << *(arr + i);
      if (i != (num-1))
        cout << ", ";
    }
  cout << "]\n";
}