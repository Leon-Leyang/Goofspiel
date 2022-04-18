//Header file for characters in the game
//Includes a base class CardHolder and three derived classes Croupier, Computer, Human

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <map>

using namespace std;

// Base class for the character that holds a suit of card at the beginning
class CardHolder {

protected:
	// Vector of the original hand
	vector<string> cards{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	// Map to store the mapping between a card and its value
	static const map<string, int> cardValMap;

public:
	// Function to play a card from hand
	void play(string card);

	// Function to select a card from hand and return the selection
	// Pure virtual function that shall be defined in derived class
	virtual string selectCard() = 0;
};


//class Croupier : public CardHolder{
//
//private:
//	// Map to store the score of computer and human
//	map<string, int> scoringMap = {
//		{"computer", 0},
//		{"human", 0}
//	};
//
//public:
//	// Function to select a card from hand randomly and return the selection
//	string selectCard();
//
//	// Function to compare the cards and assign scores
//	void evaluate(string hCard, string cCard);
//};


#endif