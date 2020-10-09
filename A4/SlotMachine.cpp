#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "SlotMachine.h"
#include <iomanip>
#include <sstream>
#include <string>

/*
* Assign a shape to each reel based on the random number
*/
void SlotMachine::make_shapes() {
	for (int k = 0; k < 3; k++) {
		this->make_shape(k);																	// Assign a random shape to the reel[k]

	}
}

/*
* Assign a shape to reel with index k in reel array based on the random number 
* @param k: index of reel array
*/
void SlotMachine::make_shape(int k) {
	int randomInt = rand() % 4;																	// Generate random number between [0, 4)
	int randomWidth = rand() % 25 + 1;															// Generate random number between [1, 25]

	if (randomInt == 0) {
		reel[k].reset(new Rhombus(randomWidth));												// Make reel[k] point to a Rhombus of random width
	}
	else if (randomInt == 1) {
		reel[k].reset(new AcuteTriangle(randomWidth));											// Make reel[k] point to a AcuteTriangle of random width
	}
	else if (randomInt == 2) {
		reel[k].reset(new RightTriangle(randomWidth));											// Make reel[k] point to a RightTriangle of random width
	}
	else {
		int randomHeight = rand() % 25 + 1;
		reel[k].reset(new Rectangle(randomWidth, randomHeight));								// Make reel[k] point to a Rectangle of random width and random height
	}
}

/*
* Display whether the player has won, lost, or neither 
*/
void SlotMachine::display() {
	if (this->prizeRate == 3) {
		cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << endl;
		cout << "Congratulations! you win 3 times your bet: " << this->tokenWon << endl;
		cout << "You now have " << this->current_tokens << " tokens" << endl;
	}
	else if (this->prizeRate == 2) {
		cout << "Three similar shapes" << endl;
		cout << "Congratulations! you win 2 times your bet: " << this->tokenWon << endl;
		cout << "You now have " << this->current_tokens << " tokens" << endl;
	}
	else if (this->prizeRate == 1) {
		cout << "Middle > Left + Right, in Screen Areas" << endl;
		cout << "Congratulations! you win your bet: " << this->amountOfBet << endl;
		cout << "You now have " << this->current_tokens << " tokens" << endl;
	}
	else if (this->prizeRate == 0) {
		cout << "Lucky this time!" << endl;
		cout << "You don't win, you don't lose, you are safe!" << endl;
		cout << "You now have " << this->current_tokens << " tokens" << endl;
	}
	else if (this->prizeRate == -1) {
		cout << "Oh No!" << endl;
		cout << "You lose your bet" << endl;
		cout << "You now have " << this->current_tokens << " tokens" << endl;
	}
	else {
		cout << "Error: Something is wrong!" << endl;
	}
	if (this->current_tokens > 0) {
		cout << endl;
	}
}

/*
* Add reels one by one from reel array to the master grid
* @param masterGrid
* @return masterGrid
*/
Grid SlotMachine::addReelsToMasterGrid(Grid masterGrid) {
	Grid box_0 = this->reel[0]->draw();
	Grid box_1 = this->reel[1]->draw();
	Grid box_2 = this->reel[2]->draw();

	int boarder1 = this->reel[0]->getWidth() + 3;												// Line between reel[0] and reel[1]
	int boarder2 = boarder1 + this->reel[1]->getWidth() + 3;									// Line between reel[1] and reel[2]
	
	// Add reel[0] to the masterGrid
	int shapeHeight = this->reel[0]->getHeight();
	int shapeWidth = this->reel[0]->getWidth();
	for (int i = 0; i < shapeHeight; i++) {
		for (int j = 0; j < shapeWidth; j++) {
			masterGrid[i + 1][j + 2] = box_0[i][j];											// Add in the first part of masterGrid
		}
	}

	// Add reel[1] to the masterGrid
	shapeHeight = this->reel[1]->getHeight();
	shapeWidth = this->reel[1]->getWidth();
	for (int i = 0; i < shapeHeight; i++) {
		for (int j = 0; j < shapeWidth; j++) {
			masterGrid[i + 1][j + boarder1 + 2] = box_1[i][j];									// Add in the second part of masterGrid
		}
	}

	// Add reel[2] to the masterGrid
	shapeHeight = this->reel[2]->getHeight();
	shapeWidth = this->reel[2]->getWidth();
	for (int i = 0; i < shapeHeight; i++) {
		for (int j = 0; j < shapeWidth; j++) {
			masterGrid[i + 1][j + boarder2 + 2] = box_2[i][j];									// Add in the third part of masterGrid		
		}
	}

	return masterGrid;
}

/*
* Print the master grid, print the three reels side by side horizontaly	
* @param masterGrid
*/
void SlotMachine::printMasterGrid(Grid masterGrid) {
	for (int i = 0; i < masterGrid.size(); i++) {
		for (int j = 0; j < masterGrid[i].size(); j++) {
			cout << masterGrid[i][j];
		}
		cout << endl;
	}
	
	// Prints the information of shapes under the picture of shape
	cout << "(" << this->reel[0]->getShapeName() << ", " << this->reel[0]->getHeight() << ", " << this->reel[0]->getWidth() << ") ";
	cout << "(" << this->reel[1]->getShapeName() << ", " << this->reel[1]->getHeight() << ", " << this->reel[1]->getWidth() << ") ";
	cout << "(" << this->reel[2]->getShapeName() << ", " << this->reel[2]->getHeight() << ", " << this->reel[2]->getWidth() << ") " << endl;
}

