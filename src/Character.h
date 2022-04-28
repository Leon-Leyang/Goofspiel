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

	// Vector of the original hand
	std::vector<std::string> cards;

	// Card selection strategy object
	Strategy* strategy = NULL;

	
public:
	// Destructor 
	~CardHolder();

	// Map to store the mapping between a card and its value
	const static std::map<std::string, int> cardValMap;

	// Function to play a card from hand
	std::string play();

	// Function to get a new suit
	void getNewSuit();
};


// Class for the croupier of the game
class Croupier : public CardHolder{

private:
	// Map to store the score of computer and human
	std::map<std::string, float> scoringMap;

public:
	// Constructor
	Croupier();

	// Function to compare the cards and assign scores
	void evaluate(const std::string& pCard, const std::string& cCard, const std::string& hCard);

	// Function to evaluate the whole game
	void evaluate();

	// Function to initialize scoringMap
	void initScoringMap();
};

class Computer : public CardHolder{
public:
	// Constructor
	Computer();

	// Function to start a round of observation
	void startNewObserve();

	// Function to learn user's playing preference
	void learn();

	// Function to observe user's playing pattern and left hand
	void observe(const int& round, const std::string& pCard, const std::string& hCard);

	// Function to observe the prize card this round
	void observe(const std::string& pCard);
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