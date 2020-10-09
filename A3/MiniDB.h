/**
* This class model a sequence container that provide the operations of a basic and efficient database.
* Seyed Mohammad Cheraghi
*/
#ifndef MINIDB_H
#define MINIDB_H

#include <list> 
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MiniDB {
private:
	list<T> db_store;
	typename list<T>::iterator current_position = db_store.end();

public:
	MiniDB() = default;													// Constructor
	MiniDB(const MiniDB & L) = default;									// Copy constructor
	MiniDB& operator =(const MiniDB & L) = default;						// Assignment operator
	size_t size() const;												// Returns the number of items in the database
	void insert(const T& item);											// Inserts a given item at where cp points at, and then it resets cp to point at the new item.
	void append(const T& item);											// Appends a given item at the end of the list and then resets cp to point at the new item.
	void prev();														// If cp is not already representing the item in the first position, it moves cp one step backward; otherwise, it throws a std : : logic_error, leaving the invoking object unchanged.
	void next();														// If cp is not already representing the item in the last position, it moves cp one step forward; otherwise, it throws a std : : logic_error, leaving the invoking object unchanged.
	T remove();															// Removes and returns the item cp points at.It resets cp to point at the itern after the one removed, if there is one; otherwise, it resets cp to point at the item before the one removed, if there is one; otherwise, the the member list line_db has become empty, and cp will be reset to db_store.end().
	void moveToFirst();													// Resets cp to represent the position of the first item in the database.
	void moveToLast();													// Resets cp to represent the position of the last item in the database.
	size_t getCurrentIndex() const;										// Returns the index of the item that cp points at.Uses 0 - based indexing.
	void moveTolndex(size_t index);										// Sets cp to represent the item at the specified index.Uses 0 based indexing.
	const T& getValue() const;											// Returns the value at the current position
	void print() const;													// Print the items in db_store
	bool isEmpty() const;												// Check that the db_store is empty
	string toStream() const;											// Print the items in db_store
	void printCurrentpos() const;										// Print the current position
	list<T> getdb_store();												// Return the db_store
	vector<T> MiniDBToVec();											// Convert MiniDB to vector
};

/*
	Return the list of db_store
*/
template <typename T>
list<T> MiniDB<T>::getdb_store() {
	return this->db_store;
}

/*
	Returns the number of items in the database
*/
template <typename T>
size_t MiniDB<T>::size() const {
	return this->db_store.size();
}

/*
* Inserts a given item at where cp points at, and then it resets cp to point at the new item.
* @param item
*/
template <typename T>
void MiniDB<T>::insert(const T& item) {
	if (size() == 0) {															// when db_store is empty, there is no difference between insert and push_back
		this->db_store.push_back(item);
		this->current_position = this->db_store.begin();
		return;
	}
	this->db_store.insert(this->current_position, item);						// Insert the item to the current position
	--current_position;															// decrement the current because it points to the item after the new item	
}

/*
* Appends a given item at the end of the listand then resets cp to point at the new item.
* @param item
*/
template <typename T>
void MiniDB<T>::append(const T& item) {
	this->db_store.push_back(item);
	this->current_position = this->db_store.end();								// Set the current position to the end of dbstore
	--this->current_position;													// decrement the current position, now it point to the new added item	
}

/*
* Print the items in db_store.
*/
template <typename T>
void MiniDB<T>::print() const{
	int counter{ 1 };
	for (auto it = db_store.begin(); it != db_store.end(); ++it) {
		std::cout << counter << ": " << *it << endl;
		++counter;
	}
}

/*
* If cp is not already representing the item in the first position, it moves cp one step backward; 
* otherwise, it throws a logic_error, leaving the invoking object unchanged.
*/
template <typename T>
void MiniDB<T>::prev() {
	if (this->isEmpty()) {														// Can not decrement the current position
		throw logic_error("Error: DB store is empty");
	}
	if (this->current_position == this->db_store.begin()) {						// Can not decrement the current position
		throw logic_error("Error: already representing the item in the first position");
	}
	--this->current_position;
}

/*
* If cp is not already representing the item in the last position, it moves cp one step forward; 
* otherwise, it throws a logic_error, leaving the invoking object unchanged.
*/
template <typename T>
void MiniDB<T>::next() {
	if (this->isEmpty()) {														// Can not increment the current position
		throw logic_error("Error: DB store is empty");
	}
	++this->current_position;
	if (this->current_position == this->db_store.end()) {						// Can not increment the current position
		throw logic_error("Error: already representing the item in the last position");
	}
}

