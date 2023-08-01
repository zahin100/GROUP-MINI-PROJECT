/*
Project Title : Books Rental System

Group Members' Name & Matric Number :

AKMAL ZAHIN BIN ZULKEPLI (B032010175)
SITI HAJAR BINTI AZI SHAUFI (B032010441)
DWAIN HANLON MATIN @ ALFRED (B032010243)
*/


#include <iostream>
#include <string>
using namespace std;
#include "List.h"
#include "Sort.h"

const int SIZE = 5;

// Structure of the book
struct Book
{
	string name;
	string genre;
	string dateRent;
};

Book list[SIZE];
List bookInfo;
Sort sortBook;
int front = -1;
int rear = -1;
int menuOperation();
void enqueue();
bool isEmpty();
void dequeue();
void transferData();
void giveData();


/*
At this main function, the user has to select 4 types of menu:
1. Add Item (Rent a book)
2. Process Item (Process the renting)
3. Display Items (View all book)
4. Exit

When the user choose menu 1, user need to choose 3 options which are add a book to rent, remove the first book to rent or
back to main menu. If user choose option 1 (Add a book to rent), the user need to enter the book name, genre and date of rent. 
Else if user choose option 2 (Remove the first book to rent), the first book in the queue will be removed. User can choose option
3 (Back) if they want to go back to the main menu.

For the menu 2, the item in menu 1 will be processed into a new normal list.

For menu 3, the data from menu 2 will be sorted in ascending order based on the book name and display the list of the books.

User can choose menu 4 to exit the program.
*/


int main()
{
	int operation, choice;
	int input;

	do
	{
		// Function call for menu operation. This function will allow the user to input what their choice is.
		operation = menuOperation();

		if (operation == 1)
		{
			do
			{
				cout << "Please choose if you want to : \n\n";
				cout << "1. Add a book to rent\n2. Remove the first book to rent\n3. Back\n";
				cout << "Enter your choice : ";
				cin >> input;

				if (input == 1)
					enqueue();

				else if (input == 2)
					dequeue();

				else if (input == 3)
					break;

				else
					cout << "Invalid choice. Please try again.\n\n";

			} while (input != 3);
		}

		else if (operation == 2)
		{
			transferData();
		}

		else if (operation == 3)
		{
			giveData();
			sortBook.simpleSort();
		}

		else if (operation == 4)
		{
			cout << "Thank you for your visit. We hope to see you again.";
		}
		else
			cout << "Invalid choice.Please try again.\n";

	} while (operation != 4);
	cout << endl;
	return 0;
}

int menuOperation()
{
	//The menu operation where the user choose. This act as a main menu
	int choice;
	cout << "\n---------------------------------------------------\n";
	cout << "\n\t\t*BOOKS RENTAL SYSTEM*\n";
	cout << "\n---------------------MAIN MENU---------------------\n";
	cout << "[ 1 ] Rent a book\n";
	cout << "[ 2 ] Process the renting\n";
	cout << "[ 3 ] View all books\n";
	cout << "[ 4 ] Exit\n";
	cout << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	cout << endl;
	return choice;
}

// Function to check if queue is empty
bool isEmpty()
{
	if (front == -1)
		return true;
	else
		return false;
}

//function to enter elements in queue
void enqueue()
{
	string value1, value2, value3;

	// Check whether queue is full or not.
	if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
		cout << "\nYou have reached the maximum number of books that you can rent.\n\n";

	else
	{
		//first element inserted
		if (front == -1)
			front = 0;

		//insert element at rear
		rear = (rear + 1) % SIZE;
		cin.ignore();
		cout << endl;
		cout << "Enter the Book Name : ";
		getline(cin, value1);
		cout << "Enter the Book Genre : ";
		cin >> value2;
		cout << "Enter the Rent Date (date/month/year) eg: 20/07/2021 : ";
		cin >> value3;
		cout << endl;
		list[rear].name = value1;
		list[rear].genre = value2;
		list[rear].dateRent = value3;
	}
}

//function to delete/remove element from queue
void dequeue()
{
	string temp;
	if (isEmpty())
		cout << "\nYou have not rent any book yet.\n\n";

	else {

		temp = list[front].name;
		//only one element
		if (front == rear)
			front = rear = -1;

		else {
			cout << "\nThe book with book name " << temp << " has been removed from the list.\n\n";
			front = (front + 1) % SIZE;
		}
	}
}

// Function to transfer data into class List
void transferData() {

	string N[SIZE], GR[SIZE], DR[SIZE];

	for (int i = 0; i < SIZE; i++) {

		N[i] = list[i].name;
		GR[i] = list[i].genre;
		DR[i] = list[i].dateRent;
	}

	bookInfo.newList(N, GR, DR);

}

// Function to transfer data into class Sort
void giveData() {

	string name[SIZE], genre[SIZE], dateRent[SIZE];

	for (int i = 0; i < SIZE; i++) {

		name[i] = bookInfo.name[i];
		genre[i] = bookInfo.genre[i];
		dateRent[i] = bookInfo.dateRent[i];
	}

	sortBook.getData(name, genre, dateRent);
}