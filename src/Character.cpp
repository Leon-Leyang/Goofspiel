#include "Character.h"
#include <iostream>
#include <algorithm>

using namespace std;


// Map to store the mapping between a card and its value
const map<string, int> CardHolder::cardValMap = {
													{"A", 1},
													{"2", 2 },
													{"3", 3 },
													{"4", 4 },
													{"5", 5 },
													{"6", 6 },
													{"7", 7 },
													{"8", 8 },
													{"9", 9 },
													{"10", 10 },
													{"J", 11 },
													{"Q", 12 },
													{"K", 13 },
												};

// Constructor for CardHolder
CardHolder::CardHolder() {
	vector<string> cardsTemp{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	cards = cardsTemp;
}

// Destructor for CardHolder
CardHolder::~CardHolder() {
	delete strategy;
}

// Function to play a card from hand
string CardHolder::play() {
	// Use the strategy to select a card from hand
	string card = strategy->selectCard(cards);
	
	// Remove the card from hand
	auto it = find(cards.begin(), cards.end(), card);
	int index = it - cards.begin();
	cards.erase(cards.begin() + index);
	
	return card;
}

// Constructor for Croupier
Croupier::Croupier() {
	// Initialize the strategy to be the random strategy
	RandomStrategy* randomStrategy = new RandomStrategy();
	strategy = randomStrategy;

	// Initialize the scoring map for later recording of the scores
	map<std::string, int> scoringMapTemp = {
		{"computer", 0},
		{"human", 0}
	};
	scoringMap = scoringMapTemp;
}


// Function to compare the cards and assign the prize
void Croupier::evaluate() {
	cout << "eval" << endl;
}