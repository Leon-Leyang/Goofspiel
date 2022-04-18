//Header file for card selection strategy used in the game

#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <vector>

using namespace std;

// Base class for the card selection strategy
class Strategy {

public:
	// Function to select a card from hand according to the situation and return the selection
	// Pure virtual function that shall be defined in derived class
	virtual string selectCard(string pCard, vector<string> selfCards, vector<string> oppoCards) = 0;
};


#endif