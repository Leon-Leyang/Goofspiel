//Header file for characters in the game
//Includes a base class CardHolder and three derived classes Croupier, Computer, Human

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <map>
#include "Strategy.h"

// Base class for the character that holds a suit of card at the beginning
class CardHolder {

protected:
	// Map to store the mapping between a card and its value
	const static std::map<std::string, int> cardValMap;

	// Vector of the original hand
	std::vector<std::string> cards{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	// Card selection strategy object
	Strategy* strategy = NULL;

	
public:
	// Function to play a card from hand
	std::string play();
	~CardHolder();
};





// Class for the croupier of the game
class Croupier : public CardHolder{

private:
	// Map to store the score of computer and human
	std::map<std::string, int> scoringMap = {
		{"computer", 0},
		{"human", 0}
	};

public:
	Croupier();

	// Function to compare the cards and assign scores
	void evaluate();
};




#endif