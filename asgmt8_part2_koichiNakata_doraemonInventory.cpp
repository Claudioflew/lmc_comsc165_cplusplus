// Description: this program manage multiple items in the inventory and save, edit, and make a report the data.
// Student name: Koichi Nakata
// Date: July 6, 2023
// Status: complete

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 51;

struct Inventory {
  char name[SIZE]; // I started with string first...
  int quantity;
  double wholesale, retail;
};

// Function prototype
int chooseMenu();
void readInitialData(string);
void displayEntry(Inventory);
void addEntry(string);
Inventory searchEntry(string);
void changeEntry(string);
void displayAll(string);
void reportInventory(string);
// First, I thought I should pass fstream data to the functions, but it will be difficult to control the fstream data (current position of reading and writing, closing, reading and writing more). Opening the file in each function is easier.

int main() {
  int choice;

  readInitialData("initial_inventory.txt");

  do {
    choice = chooseMenu();

    if (choice == 1)
      addEntry("inventory.dat");
    else if (choice == 2) {
      Inventory entry = searchEntry("inventory.dat");
      displayEntry(entry);
    } else if (choice == 3)
      changeEntry("inventory.dat");
    if (choice == 4)
      displayAll("inventory.dat");
    else if (choice == 5)
      reportInventory("inventory.dat");
    else if (choice == 6)
      cout << "\nThank you for using this program. Bye!\n";
  } while (choice != 6);
}

int chooseMenu() {
  int choice;

  cout << "\n1: Add a new record\n2: Display a record\n";
  cout << "3: Change data in a record\n4: Display all the records\n";
  cout << "5: Prepare a report\n6: Exit this program\n";
  cout << "\nPlease enter an option here: ";
  cin >> choice;
  cin.ignore(); // Erase the '\n' in the buffer
  
  return choice;
}

void readInitialData(string fileName) {
  Inventory entry;

  fstream inputFile(fileName, ios::in) // Reading mode
  fstream inventoryFile("inventory.dat", ios::out | ios::binary); // Writing mode 

  if (inputFile && inventoryFile) { // If opening is okay
    inputFile >> entry.name;
    while (!inputFile.eof()) { // Until the end of the file
      inputFile >> entry.quantity >> entry.wholesale >> entry.retail;
      inventoryFile.write((char *)&entry, sizeof(entry));
      // When we get a "chunk", which is one entry, write down the "chunk" into the dat file.
      inputFile >> entry.name; // To end the loop, this is needed.
    }
  }
  inputFile.close();
  inventoryFile.close();
}

void displayEntry(Inventory entry) {
  cout << "\nName: " << entry.name << "\nQuantity: " << entry.quantity
       << "\nWholesale price: " << entry.wholesale
       << "\nRetail price: " << entry.retail << endl;
}

void addEntry(string fileName) {
  Inventory entry;

  fstream inventoryFile(fileName, ios::app | ios::binary); // Append mode

  cout << "\nPlease enter the following data about an item:\n";
  cout << "Name: ";
  cin.getline(entry.name, SIZE);
  cout << "Quantity: ";
  cin >> entry.quantity;
  while (entry.quantity < 0) {
    cout << "Invalid entry. Please input a positive integer: ";
    cin >> entry.quantity;
  }
  cout << "Wholesale price: ";
  cin >> entry.wholesale;
  while (entry.wholesale < 0) {
    cout << "Invalid entry. Please input a positive floating number: ";
    cin >> entry.wholesale;
  }
  cout << "Retail price: ";
  cin >> entry.retail;
  while (entry.retail < 0) {
    cout << "Invalid entry. Please input a positive floating number: ";
    cin >> entry.retail;
  }

  // We are at the end of the file, so we don't need to worry about the position in the file. Just add the chunk of data.
  inventoryFile.write(reinterpret_cast<char *>(&entry), sizeof(entry));
  inventoryFile.close();
  cout << "\nThe item has been saved in the file!\n";
}

Inventory searchEntry(string filename) {
  Inventory entry;
  int index = 0, len, match;
  string target;
  bool found = false;
  fstream inventoryFile(filename, ios::in | ios::binary);

  cout << "\nPlease enter a name of the item: ";
  getline(cin, target);
  len = target.length();

  while (inventoryFile && !found) { // When found, end the loop.
    match = 0; // Matching characters
    inventoryFile.seekg((sizeof(entry) * index), ios::beg);
    // We move chunk to chunk in the fie. The size of the chunk is sizeof(chunk), and iterate the index.
    inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry));
    // Read a chunk one by one.
    for (int i = 0; i < len; i++) {
      if (entry.name[i] == target[i])
        match++;
    }
    if (match == len) // If matching size is the same of the length of the user input, that means we found it!
      found = true;
    index++; // Move on to the next "chunk"
  }
  inventoryFile.close();
  return entry;
}

void changeEntry(string filename) {
  Inventory entry;
  int index = 0;
  string target;

  fstream inventoryFile(filename, ios::in | ios::out | ios::binary);

  cout << "\nPlease enter an exact name of the item to edit: ";
  getline(cin, target);

  while (inventoryFile) { // If opening if okay
    inventoryFile.seekg((sizeof(entry) * index), ios::beg); // We move chunk to chunk
    inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry));
    if (entry.name == target)
      break; // If found, stop searching and save the index. This index is important!
    index++;
  }

  cout << "\nCurrent data about " << entry.name << ':' << endl;
  displayEntry(entry);

  cout << "\nPlease enter new data:\n";
  cout << "Name: ";
  cin.getline(entry.name, SIZE);
  cout << "Quantity: ";
  cin >> entry.quantity;
  while (entry.quantity < 0) {
    cout << "Invalid entry. Please input a positive integer: ";
    cin >> entry.quantity;
  }
  cout << "Wholesale price: ";
  cin >> entry.wholesale;
  while (entry.wholesale < 0) {
    cout << "Invalid entry. Please input a positive floating number: ";
    cin >> entry.wholesale;
  }
  cout << "Retail price: ";
  cin >> entry.retail;
  while (entry.retail < 0) {
    cout << "Invalid entry. Please input a positive floating number: ";
    cin >> entry.retail;
  }

  inventoryFile.seekp((sizeof(entry) * index), ios::beg);
  // This index is important. We move to the right position in the file.
  inventoryFile.write(reinterpret_cast<char *>(&entry), sizeof(entry)); // Overwrite the data
  inventoryFile.close();
  cout << "\nThe item was editted!\n";
}

void displayAll(string fileName) {
  Inventory entry;
  fstream inventoryFile(fileName, ios::in | ios::binary);

  if (inventoryFile) {
    inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry)); // Read one chunk of data
    while (!inventoryFile.eof()) {
      displayEntry(entry);
      inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry)); // This is needed to end the loop
    }
  }
  inventoryFile.close();
}

void reportInventory(string filename) {
  Inventory entry;
  int totalQ = 0;
  double totalW = 0, totalR = 0;
  fstream inventoryFile(filename, ios::in | ios::binary);

  if (inventoryFile) {
    inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry));
    while (!inventoryFile.eof()) {
      totalQ += entry.quantity;
      totalW += entry.wholesale;
      totalR += entry.retail;
      inventoryFile.read(reinterpret_cast<char *>(&entry), sizeof(entry));
    }
  }
  inventoryFile.close();
  cout << "\nTotal quantity: " << totalQ << endl;
  cout << "Total wholesale price: " << totalW << endl;
  cout << "Total retail price: " << totalR << endl;
}