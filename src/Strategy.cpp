#include "Strategy.h"
#include <iostream>
#include <algorithm>

using namespace std;




// Map to store the mapping between a card and its value
const map<string, int> Strategy::cardValMap = {
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




// Function to select a card randomly
string RandomStrategy::selectCard(const vector<string>& cards) const{
	// Generate a random index from 0 to size of the hand - 1
	int size = cards.size();
	int index = rand() % size;


	// Get the card at the index and return it
	string card = cards[index];

	return card;
}

HybridStrategy::HybridStrategy(Observer& observerRef): observer(observerRef){}




// Funtion to calculate the card whose value is 1 bigger than the given card
string HybridStrategy::findLargerCard(string card) const{
	// Get the value of the given card
	int value = Strategy::cardValMap.at(card);

	// If the value is not 13(i.e. the card is not K), find the whose value is 1 bigger
	// Else return ""
	if(value != 13){
		value++;
		auto it = Strategy::cardValMap.begin();
		while(it != Strategy::cardValMap.end()){
			if(it->second == value){
				return it->first;
			}
			it++;
		}
		return "";
	}else{
		return "";
	}
}





// Funtion to return computer's cards removing all possible cards that might be 1 bigger than user's preferred cards
vector<string> HybridStrategy::removePossibleCards(const vector<string>& cards) const{
	vector<string> copy = cards;

	// Get the preference information from the observer
	Row preference = observer.getPreference();

	auto it = preference.begin();
	while(it != preference.end()){
		string hCard = it->second;
		string cCard = findLargerCard(hCard);

		// Remove the card from copy
		auto it1 = find(copy.begin(), copy.end(), cCard);
		if(it1 != copy.end()){
			int index = it1 - copy.begin();
			copy.erase(copy.begin() + index);
		}
		
		
		it++;
	}

	return copy;
}







string HybridStrategy::selectCard(const vector<string>& cards) const{
	// Get the preference information from the observer
	Row preference = observer.getPreference();

	// Get the prize card this round
	string pCard = observer.getPCard();

	// Get user's left card in hand
	vector<string> hCards = observer.getHCards();





	// If there is preference information available,
	if(preference.size() > 0){

		// If the prize card this round correspond to an item in preference
		if(preference.find(pCard) != preference.end()){

			// Get user's card that is most frequently used to bid the prize card
			string hCard = preference[pCard];

			// Get the card whose value is 1 bigger than the user's preferred card
			string cCard = findLargerCard(hCard);

			// If the card exist, return the card
			if(find(cards.begin(), cards.end(), cCard) != cards.end()){
				cout << "exist" << endl;
				return cCard;
			}else{
				cout << "don't exist" << endl;
				return RandomStrategy::selectCard(removePossibleCards(cards));
			}

		}else{
			cout << "no this prize card in preference" << endl;
			return RandomStrategy::selectCard(removePossibleCards(cards));
		}



	}else{
		cout << "no preference" << endl;
		return RandomStrategy::selectCard(cards);
	}
}