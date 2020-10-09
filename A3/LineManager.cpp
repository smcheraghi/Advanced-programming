/**
* Acting as an intermediary between the user, database of text line (MiniDB.h) and menu driven service (Menu.h)
* Seyed Mohammad Cheraghi
*/

#include "LineManager.h"
#include <fstream>
#include <vector>

/**
* Constructor of LineManager
*/
LineManager::LineManager() {
	this->upper_span = 2;
	this->lower_span = 2;
	this->quite = false;
	this->generateMenu();
	//this->generateMenu_1();
	//this->generateMenu_2();
	this->haveChanged = false;
}

/**
* Generate the partial_menu and full_menu
*/
void LineManager::generateMenu(){
	std::vector<std::string> options {
		"Append input from the keyboard",
		"Insert input from the keyboard",
		"Append input from text file",
		"Insert input from text file",
		"Print the current line",
		"Print a span of lines around the current position",
		"Set the length of upper or lower line spans",
		"Print all",
		"Move the current line",
		"Delete the current line",
		"Write mini-database to file ",
		"Quit"
	};
	// populate the partial menu
	this->partial_Menu.set_top_message("Choose one of the following options :");
	for (int i = 0; i < 4; ++i) {
		this->partial_Menu.push_back(options[i]);
	}
	this->partial_Menu.push_back("Quit");
	this->partial_Menu.set_bottom_message("Enter an option number");

	// populate the full menu
	this->full_Menu.set_top_message("Choose one of the following options :");
	for (const auto& opt : options){
		this->full_Menu.push_back(opt);
	}
	this->full_Menu.set_bottom_message("Enter an option number");
}
//void LineManager::generateMenu_1() {
//	this->partial_Menu.set_top_message("Choose one of the following options :");
//	this->partial_Menu.push_back("Append input from the keyboard");
//	this->partial_Menu.push_back("Insert input from the keyboard");
//	this->partial_Menu.push_back("Append input from text file");
//	this->partial_Menu.push_back("Insert input from text file");
//	this->partial_Menu.push_back("Quit");
//	this->partial_Menu.set_bottom_message("Enter an option number");
//}
//
//void LineManager::generateMenu_2() {
//	this->full_Menu = this->partial_Menu;
//	this->full_Menu.pop_back();
//	this->full_Menu.push_back("Print the current line");
//	this->full_Menu.push_back("Print a span of lines around the current position");
//	this->full_Menu.push_back("Set the length of upper or lower line spans");
//	this->full_Menu.push_back("Print all");
//	this->full_Menu.push_back("Move the current line");
//	this->full_Menu.push_back("Delete the current line");
//	this->full_Menu.push_back("Write mini - database to file");
//	this->full_Menu.push_back("Quit");
//}

/**
* Repeatedly prompt for and read a text from the keyboard and append it at the end of the database
*/
void LineManager::appendFromKey() {
	string inputStr{ "" };
	cin.clear();
	cout << "To end input, enter a single dot and press enter" << endl;
	while (true) {
		getline(cin, inputStr);																		// Read lines from input
		if (inputStr == ".") {
			break;
		}
		this->items.append(inputStr);																// Append to the database
		this->haveChanged = true;																	// Database was changed
	}
}

/**
* Repeatedly prompt for and read a text from the keyboard and insert it at cp, . is end of input entry
*/
void LineManager::insertFromKey() {
	string inputStr{ "" };
	cin.clear();
	cout << "To end input, enter a single dot and press enter" << endl;
	while (true) {
		getline(cin, inputStr);																		// Read from input
		if (inputStr == ".") {
			break;
		}
		this->items.insert(inputStr);																// Insert to the database
		this->haveChanged = true;																	// Database was changed
	}
}

/**
* Repeatedly prompt for and read a text from the keyboard and insert it at cp, . is end of input entry
*/
void LineManager::insertFromKey_2() {
	vector<string> vec;
	string inputStr{ "" };
	cin.clear();
	cout << "To end input, enter a single dot and press enter" << endl;
	while (true) {
		getline(cin, inputStr);																		// Read from input
		if (inputStr == ".") {
			break;
		}
		vec.push_back(inputStr);																	
	}
	if (!vec.empty()) {
		for (int i = vec.size() - 1; i >= 0; --i) {
			this->items.insert(vec[i]);
			this->haveChanged = true;
		}
	try {
		size_t newCurrentLine = this->items.getCurrentIndex() + vec.size() - 1;						// Calculate the new current line
		this->items.moveTolndex(newCurrentLine);													// Change the current line
	}
	catch (std::logic_error) {
		if (this->items.isEmpty()) {
			cout << "DB store is empty !!! " << endl;
		}
		else {
			cout << "Index is out of range !!!" << endl;
		}
		
	}
	}

}

/**
* Check that the file is extsted or not
* @param filename
* return bool
*/
bool LineManager::fileExist(string filename) {
	ifstream fin;
	fin.open(filename.c_str());																		// try to open the file
	if (fin) {
		fin.clear(); // clear to good state and try again
		fin.close();
		return true;																				// If file is there, return true
	}
	cout << "Could not open " << filename << endl;	
	fin.clear(); // clear to good state and try again
	fin.close();
	return false;
}

