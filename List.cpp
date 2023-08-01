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

/*
The newList() function will receive data from transferData() function at main function. After that, the newList() function 
will store the data received into the array inside the class List.
*/
void List::newList(string NAME[], string GENRE[], string DATERENT[]) {

	for (int i = 0; i < maxSize; i++) {

		name[i] = NAME[i];
		genre[i] = GENRE[i];
		dateRent[i] = DATERENT[i];
	}

	cout << "\nThe book list to rent has been processed.\n";
}