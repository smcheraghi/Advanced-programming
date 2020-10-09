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
	this->capacity = 1;														// Initializes capacity to 1
	this->count = 0;														// Initializes count to 0			
	this->top_message = Text("");											// Initializes top messages to empty strings	
	this->bottom_message = Text("");										// Initializes bottom messages to empty strings
	this->option_list = new Text[this->capacity];							// allocate new storage options list to dynamic array of capacity 1
}


/**
* Copy Constructor; deep copies mnu into the object being constructed.
* @param mnu
*/
/*
Menu::Menu(const Menu& mnu) : capacity { mnu.capacity }, count { mnu.count }, top_message { mnu.top_message }, bottom_message { mnu.bottom_message }, option_list { new Text[mnu.capacity] }
{
	for (size_t i = 0; i < this->count; i++) {
		this->option_list[i] = mnu.option_list[i];
	}
}
*/
Menu::Menu(const Menu& mnu) {
	this->capacity = mnu.capacity;											// Initializes capacity to mnu capacity
	this->count = mnu.count;												// Initializes count to mnu count
	this->top_message = mnu.top_message;									// Initializes top messages to mnu top messages
	this->bottom_message = mnu.bottom_message;								// Initializes bottom messages to mnu bottom messages
	this->option_list = new Text[this->capacity];							// allocate new storage options list to dynamic array of capacity of mnu
	for (size_t i = 0; i < this->count; i++) {
		this->option_list[i] = mnu.option_list[i];							// deep copies mnu into the object being constructed
	}
}


/**
* Destructor. Releases dynamic storage in use by the options list
*/
Menu::~Menu() {
	this->capacity = 0;														// assign 0 to capacity
	this->count = 0;														// assign 0 to count
	this->top_message.clear();												// make top message clear
	this->bottom_message.clear();											// make bottom message clear
	delete[] option_list;													// Releases dynamic storage in use by the options list
	this->option_list = nullptr;											// assign nullptr to option list
}

/**
* Assignment operator= overload. Assigns the right hand side operand to this object, replacing its current contents
* @param m
* @return this object
*/
Menu& Menu::operator=(const Menu& m) {
	if (this != &m) {														// check that m is same or not than current object
		this->count = m.count;												// assign m count to current count
		this->capacity = m.capacity;										// assign m capacity to current capacity
		this->top_message = Text(m.top_message.getCstring());				// assign m top message to current top message
		this->bottom_message = Text(m.bottom_message.getCstring());			// assign m bottom message to current bottom message
		delete[] this->option_list;											// Releases dynamic storage in use by the options list
		this->option_list = new Text[this->capacity];						// allocate new storage options list to dynamic array of capacity of m
		for (int i = 0; i < m.count; i++) {
			this->option_list[i] = Text(m.option_list[i].getCstring());		// copies m into the current object option list
		}
	}
	return *this;
}

/**
* Inserts option at position index, shifting All options at or past index over to the right by one position.
* @param index
* @param option
*/
void Menu::insert(int index, Text& option) {
	if ((0 < index) && (index <= this->count)) {							// check that the index is in the range orr out of the range
		if (this->count == this->capacity) {						
			double_capacity();												// double the capacity			
		}
		Text* temp_optionlist = new Text[this->capacity];					// allocate new temporary storage
		int j = 0;
		for (int i = 0; i < this->count; i++) {
			if (i != index - 1) {
				temp_optionlist[j] = this->option_list[i];					// fill the temporary storage with current option list
				j++;
			}
			else {
				temp_optionlist[j] = option;								// fill the temporary storage with the parameter
				j++;
				temp_optionlist[j] = this->option_list[i];					// fill the temporary storage with current option list
				j++;
			}
		}
		this->count++;														// increse the count
		delete[] this->option_list;											// Releases dynamic storage in use by the options list
		this->option_list = temp_optionlist;								// assign the temporary storage to the current option list
		cout << "Option inserted successfully!" << endl;
	}
	else {
		if (this->count == 0) {
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1, 1]" << endl;
		}else
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1," << this->count << "]" << endl;
	}
}

/**
* Inserts option at position index, shifting All options at or past index over to the right by one position.
* @param index
* @return option
*/
void Menu::insert(int index, const char* option) {
	if ((0 < index) && (index <= this->count)) {							// check that the index is in the range orr out of the range
		if (this->count == this->capacity) {
			double_capacity();												// double the capacity
		}
		Text* temp_optionlist = new Text[this->capacity];					// allocate new temporary storage
		int j = 0;
		for (int i = 0; i < this->count; i++) {
			if (i != index - 1) {
				temp_optionlist[j] = this->option_list[i];					// fill the temporary storage with current option list
				j++;
			}
			else {
				temp_optionlist[j] = Text(option);							// fill the temporary storage with the parameter
				j++;
				temp_optionlist[j] = this->option_list[i];					// fill the temporary storage with current option list
				j++;
			}
		}
		this->count++;														// increse the count
		delete[] this->option_list;											// Releases dynamic storage in use by the options list
		this->option_list = temp_optionlist;								// assign the temporary storage to the current option list
		cout << "Option inserted successfully!" << endl;					
	}
	else {
		if (this->count == 0) {
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1, 1]" << endl;
		}
		else
			cout << "Invalid choice " << index << " for function insert. It must be in the range [1," << this->count << "]" << endl;
	}
}

