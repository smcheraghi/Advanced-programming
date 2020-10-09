#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "Shape.h"
#include <array>

using namespace std;

class SlotMachine
{
private:
	array<unique_ptr<Shape>, 3> reel{};							// Array of three reel		
	int current_tokens;											// Represent the current token
	int amountOfBet;											// Amount of money to bet
	int tokenWon;												// Number of tokens per win
	int prizeRate;												// coefficient of prize

	void setCurrentToken(int t);								// Step 2: Set the current token
	bool readAmountOfBet();										// Step 5: Read a number for betting
	void make_shapes();											// Step 6-19: Assign a shape to each reel based on the random number
	void make_shape(int k);										// Steps 7-18: Assign a shape to reel with index k in reel array based on the random number 
	void printReels();											// Step 20: Print the reels
	void computeTokensWon();									// Step 21: Compute the number of tokens which wins
	void updateCurrentToken();									// Step 22: Update the current token
	void display();												// Step 23: Display whether the player has won, lost, or neither 

	string generateWelcomingMsg();								// Generate welcoming message when the program started
	string trimSpace(string str);								// Remove space from both side of a string
	bool isWhiteSpaceLine(string str);							// Check the string to be white space or not 
	Grid generateBackgroundOfReels();							// Generate the master grid 
	Grid addReelsToMasterGrid(Grid masterGrid);					// Add reels one by one from reel array to the master grid
	void printMasterGrid(Grid masterGrid);						// Print the master grid	

public:
	SlotMachine() = default;									// ctor
	virtual ~SlotMachine() = default;							// dtor
	SlotMachine(const SlotMachine&)	= delete;					// copy ctor 
	SlotMachine(SlotMachine&&) = delete;						// move ctor
	SlotMachine& operator= (const SlotMachine&) = delete;		// copy assignment 
	SlotMachine& operator= (SlotMachine&&) = delete;			// move assignment 
	
	void run(int t=10);

};

#endif 