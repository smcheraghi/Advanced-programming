#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

using namespace std;

class Menu
{
private:
	vector<string> option_list;						// stores a pointer to dynamic array of Text objects managed by this object
	string top_message;								// The opening message
	string bottom_message; 							// The closing message

public:
	Menu();											// Default constructor. Initializes top / bottom messages to empty strings, the options list to dynamic array of capacity 1, and count to O.
	void insert(int index, string& option);			// Inserts option at position index, shifting All options at or past index over to the right by one position.
	void insert(int index, const char* option);		// Inserts option at position index, shifting All options at or past index over to the right by one position.
	void push_back(const char* pOption);			// Adds supplied option to the end of the option list
	void push_back(const string& option);			// Adds supplied option to the end of the option list
	void remove(int index);							// Removes an option from the lists given index; shifts all options to the right of index left by one position.
	int size() const;								// Returns the number of options in the option list.
	void pop_back();								// Removes the last option in the list
	string get(int k);								// Return the k'th option
	string toString() const;						// Returns a Text object storing a string representation of this menu
	int read_option_number();						// Displays this menu and then readsand returns a valid option number
	void set_top_message(const string& m);			// Sets top message to m
	void set_bottom_message(const string& m);		// Sets bottom message to m
	void clear_top_message();						// Sets top message to empty text
	void clear_bottom_message();					// Sets bottom message to empty text
	bool isEmpty() const;							// Determines whether this menu's option list is empty
};
std::ostream& operator<<(std::ostream&, const Menu&);
#endif 

