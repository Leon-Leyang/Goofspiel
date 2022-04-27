#include "Strategy.h"
#include <iostream>

using namespace std;

// Function to select a card randomly
string RandomStrategy::selectCard(const vector<string>& cards) const{
	// Generate a random index from 0 to size of the hand - 1
	int size = cards.size();
	int index = rand() % size;


	// Get the card at the index and return it
	string card = cards[index];

	return card;
}