/**
* This function take a list and write it to the file
* @param lst: list of items in database
* @return bool
*/
//int LineManager::writeToFile(vector<string> vec)
bool LineManager::writeToFile(list<string> lst)
{
	ofstream fout;
	string filename{};
	cin.clear();
	cout << "Enter input filename: " << endl;
	while (filename.empty()) {
		getline(cin, filename);																			// Read the path of file 
		filename = this->is_white_space(filename);
	}
	filename = this->fullStrip_removeSpace(filename);												// Remove the space in both side
	if (this->fileExist(filename)) {
		fout.open(filename.c_str());
		for (auto it = lst.begin(); it != lst.end(); ++it) {										// Read line by line from database and write to file
			fout << *it;
			fout << "\n";
		}
		fout.close();
		return true;
	}
	return false;
}

/**
* Read from file line by line, push back to the vector and return the vector
* @return vector of string
*/
vector<string> LineManager::readFromFile() const
{
	ifstream fin;
	vector<string> vec;																				// local vector
	string line;																					// stores a line
	string filename{};
	cin.clear();
	while (filename.empty()) {
		getline(cin, filename);																			// read a file name
		filename = this->is_white_space(filename);
	}
	filename = this->fullStrip_removeSpace(filename);
	fin.open(filename.c_str());																		// try to open the file
	if (fin) {																						// if fin is good
		while (getline(fin, line)) {																// read a line
			vec.push_back(line);																	// append the line to our vector
		}
	}
	else {
		cout << "Could not open " << filename << endl;
	}
	fin.clear();																					// clear to good state and try again
	fin.close();
																									// now we have a working input stream, ready to read from.
	return vec;

}

/**
* Set the lower span
* @param x
*/
void LineManager::setLower_span(int x) {
	this->lower_span = x;
}

/**
* Set the upper span
* @param x
*/
void LineManager::setUpper_span(int x) {
	this->upper_span = x;
}

/**
* Change lower and upper span based on the input integer. If n<0 change upper span, 
* if n>0 change lower span and if n=0 change both to zero.
* @param x
*/
void LineManager::changeUpperLowerSpan(int x) {
	try {
		int currentLine = this->items.getCurrentIndex() + 1;											// Because getcurrentinde is zero base, I add to one
		if (x < 0) {
			if (abs(x) < currentLine) {
				this->setUpper_span(abs(x));
			}
			else {
				cout << "That's a large span of lines. Max is " << currentLine - 1 << endl;
			}

		}
		else if (x > 0) {
			int maximum_upper = this->items.size() - currentLine;
			if (x <= maximum_upper) {
				this->setLower_span(x);
			}
			else {
				cout << "That's a large span of lines. Max is " << maximum_upper <<endl;
			}

		}
		else if (x==0){
			this->setUpper_span(0);
			this->setLower_span(0);
		}
	}
	catch (std::logic_error) {
		cout << "DB store is empty !!!" << endl;
	}
}

/**
* Print upper_span line above the current line, followed by the line at the current line, followed by lower_span lines below the current line
* last line will be the new current line
* @param vec: vector of items
*/
void LineManager::printSpanLines(vector<string> vec) {
		bool EOFile = false;
		bool BOFile = false;
		int lowerBound;
		int upperBound;
	try {
		int currentLine = this->items.getCurrentIndex() + 1;								// Because getCurrentIndex is zero based, add to 1
		lowerBound = currentLine - this->upper_span;
		upperBound = currentLine + this->lower_span;
		if (lowerBound < 1) {
			lowerBound = 1;
			BOFile = true;
		}
		if (upperBound > this->items.size()) {
			upperBound = this->items.size();
			EOFile = true;
		}
		if (BOFile) {
			cout << "**: BOF" << endl;
		}
		for (size_t i = lowerBound; i <= upperBound; i++) {
			cout << i << ": " << vec[i - 1] << endl;
		}
		if (EOFile) {
			cout << "**: EOF" << endl;
		}
		this->items.moveTolndex(upperBound - 1);
	}
	catch (std::logic_error) {
		if (this->items.isEmpty()) {
			cout << "DB store is empty !!!" << endl;
		}
		else {
			cout << "The index is Out of range !!!" << endl;
		}
		
	}
}

/**
* Read integer from input
* @return int
*/
int LineManager::readInt() {
	int y;
	string str;
	while (str.empty()) {
		getline(cin, str);
		str = this->is_white_space(str);
	}
	str = this->fullStrip_removeSpace(str);
	try {
		y = stoi(str);
		return y; // enteredNum;
	}
	catch (invalid_argument& e) {
		cout << "Invalid choice " << str << ". It must be an integer. ";
	}

}

