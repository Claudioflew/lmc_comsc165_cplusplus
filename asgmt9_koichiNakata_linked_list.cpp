// Description: this program allows an user to edit a list containing numbers by using linked list.
// Student name: Koichi Nakata
// Date: July 9, 2023
// Status: complete

#include <iostream>
using namespace std;

struct Node
{
  int num;
  Node* next;
};

// Function prototypes
int chooseMenu();
void insertNum(int, Node*&);
void deleteNum(int, Node*&);
void searchNum(int, Node*);
void displayAll(Node*);

int main()
{
  Node* head = new Node; // Allocate the head in a dynamic momory.
  head->next = nullptr; // Initialize the head to point to NULL.
  int choice, num;

  do
  {
    choice = chooseMenu();
    if (choice == 1)
    {
      cout << "\nPlease enter an integer to be inserted: ";
      cin  >> num;
      insertNum(num, head);
    }
    else if (choice == 2)
    {
      cout << "\nPlease enter an integer to be deleted: ";
      cin  >> num;
      deleteNum(num, head);
    }
    else if (choice == 3)
    {
      cout << "\nPlease enter an integer to be searched: ";
      cin  >> num;
      searchNum(num, head);
    }
    else if (choice == 4)
      displayAll(head);
    else if (choice == 5)
      cout << "\nThank you for using this program. Bye!\n";
  } while (choice != 5);
  return 0;
}

int chooseMenu()
{
  int choice;
  cout << "\n***Linked List Menu***\n";
  cout << "1: Insert an integer\n2: Delete an integer\n";
  cout << "3: Search an integer\n4: Display the numbers\n";
  cout << "5: Exit this program\n";
  cout << "\nPlease enter an option: ";
  cin >> choice;
  return choice;
}

void insertNum(int n, Node* &head) // Node the head points to might change, so head has to be passed by reference.
{
  Node* newNodePtr = new Node; // Allocate new node in a dynamic memory.
  newNodePtr->num = n; // Store the user-input number in the new node.
  Node* previous;
  Node* current;

  for (previous = head, current = head->next; current != nullptr; previous = previous->next, current = current->next)
    // We need two pointers because the previous one should point to the new node, and the current one should be pointed by the new node.
    {
      if (current->num == n)
      {
        cout << "\nError: duplicated number can't be inserted..\n";
        return;
        // If the user-input number is identical with the number in the list, do nothing.
      }
      else if (current->num > n)
        break;
      // By breaking, save the current pointing the target node before which the new node should be inserted.
    }
  newNodePtr->next = current; // New node should point to current which is pointing to the target node.
  previous->next = newNodePtr; // To insert, the previous node should point to the new node.
  cout << "\nThe number is inserted!\n";
}

void deleteNum(int n, Node* &head)
// head pointer might be changed to point to different node, therefore we need to pass it by reference.
{
  Node* previous;
  Node* current;

  for (previous = head, current = head->next; current != nullptr; previous = previous->next, current = current->next)
    {
      if (current->num == n)
        break;
    }
  if (current == nullptr)
    cout << "\nThe number wasn't found in the list..\n";
  else
  {
    previous->next = current->next; // This skip the target node.
    delete current; // Don't forget to delete the target node.
    cout << "\nThe number was deleted.\n";
  }
}

void searchNum(int n, Node* head)
// head pointer doens't change in this function, so we don't need to pass by reference.
{
  Node* current;

  for (current = head->next; current != nullptr; current = current->next)
    {
      if (current->num == n)
        break;
    }
  if (current == nullptr)
    cout << "\nThe number is not in the list.\n";
  else
    cout << "\nThe number is in the list.\n";
}

void displayAll(Node* head)
// head pointer won't change in this function too. No need to pass by reference.
{
  Node* current;

  if (head->next == nullptr)
  {
    cout << "\nList is empty..\n";
    return;
  }
  cout << "\nThe list contains:\n";
  for (current = head->next ; current != nullptr; current = current->next)
    cout << current->num << " ";
  cout << endl;
  return;
}