/**
* Adds supplied option to the end of the option list.
* @param pOption
*/
void Menu::push_back(const char* pOption) {
	if (this->count == this->capacity) {									// compare the count and capacity
		double_capacity();													// double the capacity
		Text* temp_optionlist = new Text[this->capacity];					// allocate new temporary storage
		for (int i = 0; i < this->count; i++) {
			temp_optionlist[i] = this->option_list[i];						// fill the temporary storage with current option list
		}
		delete[] this->option_list;											// Releases dynamic storage
		this->option_list = temp_optionlist;								// assign the temporary storage to the current option list	
		this->option_list[this->count] = Text(pOption);						// add the pOption at the end of the option list
		this->count++;														// increment the count
	}
	else {																	// count != capacity
		option_list[this->count] = Text(pOption);							// add the pOption at the end of the option list
		this->count++;														// increment the count
	}
}

/**
* Adds supplied option to the end of the option list
* @param option
*/
void Menu::push_back(const Text& option) {
	if (this->count == this->capacity) {									// compare the count and capacity
		double_capacity();													// double the capacity
		Text* temp_optionlist = new Text[this->capacity];					// allocate new temporary storage
		for (int i = 0; i < this->count; i++) {
			temp_optionlist[i] = this->option_list[i];						// fill the temporary storage with current option list
		}
		delete[] this->option_list;											// Releases dynamic storage
		this->option_list = temp_optionlist;								// assign the temporary storage to the current option list	
		this->option_list[this->count] = option;							// add the option at the end of the option list
		this->count++;														// increment the count
	}
	else {																	// count != capacity
		this->option_list[this->count] = option;							// add the option at the end of the option list
		this->count++;														// increment the count
	}
}

/**
* Removes an option from the lists given index; shifts all options to the right of index left by one position.
* @param index
*/
void Menu::remove(int index) {
	if (this->option_list->isEmpty()){
		cout << "Invalid input " << index << " for function remove. The option list is empty" << endl;
	}
	else {
		if ((0 < index) && (index <= this->count)) {								// check that the index is in the range orr out of the range
			Text* temp_optionlist = new Text[this->capacity];					// allocate new temporary storage
			int j = 0;
			for (int i = 0; i < this->count; i++) {
				if (i != index - 1) {
					temp_optionlist[j] = this->option_list[i];					// fill the temporary storage with current option list
					j++;
				}
			}
			this->count--;														// decrease the current count
			delete[] this->option_list;											// Releases dynamic storage
			this->option_list = temp_optionlist;								// assign the temporary storage to the current option list
		}
		else {
			cout << "Invalid choice " << index << " for function remove. It must be in the range [1," << this->count << "]" << endl;

		}
	}
}

/**
* Returns the number of options in the option list.
* @return count
*/
int Menu::size() const {
	return this->count;														// return current count
}

/**
* Returns the current capacity if the options list
* @return capacity
*/
int Menu::getCapacity() const {
	return this->capacity;													// return current capacity
}

/**
* Removes the last option in the list
*/
void Menu::pop_back() {
	if (this->option_list->isEmpty()) {
		cout << "Can not pop back because the option list is empty" << endl;
	}
	else {
		this->count--;															// decrease the count
		this->option_list[count] = Text("");
	}
}

/**
* Return the k'th option
* @param k
* @return k'th option
*/
Text Menu::get(int k) {
	if (k <= 0 || k > count)												// check for subscript out-of-range error
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
Text Menu::toString() const {
	Text t = Text("");
	t.append("\n");
	std::string str;
	if (this->top_message.length() != 0) {
		t.append(this->top_message.getCstring());
		t.append("\n");
	}
	for (int i = 0; i < this->count; i++) {
		t.append("\t");
		std::string s;
		s = to_string(i + 1);
		const char* pcstr = s.c_str();
		t.append(pcstr);
		t.append(": ");
		t.append(this->option_list[i].getCstring());
		t.append("\n");
	}
	if (this->bottom_message.length() != 0) {
		t.append(this->bottom_message.getCstring());
		t.append("\n");
	}
	t.append("??");
	return t;
}

/**
* Displays this menu and then readsand returns a valid option number
* @return int
*/
int Menu::read_option_number() {
	while (true) {
		cout << *this;
		int enteredNum;
		cin >> enteredNum;
		if (this->isEmpty()) {
			return enteredNum;
		}
		else {
			if ((enteredNum > 0) && (enteredNum <= this->count)) {
				return enteredNum;
			}
			else {
				cout << "Invalid choice " << enteredNum << ". It must be in the range [1," << this->count << "]" << endl;
			}
		}
	}
}

/**
* Sets top message to m
* @param m
*/
void Menu::set_top_message(const Text& m) {
	this->top_message = m;
}

/**
* Sets bottom message to m
* @param m
*/
void Menu::set_bottom_message(const Text& m) {
	this->bottom_message = m;
}

/**
* Sets top message to empty text
*/
void Menu::clear_top_message() {
	this->top_message = Text("");
}

/**
* Sets bottom message to empty text
*/
void Menu::clear_bottom_message() {
	this->bottom_message = Text("");
}

/**
* Determines whether this menu's option list is empty
* @return true or false
*/
bool Menu::isEmpty() const {
	if (this->count == 0) {
		return true;
	}
	else {
		return false;
	}
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

/**
* Doubles the current capacity of the options list
*/
void Menu::double_capacity() {
	this->capacity = this->capacity * 2;
}