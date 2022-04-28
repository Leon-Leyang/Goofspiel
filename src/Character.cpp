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

// Function to get a new suit
void CardHolder::getNewSuit(){
	vector<string> cardsTemp{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	cards = cardsTemp;
}

// Constructor for Croupier
Croupier::Croupier() {
	// Initialize the strategy to be the random strategy
	RandomStrategy* randomStrategy = new RandomStrategy();
	strategy = randomStrategy;
}

// Function to initialize scoringMap
void Croupier::initScoringMap(){
	map<std::string, float> scoringMapTemp = {
		{"computer", 0.0},
		{"human", 0.0}
	};
	scoringMap = scoringMapTemp;
}


// Function to compare the cards and assign the prize
void Croupier::evaluate(const string& pCard, const string& cCard, const string& hCard) {
	int pValue = cardValMap.at(pCard);
	int cValue = cardValMap.at(cCard);
 	int hValue = cardValMap.at(hCard);

	cout << endl << "You played " << hCard << " and the computer played " << cCard << endl;

	if(cValue > hValue){
		scoringMap["computer"] += pValue;
		cout << "The computer won this round and gained " << pValue << " point(s)!" << endl;
	}else if(cValue < hValue){
		scoringMap["human"] += pValue;
		cout << "You won this round and gained " << pValue << " point(s)!" << endl;
	}else{
		scoringMap["computer"] += static_cast< float > (pValue) / 2;
		scoringMap["human"] += static_cast< float > (pValue) / 2;
		cout << "You're tied with the computer this round and both of you gained " << static_cast< float > (pValue) / 2 << " point(s)!" << endl;
	}
}

// Function to evaluate the whole game
void Croupier::evaluate(){
	cout << "\n--------------------------------------------------------------\n" << endl;
	cout << "In total, you have gained " << scoringMap["human"] << " points and the computer has gained " << scoringMap["computer"] << " points!" << endl;
	if(scoringMap["human"] > scoringMap["computer"]){
		cout << "You won this game ";
	}else if(scoringMap["human"] < scoringMap["computer"]){
		cout << "You lost this game ";
	}else{
		cout << "You're tied with the computer in this game ";
	}

	cout << "and your score was " << scoringMap["human"] - scoringMap["computer"] << "!" << endl;
}


// Constructor for Computer
Computer::Computer() {
	// Initialize the strategy to be the mixed strategy
	HybridStrategy* hybridStrategy = new HybridStrategy(observer);
	strategy = hybridStrategy;
}

// Function to start a round of observation
void Computer::startNewObserve(){
	observer.create();
}

// Function to learn user's playing preference
void Computer::learn(){
	observer.calc();
}

// Function to call the observer to update the record, observe user's pattern and left cards in hand 
void Computer::observe(const int& round, const string& pCard, const string& hCard){
	observer.update(round, pCard, hCard);
}

// Function to observe the prize card this round
void Computer::observe(const string& pCard){
	observer.setPCard(pCard);
}

// Function to ask user to play a card from hand
string Human::play(){
	string card;

	showHand();


	cout << endl;

	cout << "Please enter the card you want to play for this round: ";
	cin >> card;

	// Remove the card from hand
	auto it = find(cards.begin(), cards.end(), card);
	int index = it - cards.begin();
	cards.erase(cards.begin() + index);

	return card;
}

void Human::showHand(){
	cout << "Your current hand: ";
	for(auto & elem : cards){
        cout<<elem<<", ";
    }
}