/*
Project Title : Books Rental System

Group Members' Name & Matric Number :

AKMAL ZAHIN BIN ZULKEPLI (B032010175)
SITI HAJAR BINTI AZI SHAUFI (B032010441)
DWAIN HANLON MATIN @ ALFRED (B032010243)
*/


#ifndef LIST_H
#define LIST_H

const int maxSize = 5;

/* 
The class List is a new normal list and will be used at menu 2. The class List will receive data from queue at menu 1
and store the data.
*/
class List {

public:
	string name[maxSize];
	string genre[maxSize];
	string dateRent[maxSize];
	void newList(string NAME[], string GENRE[], string DATERENT[]);

};

#endif