#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <string>
#include "MiniDB.h"
#include "Menu.h"
#include <vector>

using namespace std;

class LineManager {
private:
	MiniDB<string> items;											// Representing a database of string type
	Menu partial_Menu;												// A menu display when the database is empty
	Menu full_Menu;													// A menu display when the database is non-empty
	size_t upper_span;												// Spans of lines above the cp
	size_t lower_span;												// Spans of lines below the cp
	bool quite;														// Check the program continue or stop
	bool haveChanged;												// Check the database has been changed or not
	void generateMenu();											// Generate the partial_menu and full_menu
//	void generateMenu_1();											// Generate the partial_menu
//	void generateMenu_2();											// Generate the full_menu	
	bool interpretCommandLine(int input);							// Interpret the option number inserted by user
	void appendFromKey();											// Repeatedly prompt for and read a text from the keyboard and append it at the end of the database
	void insertFromKey();											// Repeatedly prompt for and read a text from the keyboard and insert it at cp, . is end of input entry
	void insertFromKey_2();											// Repeatedly prompt for and read a text from the keyboard and insert it at cp, . is end of input entry
	vector<string> readFromFile() const;							
	bool writeToFile(list<string> lst);								// This function take a list and write it to the file
	bool fileExist(string filename);								// Check that the file is extsted or not
	void setLower_span(int x);										// Set the lower span
	void setUpper_span(int x);										// Set the upper span
	void changeUpperLowerSpan(int x);								// Change lower and upper span based on the input integer. If n<0 change upper span, if n>0 change lower span and if n=0 change both to zero.
	void printSpanLines(vector<string> vec);						// Print upper_span line above the current line, followed by the line at the current line, followed by lower_span lines below the current line
	int readInt();													// Read integer from input
	void moveCurrentLine(int x);									// Move the current line to new index
	string lStrip_removeSpace(string str) const;					// Remove space from the left side of the string
	string rStrip_removeSpace(string str) const;					// Remove space from the right side of the string
	string fullStrip_removeSpace(string str) const;					// Remove space from the both side of the string
	string is_white_space(string str) const;						// Check that the input string is only white space or not

public:
	LineManager();													// Constructor
	LineManager(const LineManager& L) = default;					// Copy constructor
	LineManager& operator =(const LineManager& L) = default;		// Assignment operator
	void run();

};
#endif 