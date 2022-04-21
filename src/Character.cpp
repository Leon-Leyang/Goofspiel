#include "Character.h"
#include <iostream>

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

// Function to play a card from hand
void CardHolder::play() {
	string card = strategy->selectCard(cards);
	//remove(cards.begin(), cards.end(), card);
}


Croupier::Croupier() {
	RandomStrategy randomStrategy;
	strategy = &randomStrategy;
}


// Function to compare the cards and assign the prize
void Croupier::evaluate() {
	cout << "eval" << endl;
}