/**
* @Author: Seyed Mohammad Cheraghi
*/

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <sstream>      // std::stringstream
#include <map>
#include<string>
#include "Dog.h"
#include <algorithm>
#include <vector>
#include <functional>
#include <set>

using namespace std;

using DogMapDefault = multimap<string, Dog>;											// Key type is std::string, mapped type is Dog
// other interesting multimap types
// this one reverses the order of the elements in the multimap
using DogMapGreater = multimap<string, Dog, greater<string>>;							// this one reverses the order of the elements in the multimap
// and this one let you introduce your own callable type, say, MyCompare
//using DogMapCompare = multimap<string, Dog, MyCompare>;


template<typename MultiMapType>
void load_csvFile_Normal_Loop(MultiMapType& dog_map, string filename);					// Loading dogMap From an Input File by normal
void load_csvFile_For_Each(DogMapDefault& dog_map, string filename);					// Loading dogMap From an Input File by for_each
void load_csvFile_Transform(DogMapDefault& dog_map, string filename);					// Loading dogMap From an Input File by transform
//void load_csvFile_Normal_Loop_greater(DogMapGreater& dog_map, string filename);
DogMapDefault findBreedRange(DogMapDefault& source, const std::string& key_breed);      // Returns a DogMapDefault having the same key breed

bool is_alphabetic(char ch);															// Check the character is alpha or not
bool is_palindrome(string str);															// Check the string that same when read forward or backward	
void test_is_palindrome();																// Test the function is_palindrome
void test_second_max(std::vector<int> vec);												// Test the function second_max 

int testCountStringsFreeFun(const std::vector<std::string>& vec, int n);				// Test the functionality of CountStringsFreeFun
int testCountStringsFunctor(const std::vector<std::string>& vec, int n);				// Test the functionality of CountStringsFunctor
int testCountStringsLambda(const std::vector<std::string>& vec, int n);					// Test the functionality of CountStringsLambda

void multisetUsingMyComparator();														// Defines a multiset object using my comparator
void multisetUsingDefaultComparator();													// Defines a multiset object using multiset's default compare type parameter

void Task1_main(std::string csvFilePath);												// Main function for task 1
void Task2_main(std::string csvFilePath);												// Main function for task 2	
void Task3_main(std::string csvFilePath);												// Main function for task 3
void Task4_main(std::string csvFilePath);												// Main function for task 4	
void Task5_main(std::string csvFilePath);												// Main function for task 5
void Task6_main();																		// Main function for task 6
void Task7_main();																		// Main function for task 7
void Task8_main();																		// Main function for task 8
void Task9_main();																		// Main function for task 9		

/**
* The main function
* @return int
*/
int main() {
	std::string csvFilePath = "dogDB.csv";
	Task1_main(csvFilePath);
	Task2_main(csvFilePath);
	Task3_main(csvFilePath);
	Task4_main(csvFilePath);

	csvFilePath = "dogDB2.csv";
	Task5_main(csvFilePath);

	Task6_main();
//	Task7_main();
	Task8_main();
	Task9_main();

	cout << "\n=========================== << Test Driver Code >> ===========================\n\n";

	// Task 4:
	test_is_palindrome();
	cout << "\n";
	// Task 5:
	std::vector<int> v1{ 1 }; // one element
	test_second_max(v1);
	std::vector<int> v2{ 1, 1 }; // all elements equal
	test_second_max(v2);
	std::vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
	test_second_max(v3);
	cout << "\n";
	// problem 6:
	std::vector<std::string> vecstr
	{ "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
	"range", "[first", "last)", "for", "which", "pred", "is", "true."
	};
	cout << testCountStringsLambda(vecstr, 5) << endl;
	cout << testCountStringsFreeFun(vecstr, 5) << endl;
	cout << testCountStringsFunctor(vecstr, 5) << endl;
	cout << "\n";
	// problem 7:
	multisetUsingMyComparator();
	cout << "\n";

	return 0;
}

//======================================================================================================================================================================
//===============================================================================<  Task 1  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 1
*/
void Task1_main(std::string filePath) {
	DogMapDefault dogMap;
	load_csvFile_Normal_Loop(dogMap, filePath);
	cout << dogMap << endl;
}

/**
* This function Loading the dogMap From an Input File in normal way
* @param MultiMapType&: dog_map 
* @param string: filename
*/
template<typename MultiMapType>
void load_csvFile_Normal_Loop(MultiMapType& dog_map, std::string filename) {
	ifstream input_file_stream(filename);													// Create an input file stream
	if (!input_file_stream.is_open()) {														// Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw std::runtime_error("Could not open file " + filename);
	}
	string line;
	while (getline(input_file_stream, line)) {												// read a line
		stringstream my_line_stream(line);													// turn the line into an input stream
		Dog dog{};
		my_line_stream >> dog;																// initialize dog using Dog's operator>>
		dog_map.emplace(dog.getBreed(), dog);												// insert dog into dog_map
	}
	input_file_stream.close();																// Close file
}


