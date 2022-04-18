#include "Character.h"

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
void CardHolder::play(string card) {
	remove(cards.begin(), cards.end(), card);
}



// Function to select a card from hand randomly and return the selection
//string Croupier::selectCard() {
//	// Generate a random index from 0 to size of the vector - 1
//	int size = cards.size();
//	int index = rand() % size;
//
//	// Get the card at the index and return it
//	string card = cards[index];
//	return card;
//}

// Function to compare the cards and assign the prize
//void evaluate(string pCard, string hCard, string cCard) {
//	static 
//}