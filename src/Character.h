//Header file for characters in the game
//Includes a base class CardHolder and three derived classes Croupier, Computer, Human

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <map>
#include "Strategy.h"
#include "Observer.h"

// Base class for the character that holds a suit of card at the beginning
class CardHolder {

protected:
	// Map to store the mapping between a card and its value
	const static std::map<std::string, int> cardValMap;

	// Vector of the original hand
	std::vector<std::string> cards;

	// Card selection strategy object
	Strategy* strategy = NULL;

	
public:
	// Destructor 
	~CardHolder();

	// Function to play a card from hand
	std::string play();

	// Function to get a new suit
	void getNewSuit();
};


// Class for the croupier of the game
class Croupier : public CardHolder{

private:
	// Map to store the score of computer and human
	std::map<std::string, int> scoringMap;

public:
	// Constructor
	Croupier();

	// Function to compare the cards and assign scores
	void evaluate();
};

class Computer : public CardHolder{
public:
	// Constructor
	Computer();

	// Function to observe user's playing pattern
	void observePattern(const int& round, const std::string& pCard, const std::string& hCard);
private:
	Observer observer;
};

class Human : public CardHolder{
public:
	// Function to ask user to play a card from hand
	std::string play();

private:
	// Function to show current hand to player
	void showHand();
};


#endif