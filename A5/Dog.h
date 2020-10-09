#ifndef DOG_H
#define DOG_H

#include<string>
#include<map>

class Dog {
private:
	std::string name;																		// Name of dog
	std::string breed;																		// Breed of dog
	std::string age;																		// Age of dog
	std::string gender;																		// Gender of dog
		
public:
	Dog(std::string n, std::string b, std::string a, std::string g) : name(n), breed(b), age(a), gender(g) {}		// Constructor
	Dog() = default;																		// Default ctor
	Dog(const Dog&) = default;																// Default copy ctor	
	Dog& operator=(const Dog&) = default;													// Default copy assignment
	~Dog() = default;																		// Default dctor	
	Dog(Dog&&) = default;																	// Default move ctor
	Dog& operator=(Dog&&) = default;														// Default copy move ctor
	void setName(std::string n);															// Set the name
	void setBreed(std::string b);															// Set the breed	
	void setAge(std::string a);																// Set the age
	void setGender(std::string g);															// Set the gender		
	std::string getName() const;															// Get the name
	std::string getBreed() const;															// Get the breed
	std::string getAge() const;																// Get the age	
	std::string getGender() const;															// Get the gender
	friend std::ostream& operator<<(std::ostream&, const Dog&);								// Operator overloading <<	
	friend std::istream& operator>>(std::istream&, Dog&);									// Operator overloading >>
};
using DogMapDefault = std::multimap<std::string, Dog, std::less<std::string>>;				// Define type DogMapDefault
using DogMapGreater = std::multimap<std::string, Dog, std::greater<std::string>>;			// Define type DogMapGreater
std::ostream& operator<<(std::ostream&, const DogMapDefault&);								// Operator overloading << for DogMapDefault
std::ostream& operator<<(std::ostream&, const DogMapGreater&);								// Operator overloading << for DogMapGreater
std::string trim(const std::string& str);													// Remove the space from both side
bool isValidDog(Dog dog);																	// Check the validity of input dog
bool isWhiteSpaceLine(std::string str);														// Check the string to be white space or not 
bool validInt(std::string str);																// Check the validity of string to be a number
bool validGender(std::string str);															// Check the validity of gender
bool validString(std::string str);															// Check the validy of name or breed

//template<typename Comp>
//std::ostream& operator<<(std::ostream& sout, const std::multimap<std::string, Dog, Comp>& dogmap);

#endif 