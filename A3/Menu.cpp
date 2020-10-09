/**
* This class model a menu of options that is typically used in menu-driven text-based interactive programs, where
* the user is first presented with a list of options to choose from and is then promoted to enter a value corresponding
* to an option very similar to menu-based voice interface.
*
* @author  Seyed Mohammad Cheraghi
* @version 1.0
*/

#include<iostream>
#include "Menu.h"
#include <string>

using namespace std;

/**
* Default constructor. Initializes top / bottom messages to empty strings, the options list to dynamic array of capacity 1, and count to O.
*/
//Menu::Menu() : capacity { 1 }, count { 0 }, top_message { Text("") }, bottom_message { Text("") }, option_list { new Text[1] } {}
Menu::Menu() {
	this->top_message = "";											// Initializes top messages to empty strings	
	this->bottom_message = "";										// Initializes bottom messages to empty strings

}



/**
* Inserts option at position index, shifting All options at or past index over to the right by one position.
* @param index
* @param option
*/
void Menu::insert(int index, string& option) {
	if (this->isEmpty()) {
		cout << "Invalid choice " << index << " for function insert. There is no option, menu is empty." << endl;
	}
	else {
		if ((0 < index) && (index <= option_list.size())) {							// check that the index is in the range orr out of the range
			option_list.insert(option_list.begin() + index - 1, option);
			cout << "Option inserted successfully!" << endl;
		}
		else {
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1," << option_list.size() << "]" << endl;
		}
	}
}

/**
* Inserts option at position index, shifting All options at or past index over to the right by one position.
* @param index
* @return option
*/
void Menu::insert(int index, const char* option) {
	if (this->isEmpty()) {
		cout << "Invalid choice " << index << " for function insert. There is no option, menu is empty." << endl;
	}
	else {
		if ((0 < index) && (index <= option_list.size())) {							// check that the index is in the range orr out of the range
			option_list.insert(option_list.begin() + index - 1, option);
			cout << "Option inserted successfully!" << endl;
		}
		else {
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1," << option_list.size() << "]" << endl;
		}
	}
	
}

/**
* Adds supplied option to the end of the option list.
* @param pOption
*/
void Menu::push_back(const char* pOption) {
	this->option_list.push_back(pOption);
}

/**
* Adds supplied option to the end of the option list
* @param option
*/
void Menu::push_back(const string& option) {
	this->option_list.push_back(option);
}

/**
* Removes an option from the lists given index; shifts all options to the right of index left by one position.
* @param index
*/
void Menu::remove(int index) {
	if (index <= 0 || index > option_list.size())												// check for subscript out-of-range error
	{
		throw out_of_range("No such option");
	}
	this->option_list.erase(this->option_list.begin() + index - 1);
}

/**
* Returns the number of options in the option list.
* @return count
*/
int Menu::size() const {
	return this->option_list.size();														// return current count
}


/**
* Removes the last option in the list
*/
void Menu::pop_back() {
	if (this->option_list.empty()) {
		cout << "Can not pop back because the option list is empty" << endl;
	}
	else {
		option_list.pop_back();
	}
}

/**
* Return the k'th option
* @param k
* @return k'th option
*/
string Menu::get(int k) {
	if (k <= 0 || k > option_list.size())												// check for subscript out-of-range error
	{
		throw out_of_range("No such option");
	}
	return this->option_list[k - 1];
}
/*
Text Menu::get(int k) {
	if ((0 < k) && (k <= this->count)) {
		return this->option_list[k - 1];									// return the k'th option
	}
	else {
		cout << "Invalid input " << k << " for function get. It must be in the range [1," << this->count << "]" << endl;
		return Text("");
	}
}
*/


/**
* Returns a Text object storing a string representation of this menu
* @return Text
*/
string Menu::toString() const {
	string t = "";
	t.append("\n");
	std::string str;
	if (this->top_message.length() != 0) {
		t.append(this->top_message);
		t.append("\n");
	}
	for (int i = 0; i < this->option_list.size(); i++) {
		t.append("\t");
		std::string s;
		s = to_string(i + 1);
		const char* pcstr = s.c_str();
		t.append(pcstr);
		t.append(": ");
		t.append(this->option_list[i]);
		t.append("\n");
	}
	if (this->bottom_message.length() != 0) {
		t.append(this->bottom_message);
		t.append("\n");
	}
	t.append("??");
	return t;
}

/**
* Remove space from left side of string
* @param str: input string
* @return string
*/
string lStrip_removeSpace(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isspace(str[i])) {
			return str.substr(i);
		}
	}
}

/**
* Remove space from right side of string
* @param str: input string
* @return string
*/
string rStrip_removeSpace(string str) {
	int myCounter = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (!isspace(str[i])) {
			return str.substr(0, str.size() - myCounter);
		}
		++myCounter;
	}
}

/**
* Remove space from both side of string
* @param str: input string
* @return string
*/
string fullStrip_removeSpace(string str) {
	str = lStrip_removeSpace(str);
	str = rStrip_removeSpace(str);
	return str;
}

/**
* Check that the input string is only white space or not
* @param str: input string
* @return string
*/
string is_white_space_22(string str) {
	bool stringIsGood = false;
	if (str.empty()) {
		return str;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ' && str[i] != '\t') {
				return str;
			}
		}
	}
	return "";
}

/**
* Read int from input
* @return int
*/
int readInt() {
	bool not_digit = false;
	string str;
	getline(cin, str);
	str = fullStrip_removeSpace(str);
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			not_digit = true;
		}
	}
	if (!not_digit) {
		return stoi(str);
	}
	return 99099;
}

/**
* Displays this menu and then readsand returns a valid option number
* @return int
*/
int Menu::read_option_number() {
	while (true) {
		cout << *this;
		int enteredNum = -10;
		bool not_digit = false;
		string str;
		while (str.empty()) {
			getline(cin, str);
			str = is_white_space_22(str);
		}
		str = fullStrip_removeSpace(str);
	
		for (int i = 0; i < str.size(); i++) {
			if (!isdigit(str[i])) {
				not_digit = true;
			}
		}
		if (!not_digit) {
			enteredNum = stoi(str);
		}

		if (this->isEmpty()) {
			try {
				enteredNum = stoi(str);
				return enteredNum; // enteredNum;
			}
			catch (invalid_argument& e) {
				cout << "Invalid choice " << str << ". It must be an integer." << endl;
			}
		}
		else {
			if ((enteredNum > 0) && (enteredNum <= this->option_list.size())) {
				return enteredNum;
			}
			else {
				cout << "Invalid choice " << str << ". It must be in the range [1," << this->option_list.size() << "]" << endl;
			}
		}
	}
}

/**
* Sets top message to m
* @param m
*/
void Menu::set_top_message(const string& m) {
	this->top_message = m;
}

/**
* Sets bottom message to m
* @param m
*/
void Menu::set_bottom_message(const string& m) {
	this->bottom_message = m;
}

/**
* Sets top message to empty text
*/
void Menu::clear_top_message() {
	this->top_message = "";
}

/**
* Sets bottom message to empty text
*/
void Menu::clear_bottom_message() {
	this->bottom_message = "";
}

/**
* Determines whether this menu's option list is empty
* @return true or false
*/
bool Menu::isEmpty() const {
	return this->option_list.empty();
}

/**
* Assignment operator<< overload.
* @param sout
* @param mnu
* @return sout
*/
std::ostream& operator<<(std::ostream& sout, const Menu& mnu)
{
	sout << mnu.toString();
	return sout;
}

