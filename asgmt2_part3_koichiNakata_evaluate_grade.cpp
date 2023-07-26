// Description: this program asks an user to input their score of the exams and output their grade based on the result of a calculation.
// Student name: Koichi Nakata
// Date: June 15, 2023
// Status: complete

#include <iostream>
#include <iomanip>
using namespace std;

void calculateAve(float scores[], int, float&);

int main() {
  int examNum;
  float average;
  char grade;

  cout << "How many exams did you take?\n";
  cin >> examNum;

  float scores[examNum];

  for (int ctr = 0; ctr < examNum; ctr++) {
    cout << "Please enter the score of exam " << ctr + 1 << " in integers:\n";
    cin >> scores[ctr];
  }

  calculateAve(scores, examNum, average);
  cout << fixed << setprecision(1);

  if (average >= 90) {
    grade = 'A';
  } else if (average >= 80) {
    grade = 'B';
  } else if (average >= 70) {
    grade = 'C';
  } else if (average >= 60) {
    grade = 'D';
  } else {
    grade = 'E';
  }

  cout << "\nYour average score: " << average << endl;
  cout << "Your grade: " << grade << endl;
}

void calculateAve(float scores[], int examNum, float &average) {
  float total = 0;

  for (int ctr = 0; ctr < examNum; ctr++) {
    total += scores[ctr];
  }
  average = total / examNum;
}