/*
* Generate the master grid 
* @return reelGrid: master Grid
*/
Grid SlotMachine::generateBackgroundOfReels() {
	int masterGridHeight = 0;
	int masterGridWidth = 0;
	int maxHeight = 0;
	int maxWidth = 0;
	int boarder1 = this->reel[0]->getWidth() + 3;													// Line between reel[0] and reel[1]
	int boarder2 = boarder1 + this->reel[1]->getWidth() + 3;										// Line between reel[1] and reel[2]		

	for (int i = 0; i < 3; i++) {
		if (this->reel[i]->getHeight() > masterGridHeight) {
			maxHeight = this->reel[i]->getHeight();													// Find the max height among three reels	
		}
		if (this->reel[i]->getWidth() > masterGridWidth) {
			maxWidth = this->reel[i]->getWidth();													// Find the max width among three reels
		}
		masterGridHeight = maxHeight;
		masterGridWidth = masterGridWidth + this->reel[i]->getWidth();
	}
	masterGridHeight = masterGridHeight + 2;														// Set the masterGrid height 
	masterGridWidth = masterGridWidth + 10;															// Set the masterGrid newWidth
	
	/* Create the masterGrid which is the background of the all three reels, it contains the margin only and shape parts are empty */
	vector<vector<char>> masterGrid;
	for (int i = 0; i < masterGridHeight; i++) {
		vector<char> row{};
		for (int j = 0; j < masterGridWidth; j++) {
			if (i == 0 || i == masterGridHeight - 1) {
				if (j == 0 || j == boarder1 || j == boarder2 || j == masterGridWidth - 1) {
					row.push_back('+');																// Add margin
				}
				else {
					row.push_back('-');																// Add margin
				}
			}
			else if (j == 0 || j == boarder1 || j == boarder2 || j == masterGridWidth - 1) {
				row.push_back('|');																	// Add margin	
			}
			else if (j == 1 || j == boarder1 - 1 || j == boarder1 + 1 || j == boarder2 - 1 || j == boarder2 + 1 || j == masterGridWidth - 2) {
				row.push_back(' ');																	// Add empty space
			}
			else {
				row.push_back(' ');																	// Add empty space
			}
		}
		masterGrid.push_back(row);
	}
	return masterGrid;
}

/*
* Print the reels
*/
void SlotMachine::printReels() {
	Grid masterGrid = this->generateBackgroundOfReels();											// Generate Master Grid
	masterGrid = addReelsToMasterGrid(masterGrid);													// Add reels to Master Grid
	printMasterGrid(masterGrid);																	// Print Master Grid
}

/*
* Generate welcoming message when the program started
* @return string
*/
string SlotMachine::generateWelcomingMsg() {
	std::stringstream myStream;
	myStream << "Welcome to 3-Reel Lucky Slot Machine Game!" << endl;
	myStream << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	myStream << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas" << endl;
	myStream << "To win 2 x bet, get 3 similar shapes" << endl;
	myStream << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	myStream << "To win or lose nothing, get same Left and Right shapes" << endl;
	myStream << "Otherwise, you lose your bet." << endl;
	myStream << "You start with " << this->current_tokens << " free slot tokens!" << endl;
	
	return myStream.str();
}

/*
* Compute the number of tokens which wins
*/
void SlotMachine::computeTokensWon() {
	// Any two symbols are similar in shape and any two match in screen areas 
	if ((this->reel[0]->getShapeName() == this->reel[1]->getShapeName()) ||						
		(this->reel[0]->getShapeName() == this->reel[2]->getShapeName()) ||
		(this->reel[1]->getShapeName() == this->reel[2]->getShapeName()))						// check any two symbols are similar in shape 
	{
		if ((this->reel[0]->computeScrArea() == this->reel[1]->computeScrArea()) ||					
			(this->reel[0]->computeScrArea() == this->reel[2]->computeScrArea()) ||
			(this->reel[1]->computeScrArea() == this->reel[2]->computeScrArea()))				// Check any two match in screen areas	
		{
			this->prizeRate = 3;
			this->tokenWon = this->prizeRate * this->amountOfBet;
		}
		else if ((this->reel[0]->getShapeName() == this->reel[1]->getShapeName()) &&
			(this->reel[0]->getShapeName() == this->reel[2]->getShapeName()))						// All three symbols are similar in shape 
		{
			this->prizeRate = 2;
			this->tokenWon = this->prizeRate * this->amountOfBet;
		}
		else if (this->reel[1]->computeScrArea() > (this->reel[0]->computeScrArea() + this->reel[2]->computeScrArea()))  // Screen area of middle symbol>sum of screen areas of left and right 
		{
			this->prizeRate = 1;
			this->tokenWon = this->prizeRate * this->amountOfBet;
		}
		else if (this->reel[0]->getShapeName() == this->reel[2]->getShapeName())					// The left and right symbols are similar 
		{
			this->prizeRate = 0;
			this->tokenWon = this->prizeRate * this->amountOfBet;
		}
		else {																						// Player loses the bet
			this->prizeRate = -1;
			this->tokenWon = this->prizeRate * this->amountOfBet;
		}
	}	
	else if ((this->reel[0]->getShapeName() == this->reel[1]->getShapeName()) && 
		(this->reel[0]->getShapeName() == this->reel[2]->getShapeName()))						// All three symbols are similar in shape 
	{
		this->prizeRate = 2;
		this->tokenWon = this->prizeRate * this->amountOfBet;
	}
	else if (this->reel[1]->computeScrArea() > (this->reel[0]->computeScrArea() + this->reel[2]->computeScrArea()))  // Screen area of middle symbol>sum of screen areas of left and right 
	{
		this->prizeRate = 1;
		this->tokenWon = this->prizeRate * this->amountOfBet;
	}
	else if (this->reel[0]->getShapeName() == this->reel[2]->getShapeName())					// The left and right symbols are similar 
	{	
		this->prizeRate = 0;
		this->tokenWon = this->prizeRate * this->amountOfBet;
	}
	else {																						// Player loses the bet
		this->prizeRate = -1;
		this->tokenWon = this->prizeRate * this->amountOfBet;
	}
}

