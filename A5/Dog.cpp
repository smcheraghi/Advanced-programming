/**
* This is the implementation of Dog.h
*/

#include<map>
#include "Dog.h"
#include<iostream>
#include <iomanip>      // std::setw

/**
* This function set the name
* @param string
*/
void Dog::setName(std::string n) {
	this->name = n;
}

/**
* This function set the breed
* @param string
*/
void Dog::setBreed(std::string b) {
	this->breed = b;
}

/**
* This function set the age
* @param string
*/
void Dog::setAge(std::string a) {
	this->age = a;
}

/**
* This function set the gender
* @param string
*/
void Dog::setGender(std::string g) {
	this->gender = g;
}

/**
* This function get the name
* @return string
*/
std::string Dog::getName() const {
	return this->name;
}

/**
* This function get the breed
* @return string
*/
std::string Dog::getBreed() const {
	return this->breed;
}

/**
* This function get the age
* @return string
*/
std::string Dog::getAge() const {
	return this->age;
}

/**
* This function get the gender
* @return string
*/
std::string Dog::getGender() const {
	return this->gender;
}

/**
* Check that the input string is only white space or not
* @param string: input string
* @return bool
*/
bool isWhiteSpaceLine(std::string str) {
	bool stringIsGood = false;
	if (str.empty()) {
		return true;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ' && str[i] != '\t') {
				return false;																// It means that the string is not only white space
			}
		}
	}
	return true;
}

/**
* Read a number for betting
* @return bool
*/
bool validInt(std::string str) {
	if (isWhiteSpaceLine(str)) {															// Check that the strin is only white space
		return false;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			return false;																	// The string is not number
		}
	}
	return true;
}



/**
* This function Removes any leading and trailing whitespace in a supplied string.
@param string: The supplied string.
@return A copy of the supplied string, with any leading and trailing whitespace removed.
*/
std::string trim(const std::string& str) {
	bool isWhiteSpace = true;
	std::string tempStr = str;
	for (int i = 0; i < tempStr.size(); i++) {
		if (tempStr[i] != ' ' && tempStr[i] != '\t') {
			isWhiteSpace = false;															// String is not white space	
		}
	}

	if (isWhiteSpace == false) {
		for (int i = 0; i < tempStr.size(); i++) {
			if (!isspace(tempStr[i])) {
				tempStr = tempStr.substr(i);												// Cut the string from first character util end
				break;
			}
		}
		int myCounter = 0;
		for (int i = tempStr.size() - 1; i >= 0; --i) {
			if (!isspace(tempStr[i])) {
				return tempStr.substr(0, tempStr.size() - myCounter);						// Cut the string from first character from end to until first
			}
			++myCounter;
		}
		return tempStr;																		// The string whith out space from both side 
	}
	else {
		return "";
	}
}

/**
* This function check the validity of gender, male or female
* @param string
* @return bool
*/
bool validGender(std::string str) {
	std::string tempStr = str;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		tempStr[i] = tolower(c);															// Change each character to lower case
	}
	if (tempStr == "male" || tempStr == "female") {											// Check that the string to be male or female only		
		return true;
	}
	else {
		return false;
	}
}

/**
* This function check the validity of name or breed
* @param string
* @return bool
*/
bool validString(std::string str) {
	if (str.empty() || isWhiteSpaceLine(str)) {
		return false;																		// If the string is empty or whitespace
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i] != '-') {
			if (!std::isalpha(str[i])) {
				return false;																// Return false if is not alpha or -									
			}
		}
	}
	return true;
}

/**
* This function check the validity of input
* @param Dog
* @return bool
*/
bool isValidDog(Dog dog) {
	return ( validString(dog.getName()) && validString(dog.getBreed()) && validInt(dog.getAge()) && validGender(dog.getGender()) );

}

/**
* operator overloading <<
* @param ostream&: sout
* @param const Dog&: dog
* @return ostream&
*/
std::ostream& operator<<(std::ostream& sout, const Dog& dog) {
	sout << dog.name << ", " << dog.breed << ", " << dog.age << ", " << dog.gender;
	return sout;
}

/**
* operator overloading >>
* @param istream&: sin
* @param const Dog&: dog
* @return istream&
*/
std::istream& operator>>(std::istream& sin, Dog& dog) {
	std::string name, breed, age, gender;
	bool isOk = false;
	
	if (std::getline(sin, name, ',')) {
		if (std::getline(sin, breed, ',')) {
			if (std::getline(sin, age, ',')) {
				if (std::getline(sin, gender)) {
					isOk = true;
				}
			}
		}
	}

	if (!isOk && !sin.eof()) {
		throw std::runtime_error("Invalid input line");
	}
	
	name   = trim(name);
	breed  = trim(breed);
	age    = trim(age);
	gender = trim(gender);

	Dog tempDog;
	tempDog.setName(name);
	tempDog.setBreed(breed);
	tempDog.setAge(age);
	tempDog.setGender(gender);

	if (name.empty() && breed.empty() && age.empty() && gender.empty()) {
		return sin;
	}

	if (isValidDog(tempDog)) {																		// Check the validity of dog
		dog.name = name;
		dog.breed = breed;
		dog.age = age;
		dog.gender = gender;
		return sin;
	}
	else {
		throw std::runtime_error("Invalid input line ");											// If not invalid
	}
}

/**
* operator overloading <<
* @param ostream&: sout
* @param const DogMapDefault&: dogmap
* @return ostream&
*/
std::ostream& operator<<(std::ostream& sout, const DogMapDefault& dogmap) {
	for (const auto & dog : dogmap) {												// C++14
	 std::cout << std::setw(25) << dog.first << " --> " << dog.second << std::endl;
	 }
	//for (const auto& [ breed , dog ] : dogmap) {									// C++17
	//	std::cout << std::setw(25) << breed << " --> " << dog << std::endl;
	//}
	return sout;
}

/**
* operator overloading <<
* @param ostream&: sout
* @param const DogMapGreater&: dogmap
* @return ostream&
*/
std::ostream& operator<<(std::ostream& sout, const DogMapGreater& dogmap) {
	for (const auto& dog : dogmap) {												// C++14
		std::cout << std::setw(25) << dog.first << " --> " << dog.second << std::endl;
	}
	//for (const auto& [ breed , dog ] : dogmap) {									// C++17
	//	std::cout << std::setw(25) << breed << " --> " << dog << std::endl;
	//}
	return sout;
}


//template<typename Comp>
//std::ostream& operator<<(std::ostream& sout, const std::multimap<std::string, Dog, Comp>& dogmap)
//{
//	for (const auto& dog : dogmap) {
//		sout << std::setw(25) << dog.first << " :: " << dog.second << std::endl;
//	}
//	return sout;
//}