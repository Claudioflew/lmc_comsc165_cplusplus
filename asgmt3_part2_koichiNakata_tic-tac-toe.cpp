// Description: this program demonstrates tic-tac-toe.
// Student name: Koichi Nakata
// Date: June 18, 2023
// Status: complete

#include <iostream>
using namespace std;

const int ROW = 3, CLN = 3; // Define the board size.

void showBoard(char [][CLN]);
void selectPlace(char [][CLN], char);
bool checkBoard(char [][CLN], char);

int main() {
  char board[3][3] = {{'*', '*', '*'},
                      {'*', '*', '*'},
                      {'*', '*', '*'}};

  bool won = false; // Flag variables
  int count = 0; // Counts how many times players select.
  
  while (not won && count < 9) {
    showBoard(board);
    selectPlace(board, 'O');
    count++;
    won = checkBoard(board, 'O');
    if (not won && count < 9) {
      showBoard(board);
      selectPlace(board, 'X');
      count++;
      won = checkBoard(board, 'X');
      if (won) {
        cout << "\nPlayer X won!\n";
        showBoard(board);
      }
    }
    else if (not won && count == 9) {
      cout << "\nIt's a tie!\n";
    }
    else {
      cout << "\nPlayer O won!\n";
      showBoard(board);
    }
  }
  return 0;
}


void showBoard(char board[][CLN]) {
  cout << endl;
  for (int row = 0; row < ROW; row++) {
    for (int cln = 0; cln < CLN; cln++) {
      cout << board[row][cln] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}


void selectPlace(char board[][CLN], char marker) {
  int selectRow, selectCln;
  cout << "Player " << marker << "'s turn\n";
  cout << "Please select a place by specifying a row and a column number.\n";
  cout << "Row: ";
  cin >> selectRow;
  cout << "Column: ";
  cin >> selectCln;

  board[selectRow][selectCln] = marker;
}


bool checkBoard(char board[][CLN], char marker) {
  int row, cln, markerNum;
  // This for loop checks if there are the three consective markers in a row horizontally.
  for (row = 0; row < ROW; row++) {
    markerNum = 0;
    for (cln = 0; cln < CLN; cln++) {
      if (board[row][cln] == marker) {
        markerNum += 1;
      }
    }
    if (markerNum == 3) {
      return true;
      break;
    }
  }

  // This for loop checks if there are the three consective markers in a row vertically.
  for (cln = 0; cln < CLN; cln++) {
    markerNum = 0;
    for (row = 0; row < ROW; row++) {
      if (board[row][cln] == marker) {
        markerNum += 1;
      }
    }
    if (markerNum == 3) {
      return true;
      break;
    }
  }

  // Manually check diagonally.
  if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
    return true;
  }
  else if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
    return true;
  }
  return false;
}