/*
* Update the current token
*/
void SlotMachine::updateCurrentToken() {
	this->current_tokens = this->current_tokens + this->tokenWon;						
}

/*
* Set the current token
* @param t: number of token
*/
void SlotMachine::setCurrentToken(int t) {
	this->current_tokens = t;
}

/**
* Remove space from both side of string
* @param str: input string
* @return string
*/
string SlotMachine::trimSpace(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isspace(str[i])) {
			str = str.substr(i);															// Cut the string from first character util end
			break;
		}
	}
	int myCounter = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (!isspace(str[i])) {
			return str.substr(0, str.size() - myCounter);									// Cut the string from first character from end to until first
		}
		++myCounter;
	}
	return str;
}

/**
* Check that the input string is only white space or not
* @param str: input string
* @return bool
*/
//string SlotMachine::removeWhiteSpace(string str) {
bool SlotMachine::isWhiteSpaceLine(string str) {
	bool stringIsGood = false;
	if (str.empty()) {
//		return str;
		return true;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ' && str[i] != '\t') {
//				return str;
				return false;
			}
		}
	}
//	return "";
	return true;
}

/**
* Read a number for betting
* @return bool
*/
bool SlotMachine::readAmountOfBet() {
	cout << "How much would you like to bet (enter 0 to quit)? ";
	while (true) {
		bool not_digit = false;
		string str;
		while (str.empty()) {
			getline(cin, str);
//			str = removeWhiteSpace(str);
			if (this->isWhiteSpaceLine(str)) {
				str = "";
			}
			if (str.empty()) {
				cout << "How much would you like to bet (enter 0 to quit)? ";
			}
		}
		str = trimSpace(str);

		for (int i = 0; i < str.size(); i++) {
			if (!isdigit(str[i])) {
				not_digit = true;
			}
		}
		if (not_digit == false) {
			this->amountOfBet = stoi(str);
			if (this->amountOfBet <= this->current_tokens) {
				if (this->amountOfBet == 0)
					return false;
				return true;
			}
			else {
				cout << "You can't bet more than " << this->current_tokens << ", try again!" << endl << endl;
				cout << "How much would you like to bet (enter 0 to quit)? ";
			}
		}
		else {
			cout << "Error: Please enter a number between 0 and " << this->current_tokens << endl << endl;
			cout << "How much would you like to bet (enter 0 to quit)? ";
		}
	}
}

/*
* This function is used to run the program
*/
void SlotMachine::run(int t) {
	bool wantToPlay = true;
	srand(time(NULL));																			// Initialize random seed
	this->setCurrentToken(t);																	// Set the current token
	cout << generateWelcomingMsg() << endl;										
	while (this->current_tokens > 0 && wantToPlay)												// countinue until current token is more than zero and player wants to play
	{
		this->amountOfBet = 0;	
		this->tokenWon = 0;
		this->prizeRate = -1;
		wantToPlay = this->readAmountOfBet();													// Read a number for betting
		if (wantToPlay) {
			this->make_shapes();																// Assign a shape to each reel based on the random number
			this->printReels();																	// Print the reels
			this->computeTokensWon();															// Compute the number of tokens which wins
			this->updateCurrentToken();															// Update the current token
			this->display();																	// Display whether the player has won, lost, or neither
		}
		else {
			break;
		}
	}
	if (this->current_tokens <= 0) {
		cout << "You just ran out of tokens, Better luck next time!" << endl;
		cout << "Game Over." << endl;
	}
	else {
		cout << "Thank you for playing, come back soon!" << endl;
		cout << "Be sure you cash in your remaining " << this->current_tokens << " tokens at the bar!" << endl;
		cout << "Game Over." << endl;
	}
}