/**
* Move the current line to new index
* @param x: new position
*/
void LineManager::moveCurrentLine(int x) {
	try {
		this->items.moveTolndex(x - 1);
	}
	catch (std::logic_error){
		if (this->items.isEmpty()) {
			cout << "Error: Database is empty" << endl;
		}
		else {
			cout << "Invalid choice " << x << ". It must be in the range of [1, " << (this->items.getCurrentIndex() + 1) << "] " << endl;
		}
		
	}
}


/**
* Remove space from the left side of the string
* @param str: input string
* @return string
*/
string LineManager::lStrip_removeSpace(string str) const{
	for (int i = 0; i < str.size(); i++) {
		if (!isspace(str[i])) {
			return str.substr(i);
		}
	}
}

/**
* Check that the input string is only white space or not
* @param str: input string
* @return string
*/
string LineManager::is_white_space(string str) const{
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
* Remove space from the right side of the string
* @param str: input string
* @return string
*/
string LineManager::rStrip_removeSpace(string str) const{
	int myCounter = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (!isspace(str[i])) {
			return str.substr(0, str.size() - myCounter);
		}
		++myCounter;
	}
}

/**
* Remove space from the both side of the string
* @param str: input string
* @return string
*/
string LineManager::fullStrip_removeSpace(string str) const{
	str = lStrip_removeSpace(str);																	// Remove left side space
	str = rStrip_removeSpace(str);																	// Remove right side space			
	return str;
}

/**
* Interpret the option number inserted by user
* @param input: option number
* @return bool
*/
bool LineManager::interpretCommandLine(int input) {
	vector<string> vec;
	switch (input) {
	case 1:																							// "Append input from the keyboard"
		this->appendFromKey();
		break;       
	case 2:																							// "Insert input from the keyboard"		
		//if (this->items.isEmpty()) {
		//	this->appendFromKey();
		//}
		//else{
		this->insertFromKey_2();
//		}
		break;
	case 3:																							// "Append input from text file"
		cout << "Enter input filename: " << endl;
		vec = this->readFromFile();
		for (int i = 0; i < vec.size(); i++) {
			this->items.append(vec[i]);
			this->haveChanged = true;
		}
		break;
	case 4:																							// "Insert input from text file"
		cout << "Enter input filename: " << endl;
		vec = this->readFromFile();
		if (vec.size() > 0) {
			for (int i = vec.size() - 1; i >= 0; --i) {
				this->items.insert(vec[i]);
				this->haveChanged = true;
			}
			size_t newCurrentLine;
			try {
				newCurrentLine = this->items.getCurrentIndex() + vec.size() - 1;
				this->items.moveTolndex(newCurrentLine);
			}
			catch (std::logic_error) {
				if (this->items.isEmpty()) {
					cout << "DB store is empty !!!" << endl;
				}
				else {
					cout << "The index is out of range !!!" << endl;
				}
				
			}

		}
		break;
	case 5:																							// "Print the current line"
		try {
			this->items.printCurrentpos();
		}
		catch (std::logic_error) {
			cout << "DB store is empty !!!" << endl;
		}
		break;
	case 6:																							// "Print a span of lines around the current position"
		this->printSpanLines(this->items.MiniDBToVec());
		break;
	case 7:																							// "Set the length of upper or lower line spans"
		cout << "What's the length of the span?" << endl;
		this->changeUpperLowerSpan(this->readInt());
		break;
	case 8:																							// "Print all"
//		this->items.print();
		cout << this->items;
		try {
			this->items.moveToLast();
		}
		catch (std::logic_error) {
			cout << "DB store is empty !!!" << endl;
		}
		break;
	case 9:																							// "Move the current line"
		cout << "Which line to move to?" << endl;
		this->moveCurrentLine(this->readInt());
		break;
	case 10:																						// "Delete the current line"
		try {
			this->items.remove();
			cout << "Removing the current line ..." << endl;
			this->haveChanged = true;
		}
		catch (std::logic_error) {
			cout << "Can not remove, DB store is empty !!!" << endl;
		}
		break;
	case 11:																						// "Write mini-database to file "
		if (this->writeToFile(this->items.getdb_store()))
			this->haveChanged = false;
		break;
	case 12:																						// "Quit"
		if (this->haveChanged) {
			cout << "Do you want to save changes to a file?" << endl;
			string ans{ "" };
			cin.clear();
			while (ans.empty()) {
				getline(cin, ans);
				ans = this->is_white_space(ans);
			}
			ans = this->fullStrip_removeSpace(ans);
			if ((ans[0] == 'y') || ans[0] == 'Y') {
				if (this->writeToFile(this->items.getdb_store()))
					this->haveChanged = false;
				break;
			}

		}
		cout << "Goodbye" << endl;
		return true;
	}
	return false;
}

/**
* This function launches the program, let the user to select an option to execute. 
*/
void LineManager::run() {
	int input = 0;
	while (!this->quite) {
		if (this->items.isEmpty()) {
			input = this->partial_Menu.read_option_number();							
			if (input == 5) {
				this->quite = true;
			}
			else {
				this->quite = this->interpretCommandLine(input);
			}
		}
		else {
			input = this->full_Menu.read_option_number();
			this->quite = this->interpretCommandLine(input);
		}
		
	}
}