//======================================================================================================================================================================
//===============================================================================<  Task 2  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 2
*/
void Task2_main(std::string filePath) {
	DogMapDefault dogMap;
	load_csvFile_For_Each(dogMap, filePath);
	cout << dogMap << endl;
}

/**
* This function Loading the dogMap From an Input File by for_each
* @param DogMapDefault&: dog_map
* @param string: filename
*/
void load_csvFile_For_Each(DogMapDefault& dog_map, string filename) {
	ifstream input_file_stream(filename);													// Create an input file stream
	if (!input_file_stream.is_open()) {														// Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw std::runtime_error("Could not open file " + filename);
	}
	istream_iterator<Dog> input_start(input_file_stream);									// start of input stream of Dog objects
	istream_iterator<Dog> input_finish;														// end of input stream of Dog objects

	for_each(input_start, input_finish, [&](Dog dog) { dog_map.emplace(dog.getBreed(), dog); });  // insert dog into dog_map
		
	input_file_stream.close();																// Close file
}

//======================================================================================================================================================================
//===============================================================================<  Task 3  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 3
*/
void Task3_main(std::string filePath) {
	DogMapDefault dogMap;
	load_csvFile_Transform(dogMap, filePath);
	cout << dogMap << endl;
}

/**
* This function Loading the dogMap From an Input File by transform
* @param DogMapDefault&: dog_map
* @param string: filename
*/
void load_csvFile_Transform(DogMapDefault& dog_map, string filename) {
	ifstream input_file_stream(filename);													// Create an input file stream
	if (!input_file_stream.is_open()) {														// Check that the file is open
		std::cout << "Could not open file " + filename << endl;
		throw std::runtime_error("Could not open file " + filename);
	}

	istream_iterator<Dog> input_start(input_file_stream);									// start of input stream of Dog objects
	istream_iterator<Dog> input_finish;														// end of input stream of Dog objects

	// returns an pair<string, Dog> element to be inserted into multimap
	transform(input_start, input_finish, std::inserter(dog_map, dog_map.begin()), [&](Dog dog) { return std::pair<std::string, Dog>(dog.getBreed(), dog); });
		
	input_file_stream.close();																// Close file

}


//======================================================================================================================================================================
//===============================================================================<  Task 4  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 4
*/
void Task4_main(std::string filePath) {
	DogMapGreater dogMap;																	// multimap<string, Dog, greater<string>>;
	load_csvFile_Normal_Loop(dogMap, filePath);
//	load_csvFile_Normal_Loop_greater(dogMap, filePath);
	cout << dogMap << endl;
}

/**
* This function Loading the dogMap From an Input in the reverse order
* @param DogMapGreater&: dog_map
* @param string: filename
*/
void load_csvFile_Normal_Loop_greater(DogMapGreater& dog_map, string filename) {
	ifstream input_file_stream(filename);													// Create an input file stream
	if (!input_file_stream.is_open()) {														// Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw std::runtime_error("Could not open file " + filename);
	}
	string line;
	while (getline(input_file_stream, line)) {												// read a line
		stringstream my_line_stream(line);													// turn the line into an input stream
		Dog dog{};
		my_line_stream >> dog;																// initialize dog using Dog's operator>>
		dog_map.emplace(dog.getBreed(), dog);												// insert dog into dog_map
	}
	input_file_stream.close();																// Close file
}



//======================================================================================================================================================================
//===============================================================================<  Task 5  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 5
*/
void Task5_main(std::string filePath) {
	DogMapDefault dog_map;
	load_csvFile_Normal_Loop(dog_map, filePath);
	DogMapDefault breedRangeMap1 = findBreedRange(dog_map, std::string("Greyhound"));
	cout << breedRangeMap1 << "----------" << endl;
	DogMapDefault breedRangeMap2 = findBreedRange(dog_map, std::string("Lakeland Terrier"));
	cout << breedRangeMap2 << "----------" << endl;
	DogMapDefault breedRangeMap3 = findBreedRange(dog_map, std::string("Pug"));
	cout << breedRangeMap3 << "----------" << endl;
	DogMapDefault breedRangeMap4 = findBreedRange(dog_map, std::string("Xyz"));
	cout << breedRangeMap4 << "----------" << endl;
}

