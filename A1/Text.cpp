/**
* This class represents the text of the messages and options in a menu.
*
* @author  Seyed Mohammad Cheraghi
* @version 1.0
*/

#include<iostream>
#include "Text.h"

using namespace std;

/**
* Releases dynamic storage in use by this object
*/
Text::~Text() {
	this->textLength = 0;										
	delete[] this->pStore;										// release dynamic storage
	this->pStore = nullptr;										// assign to null pointer
}

/**
* Default constructor; equivalent to Text ("")
*/
Text::Text() {
	this->textLength = strlen("");								// assign the length of empty text to textLength
	this->pStore = new char[this->textLength + 1];				// allocate new storage
	strcpy(this->pStore, "");									// copy the empty text to pStore
}

/**
* Copy Constructor; deep-copies txt into the object being constructed
* @param txt 
*/
Text::Text(const Text& txt) {
	this->textLength = txt.textLength;							// assign the length of parameter to textLength
	this->pStore = new char[this->textLength + 1];				// allocate new storage
	strcpy(this->pStore, txt.pStore);							// copy the content of parameter pointer to pStore
}

/**
* Conversion Constructor (C-string to Text)
* @param pCstr 
*/
Text::Text(const char* pCstr) {
	this->textLength = strlen(pCstr);							// assign the length of parameter to textLength
	this->pStore = new char[this->textLength + 1];				// allocate new storage
	strcpy(this->pStore, pCstr);								// copy the content of parameter to pStore
}

/**
* Assigns a C-string to this object, replacing its current contents
* @param pCstr
*/
void Text::assign(const char* pCstr) {
	delete[] this->pStore;										// release dynamic storage
	this->textLength = strlen(pCstr);							// assign the length of parameter to current textLength
	this->pStore = new char[this->textLength + 1];				// allocate new storage
	strcpy(this->pStore, pCstr);								// copy the content of parameter to current pStore
}

/**
* Assigns a Text object to this object, replacing its current contents
* @param txt
*/
void Text::assign(const Text& txt) {
	delete[] this->pStore;										// release dynamic storage
	this->textLength = txt.textLength;							// assign the length of parameter to current textLength
	this->pStore = new char[this->textLength + 1];				// allocate new storage
	strcpy(this->pStore, txt.pStore);							// copy content of the parameter to current pStore
}

/**
* Assignment operator= overload. Assigns the right hand side operand to this object, replacing its current contents
* @param txt
* @return this object
*/
Text& Text::operator=(const Text& txt) {
	if (this != &txt) {											// check that the parameter and current object is same or not
		this->textLength = txt.textLength;						// assign the length of parameter to current textLength
		delete[] this->pStore;									// release dynamic storage
		this->pStore = new char[this->textLength + 1];			// allocate new storage
		strcpy(this->pStore, txt.pStore);						// copy content of the parameter to current pStore
	}
	return *this;
}

/**
* Appends a C-string to this object, extending its contents
* @param pCstr
*/
void Text::append(const char* pCstr) {
	int newTextLenght = this->textLength + strlen(pCstr);		// assign sum of current textLength and parameter length to a variable newTextLenght
	char* tempText = new char[newTextLenght + 1];				// allocate temporary new storage
	strcpy(tempText, this->pStore);								// copy the content of current storage to the new temporary storage
	strcat(tempText, pCstr);									// append a string to a character array
//	for (int i = 0; i <= strlen(pCstr); i++) {					
//		tempText[this->textLength + i] = pCstr[i];				// appent the elements of pCstr to the new temporary storage 
//	}
	delete[] this->pStore;										// release current dynamic storage
	this->textLength = newTextLenght;							// assign the new variable newTextLenght to the current textLength
	this->pStore = tempText;									// update pStore to new temporary sorage
}

/**
* Appends txt's text to this object, extending its contents
* @param txt
*/
void Text::append(const Text& txt) {
	int newTextLenght = this->textLength + txt.textLength;		// assign sum of current textLength and parameter textLength to a variable newTextLenght
	char* tempText = new char[newTextLenght + 1];				// allocate temporary new storage
	strcpy(tempText, this->pStore);								// copy the content of current storage to the new temporary storage
	strcat(tempText, txt.pStore);								// append a string to a character array
//	for (int i = 0; i <= txt.textLength; i++) {
//		tempText[this->textLength + i] = txt.pStore[i];			// appent the elements of pCstr to the new temporary storage 
//	}
	delete[] this->pStore;										// release current dynamic storage
	this->textLength = newTextLenght;							// assign the new variable newTextLenght to the current textLength
	this->pStore = tempText;									// update pStore to new temporary sorage
}

/**
* Erases the contents of the C-string in this object, which becomes an empty C-string
*/
void Text::clear() {
	textLength = strlen("");									// assign the length of empty string to the current textLength 
	delete[] this->pStore;										// release current dynamic storage
	this->pStore = new char[this->textLength + 1];				// allocate a new storage
	strcpy(this->pStore, "");									// copy the empty text to current storage
}

/**
* Returns the length of this object's text
* @return textLength which is the length of this object's text
*/
int Text::length() const {
	return this->textLength;									// length of this object's text
}

/**
* Determines whether this object represents a C-string of length zero
* @return True or False
*/
bool Text::isEmpty() const {
	if (this->textLength == 0) {
		return true;
	}
	else {
		return false;
	}
}

/**
* returns the text stored in this object
* @return pStore as a const pointer
*/
const char* Text::getCstring() const {
	return this->pStore;										// returns the text stored in this object
}

/**
* Assignment operator << overload. cout the content of the object
* @param sout
* @param txt
* @return sout
*/
std::ostream& operator<<(std::ostream& sout, const Text& txt)
{
	sout << txt.getCstring();
	return sout;
}