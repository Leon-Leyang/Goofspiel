#include "Strategy.h"
#include <iostream>

string Strategy::selectCard(const vector<string>& cards) {
	cout << "base sel" << endl;

	string str = "base sel";

	return str;
}


// Function to select a card randomly
string RandomStrategy::selectCard(const vector<string>& cards) {
	// Generate a random index from 0 to size of the hand - 1
	int size = cards.size();

	int index = rand() % size;

	// Get the card at the index and return it
	string card = cards[index];
	
	cout << "cards size:" << size << endl;
	cout << "index:" << index << endl;
	cout << "card played: " << card << endl;


	return card;
}