/**
* This function takes a DogMapDefault and a string as parameters and returns a DogMapDefault that contains all Dog objects in source having the same key breed.
* @param DogMapDefault: source
* @param string: key_breed
* @return DogMapDefault
*/
DogMapDefault findBreedRange(DogMapDefault& source, const std::string& key_breed)
{
	DogMapDefault result;
	auto p = source.equal_range(key_breed);
	for (auto i = p.first; i != p.second; ++i) {
		result.emplace(i->first, i->second);
	}
	return result;
}

//======================================================================================================================================================================
//===============================================================================<  Task 6  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 6
*/
void Task6_main() {
	test_is_palindrome();
	cout << "\n";
}

/**
* This function check the character which are alphabetic or not
* @param char: ch
* @return bool
*/
bool is_alphabetic(char ch) {
	if (isalpha(ch) == 0) {
		return true;
	}
	else {
		return false;
	}
}

/**
* This function check that a palindrome is a word or phrase that reads the same when read forward or backward
* @param string: str
* @return bool
*/
bool is_palindrome(string str) {
	string temp;
	remove_copy_if(str.begin(), str.end(), inserter(temp, temp.begin()), is_alphabetic);				// move only alphabet characters from phrase to temp
	transform(temp.begin(), temp.end(), temp.begin(), [&](char ch) { return tolower(ch); });			// convert all the characters in it to the same letter - case, either uppercase or lowercase

	bool result = std::equal(temp.begin(), temp.end(), temp.rbegin());									// use std::equal to compare the rst half of temp with its second half
	if (result == 0) {
		return false;
	}
	else {
		return true;
	}
}

/**
* This function test the functionality of is_palindrome
*/
void test_is_palindrome()
{
	std::string str_i = std::string("was it a car or A Cat I saW?");
	std::string str_u = std::string("was it A Car or a cat U saW?");
	cout << "the phrase \"" + str_i + "\" is " +
		(is_palindrome(str_i) ? "" : "not ") + "a palindrome\n";
	cout << "the phrase \"" + str_u + "\" is " +
		(is_palindrome(str_u) ? "" : "not ") + "a palindrome\n";
}

//======================================================================================================================================================================
//===============================================================================<  Task 7  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for Task 7
*/
void Task7_main() {
	vector<int> vec;
	vec.push_back(40);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(25);
	vec.push_back(20);
	vec.push_back(30);
	test_second_max(vec);															//	second_max(vec.begin(), vec.end());
	cout << "\n";
}

template <class Iterator>															// template header
std::pair<Iterator, bool>															// function template return type;

/**
* This function find the second largest element in a container within a given range
* @param Iterator: start
* @param Iterator: finish
*/
second_max(Iterator start, Iterator finish)											// function signature
{
	bool isEmpty = false;
	bool allEqualElements = true;
	bool distinctElements = false;
	Iterator first_max = start;
	Iterator iter = start;

	if (start == finish) {
		isEmpty = true;
	}
	else {
		while (start != finish) {
			if (*start > * first_max) {
				iter = first_max;
				first_max = start;
				allEqualElements = false;
				distinctElements = true;
			}
			else if (*start < *first_max) {
				if (iter == first_max) {
					iter = start;
				}
				else if (*start > * iter) {
					iter = start;
				}
				allEqualElements = false;
				distinctElements = true;
			}
			++start;
		}
	}

	if (isEmpty) {
		return std::make_pair(finish, false);
	}
	else if (allEqualElements) {
		return std::make_pair(iter, false);
	}
	else if (distinctElements) {
		return std::make_pair(iter, true);
	}
}

/**
* This function test the functionality of second_max
* @param vector<int>: vec
*/
void test_second_max(std::vector<int> vec)
{
	// note: auto in the following statement is deduced as
	// std::pair<std::vector<int>::iterator, bool>
	auto retval = second_max(vec.begin(), vec.end());									// find the second max
	if (retval.second)
	{
		cout << "The second largest element in vec is "
			<< *retval.first << endl;
	}
	else
	{
		if (retval.first == vec.end())
			cout << "List empty, no elements\n";
		else
			cout << "Container's elements are all equal to "
			<< *retval.first << endl;
	}
}

