#include "Strategy.h"


// Function to select a card randomly
string RandomStrategy::selectCard() {
	// Generate a random index from 0 to size of the hand - 1
	int size = this->cards.size();
	int index = rand() % size;

	// Get the card at the index and return it
	string card = this->cards[index];
	return card;
}