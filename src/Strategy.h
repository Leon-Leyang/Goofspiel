//Header file for card selection strategies used in the game

#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <vector>
#include "Observer.h"

// Base class for the card selection strategy
class Strategy {

public:
	// Map to store the mapping between a card and its value
	const static std::map<std::string, int> cardValMap;

	// Function to select a card from hand according to the situation and return the selection
	// Pure virtual function that shall be defined in derived class
	virtual std::string selectCard(const std::vector<std::string>& cards)  const = 0;
};


// Derived class for random card selection strategy
class RandomStrategy : public Strategy{

public:
	// Function to select a card randomly
	virtual std::string selectCard(const std::vector<std::string>& cards) const;
};

// Derived class for learning and random mixed strategy
class HybridStrategy : public RandomStrategy{
public:
	// Constructor
	HybridStrategy(Observer& observer);

	// Function to select a card based on the observation of user
	virtual std::string selectCard(const std::vector<std::string>& cards) const;

private:
	Observer& observer;

	// Funtion to calculate the card whose value is 1 bigger than the given card
	std::string findLargerCard(std::string card) const;

	// Funtion to return computer's cards removing all possible cards that might be 1 bigger than user's preferred cards
	std::vector<std::string> removePossibleCards(const std::vector<std::string>& cards) const;
};


#endif