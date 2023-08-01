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
#include "Sort.h"

/*
getData() function will receive data from giveData() function at main function. After that, the getData() function
will store the data into the arrays inside the class Sort.
*/
void Sort::getData(string NAME[], string GENRE[], string DATERENT[]) {

	for (int i = 0; i < NUM; i++) {

		bookName[i] = NAME[i];
		bookGenre[i] = GENRE[i];
		bookdateRent[i] = DATERENT[i];
	}

}

/*
simpleSort() function will sort the data in ascending order based on the book name and display the list of the books.
*/ 
void Sort::simpleSort() {

	for (int i = 0; i < NUM; i++) {

		int smallestIndex = i;

		for (int m = i + 1; m < NUM; m++) {

			if (bookName[m] < bookName[smallestIndex])
				smallestIndex = m;
		}

		swap(bookName[smallestIndex], bookName[i]);
		swap(bookGenre[smallestIndex], bookGenre[i]);
		swap(bookdateRent[smallestIndex], bookdateRent[i]);
	}

	cout << "Below are the list of books that you rent.\n\n";

	for (int i = 0; i < NUM; i++) {

		// Skip one iteration if the array is empty
		if (bookName[i] == "\0")
			continue;

		cout << "Book name : " << bookName[i] << endl;
		cout << "Book genre : " << bookGenre[i] << endl;
		cout << "Date of rent : " << bookdateRent[i] << endl;
		cout << endl;
	}
}