/*
* Removes and returns the item cp points at. It resets cp to point at the item after the one removed, if there is one; 
* otherwise, it resets cp to point at the item before the one removed, if there is one; 
* otherwise, the the member list line_db has become empty, and cp will be reset to db_store.end().
* return an object type T
*/
template<typename T>
T MiniDB<T>::remove() {
	T temp;
	if (this->db_store.size()==0) {
		throw logic_error("Error: Can not remove, DB store is empty");
//		return NULL;										
	}
	else if (this->current_position != this->db_store.end()) {			
		typename list<T>::iterator it = this->current_position;
		temp = *this->current_position;
		++this->current_position;
		this->db_store.erase(it);															// Remove the current line
		if (this->current_position == this->db_store.end()) {								// Set the new current line
			if (this->db_store.size() != 0) {
				--this->current_position;
			}
			else
			{
				this->current_position = db_store.end();
			}
		}
	}
	return temp;
}

/*
* Resets cp to represent the position of the first item in the database.
*/
template<typename T>
void MiniDB<T>::moveToFirst() {
	if (this->isEmpty()) {
		throw logic_error("Error: Can not move to first, DB store is empty");
	}
	else {
		this->current_position = this->db_store.begin();						// Move to first			
	}
}


/*
* Resets cp to represent the position of the last item in the database.
*/
template<typename T>
void MiniDB<T>::moveToLast() {
	if (this->isEmpty()) {
		throw logic_error("Error: Can not move to Last, DB store is empty");
	}
	else
	{
		this->current_position = this->db_store.end();							// Current position points to the end of the dbstore
		--this->current_position;												// Now it point to the last item
	}
}

/*
* Returns the index of the item that cp points at. Uses 0 - based indexing.
* return index
*/
template<typename T>
size_t MiniDB<T>::getCurrentIndex() const{
//	cout << ">> Call getCurrentIndex func" << endl;											
	size_t index = -10;
	if (this->db_store.size() == 0) {
		throw logic_error("Error: DB store is empty");
		return index;
	}
	else
	{
		typename  std::list<T>::const_iterator first = db_store.begin();
		typename  std::list<T>::const_iterator second = current_position;
		index = distance(first, second);													// Calculate the distance from begin to current line
		/*index = 0;
		for (auto it = this->db_store.begin(); it != this->current_position; ++it) {
			++index;
		}*/
	}
	return index;
}

/*
* Sets cp to represent the item at the specified index. Uses 0 based indexing.
* @param index
*/
template<typename T>
void MiniDB<T>::moveTolndex(size_t index) {
	if (this->db_store.size() == 0) {
//		cout << "DB store is empty ..." << endl;									
		throw logic_error("Error: DB store is empty");
	}
	else if (index < this->db_store.size()) {
		this->current_position = this->db_store.begin();
		advance(this->current_position, index);											// Move the current line to index
		/*typename list<T>::iterator temp_it = this->db_store.begin();
		for (size_t i = 0; i < index; i++) {
			++temp_it;
		}
		this->current_position = temp_it;*/
	}
	else{
		throw logic_error("Error: Out of range index");
	}

}

/*
* Returns the value at the current position
* @return current_position
*/
template<typename T>
const T& MiniDB<T>::getValue() const{
	if (this->db_store.size() == 0) {
		throw logic_error("Error: DB store is empty");                 
		return NULL;
	}
	else {
		return *this->current_position;
	}
}

/*
* Check that the db_store is empty
* @return true or false
*/
template <typename T>
bool MiniDB<T>::isEmpty() const{
	return this->db_store.size() == 0;
}

/*
* Print current position
*/
template<typename T>
void MiniDB<T>::printCurrentpos() const{
	int currentPosition = this->getCurrentIndex() + 1;								// add to 1 because getcurrentIndex is zero based
	cout << currentPosition <<": "<< *this->current_position << endl;
}

/*
* Print the items in db_store
* @return out
*/
template<typename T>
string MiniDB<T>::toStream() const{
	int rowNum = 1;
	string out = "";
	for (auto it = db_store.begin(); it != db_store.end(); ++it) {
		out = out + to_string(rowNum) + ": " + *it + "\n";
		++rowNum;
	}
	return out;
}

/*
* Convert MiniDB to vector
* @return vec
*/
template<typename T>
vector<T> MiniDB<T>::MiniDBToVec() {
	vector<T> vec;
	for (auto it = db_store.begin(); it != db_store.end(); ++it) {
		vec.push_back(*it);
	}
	return vec;
}

/*
* Overloading the operator <<
*/
template<typename T>
ostream& operator<< (ostream& sout, MiniDB<T> m) {
	sout << m.toStream();
	return sout;
}


#endif 

