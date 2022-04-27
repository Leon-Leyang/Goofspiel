//Header file for card selection strategies used in the game

#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <vector>

// Base class for the card selection strategy
class Strategy {

public:
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
// class MixedStrategy : public RandomStrategy{
// public:
// 	// Function to select a card based on the observation of user
// 	virtual std::string selectCard(const std::vector<std::string>& cards) const;
//  };


#endif