//======================================================================================================================================================================
//===============================================================================<  problem 6  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for problem 6
*/
void Task8_main() {
	std::vector<std::string> vec{ "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };

	cout << "testCountStringsLambda: " << endl;
	cout << testCountStringsLambda(vec, 1) << ", " << testCountStringsLambda(vec, 2) << ", " << testCountStringsLambda(vec, 3) << ", " << testCountStringsLambda(vec, 4) <<endl;

	cout << "testCountStringsFreeFun: " << endl;
	cout << testCountStringsFreeFun(vec, 1) << ", " << testCountStringsFreeFun(vec, 2) << ", " << testCountStringsFreeFun(vec, 3) << ", " << testCountStringsFreeFun(vec, 4) << endl;

	cout << "testCountStringsFunctor: " << endl;
	cout << testCountStringsFunctor(vec, 1) << ", " << testCountStringsFunctor(vec, 2) << ", " << testCountStringsFunctor(vec, 3) << ", " << testCountStringsFunctor(vec, 4) << endl;
	cout << "\n";
}


//int countsStringLambda(const std::vector<string> vec, int n) {
//	return count_if(vec.begin(), vec.end(), [&](string str) { 
//		return str.size() == n; 
//		});
//};
//auto countsStringLambda = [=](string str, int n) { return str.size() == n; };
//
//int testCountStringsLambda(const std::vector<std::string>& vec, int n) {
//	int count = count_if(vec.begin(), vec.end(), std::bind(countsStringLambda, std::placeholders::_1, n));
//	return count;
//}

/**
* This function test the functionality of countsStringLambda
* @param const std::vector<std::string>
* @param int
* @return int
*/
int testCountStringsLambda(const std::vector<std::string>& vec, int n) {
	auto countsStringLambda = [=](string str) { return str.size() == n; };						// Lambda func
	int count = count_if(vec.begin(), vec.end(), countsStringLambda);							// count_if
	return count;
}

/*
* A free function named countStringsFreeFun
* @param string: str
* @param int: n
* @return int
*/
int countStringsFreeFun(string str, int n) {
	return str.size() == n;
}

/**
* This function test the functionality of countStringsFreeFun
* @param const std::vector<std::string>
* @param int
* @return int
*/
int testCountStringsFreeFun(const std::vector<std::string>& vec, int n) {
	int count = std::count_if(vec.begin(), vec.end(), std::bind(countStringsFreeFun, std::placeholders::_1, n));
	return count;
}

/*
* A functor (function object) named countStringsFunctor
*/
class countStringsFunctor {
	int n;
public:
	countStringsFunctor(int n) {
		this->n = n;
	}
	int operator() (string str) {															// Function operator overloading
		return str.size() == n;
	}
};

/**
* This function test the functionality of testCountStringsFunctor
* @param const std::vector<std::string>
* @param int
* @return int
*/
int testCountStringsFunctor(const std::vector<std::string>& vec, int n) {
	countStringsFunctor func(n);
	int count = count_if(vec.begin(), vec.end(), func);
	return count;
}

//======================================================================================================================================================================
//===============================================================================<  problem 7  >===========================================================================
//======================================================================================================================================================================

/**
* This is the main function for problem 7
*/
void Task9_main() {
	multisetUsingDefaultComparator();
	cout << "\n";
	multisetUsingMyComparator();
	cout << "\n";
}

/**
* This class works as my cmparator and works in the way that the string elements in strSet are now ordered into groups of strings of
* increasing lengths 1, 2, 3, ..., with the strings in each group sorted lexicographically.
*/
class myCompare {
public:
	bool operator() (const string& x, const string& y) const {										// Function overloading
		if (x.length() < y.length())
			return true;
		else if (x.length() > y.length())
			return false;
		else {
			return (x < y);
		}
	}
};

/**
* This function defines a multiset object using std::multiset's default compare type parameter, which is std::less<T>
*/
void multisetUsingDefaultComparator()
{
	multiset<std::string> strSet; // an empty set

	// a set that uses the default std::less<int> to sort the set elements
	std::vector<std::string> vec{ "C", "BB", "A", "CC", "A", "B",
								  "BB", "A", "D", "CC", "DDD", "AAA" };

	// copy the vector elements to our set. 
	// We  must use a general (as oppsed to a front or back) inserter.
	// (set does not have push_front or push_back members,
	// so we can't use a front or back inserter)

	std::copy(vec.begin(), vec.end(),                // source start and finish
		std::inserter(strSet, strSet.begin()));		// destination start with
													// a general inserter

	// create an ostream_iterator for writing to cout, 
	// using a space " " as a separator
	std::ostream_iterator<std::string> out(cout, " ");

	// output the set elements to cout separating them with a space
	std::copy(strSet.begin(), strSet.end(), out);
}

/**
* This function defines a multiset object using my comparator
*/
void multisetUsingMyComparator()
{
	multiset<std::string, myCompare> strSet;														// an empty set with myCompare_Less
	std::vector<std::string> vec{ "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
	std::copy(vec.begin(), vec.end(), std::inserter(strSet, strSet.begin())); 
	std::ostream_iterator<std::string> out(cout, " ");
	std::copy(strSet.begin(), strSet.end(), out);
}