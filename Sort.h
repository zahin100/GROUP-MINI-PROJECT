/*
Project Title : Books Rental System

Group Members' Name & Matric Number :

AKMAL ZAHIN BIN ZULKEPLI (B032010175)
SITI HAJAR BINTI AZI SHAUFI (B032010441)
DWAIN HANLON MATIN @ ALFRED (B032010243)
*/


#ifndef SORT_H
#define SORT_H

const int NUM = 5;

/*
The class Sort will be used at menu 3. The class Sort will receive data from class List at menu 2 and store 
the data. After that, class Sort will sort the data in ascending order based on the book name and display 
the list of the books.
*/
class Sort {

private:
	string bookName[NUM];
	string bookGenre[NUM];
	string bookdateRent[NUM];

public:
	void getData(string NAME[], string GENRE[], string DATERENT[]);
	void simpleSort();

};

#endif
