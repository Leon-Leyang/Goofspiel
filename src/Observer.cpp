#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Function to update the recordMatrix, the preference and left cards in user's hand
void Observer::update(const int& round, const string& pCard, const string& hCard){
    // Update the recordMatrix
    recordMatrix[round - 1][pCard] = hCard;

    if(preference.size() > 0){
        // Delete element in preference with pCard as key 
        if(preference.erase(pCard)){
            cout << "Erase preference with pCard: " << pCard << endl;
        }

        // Delete element in preference with hCard as value 
        auto it = preference.begin();
        while (it != preference.end()){
            if (it->second == hCard){
                it = preference.erase(it);
                cout << "Erase preference with hCard: " << hCard << endl;
                break;
            }else{
                it++;
            }
        }
    }

    // Remove the card from user's left cards
	auto it1 = find(hCards.begin(), hCards.end(), hCard);
	int index = it1 - hCards.begin();
	hCards.erase(hCards.begin() + index);
    cout << "Remove " << hCard << " from user's left cards" << endl;
}

// Function to create a new Row, push it to the back of the recordMatrix and renew the left cards in user's hand
void Observer::create(){
    Row row = { 
                {"A", ""},
                {"2", "" },
                {"3", "" },
                {"4", "" },
                {"5", "" },
                {"6", "" },
                {"7", "" },
                {"8", "" },
                {"9", "" },
                {"10", "" },
                {"J", "" },
                {"Q", "" },
                {"K", "" },
    };
    recordMatrix.push_back(row);

    // Initialize user's left cards
    vector<string> hCardsTemp{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	hCards = hCardsTemp;
    cout << "Renew user's left cards" << endl;
}

// Function to calculate user's preference
void Observer::calc(){
    // Clear the previous calculated preference
    preference.clear();

    // Testing resources
    // Row row1 = { 
    //             {"A", "3"},
    //             {"2", "2" },
    //             {"3", "4" },
    //             {"4", "K" },
    //             {"5", "Q" },
    //             {"6", "J" },
    //             {"7", "10" },
    //             {"8", "9" },
    //             {"9", "8" },
    //             {"10", "7" },
    //             {"J", "6" },
    //             {"Q", "5" },
    //             {"K", "A" },
    // };
    // recordMatrix.push_back(row1);

    // Row row2 = { 
    //             {"A", "A"},
    //             {"2", "2" },
    //             {"3", "4" },
    //             {"4", "8" },
    //             {"5", "6" },
    //             {"6", "5" },
    //             {"7", "J" },
    //             {"8", "Q" },
    //             {"9", "K" },
    //             {"10", "9" },
    //             {"J", "7" },
    //             {"Q", "10" },
    //             {"K", "3" },
    // };
    // recordMatrix.push_back(row2);

    // Row row3 = { 
    //             {"A", "2"},
    //             {"2", "3" },
    //             {"3", "4" },
    //             {"4", "5" },
    //             {"5", "6" },
    //             {"6", "7" },
    //             {"7", "8" },
    //             {"8", "9" },
    //             {"9", "10" },
    //             {"10", "J" },
    //             {"J", "Q" },
    //             {"Q", "K" },
    //             {"K", "A" },
    // };
    // recordMatrix.push_back(row3);

    // Row row4 = { 
    //             {"A", "2"},
    //             {"2", "4" },
    //             {"3", "5" },
    //             {"4", "6" },
    //             {"5", "7" },
    //             {"6", "8" },
    //             {"7", "9" },
    //             {"8", "10" },
    //             {"9", "J" },
    //             {"10", "Q" },
    //             {"J", "K" },
    //             {"Q", "A" },
    //             {"K", "3" },
    // };
    // recordMatrix.push_back(row4);

    // Row row5 = { 
    //             {"A", "2"},
    //             {"2", "5" },
    //             {"3", "6" },
    //             {"4", "7" },
    //             {"5", "8" },
    //             {"6", "9" },
    //             {"7", "10" },
    //             {"8", "J" },
    //             {"9", "Q" },
    //             {"10", "K" },
    //             {"J", "A" },
    //             {"Q", "3" },
    //             {"K", "4" },
    // };
    // recordMatrix.push_back(row5);

    

    // Only calculate user's preference when there have been more than one round
    if(recordMatrix.size() >= 2){
        cout << "calculate preference" << endl;

        // Calculate for each prize card the user's most frequently used card
        Row hCard4pCard = calcHCard4PCard();

        // Calculate for each user's card the most frequenly bid prize card
        Row pCard4hCard = calcPCard4HCard();

        // Only for testing
        // auto it = hCard4pCard.begin();
        // while(it != hCard4pCard.end()){
        //     cout << it->first << ": " << it->second << endl;
        //     it++;
        // }
        // it = pCard4hCard.begin();
        // while(it != pCard4hCard.end()){
        //     cout << it->first << ": " << it->second << endl;
        //     it++;
        // }

        // Compare the two Row above
        // Get user's preference with the following rule:
        //      if for a prize card P_a, user most frequently uses H_a to bid
        //      And for the card H_a, user most frequently uses it to bid for P_a
        //      Then add <P_a, H_a> to the preference 
        auto it = hCard4pCard.begin();
        while(it != hCard4pCard.end()){
            string pCard = it->first;
            string hCard = it->second;

            string pCardBid = pCard4hCard[hCard];

            if(pCard == pCardBid){
                preference[pCard] = hCard;
            }

            it++;
        }

        // Only for testing
        // it = preference.begin();
        // while(it != preference.end()){
        //     cout << "P: " << it->first << " ; H: " << it->second << endl;
        //     it++;
        // }


    }else{
        cout << "Too small for learning" << endl;
    }
}

// Function to calculate the Row whose key is the prize card and value is user's card that is used most frequently to bid this prize card
Row Observer::calcHCard4PCard(){
    Row row = { 
                {"A", ""},
                {"2", "" },
                {"3", "" },
                {"4", "" },
                {"5", "" },
                {"6", "" },
                {"7", "" },
                {"8", "" },
                {"9", "" },
                {"10", "" },
                {"J", "" },
                {"Q", "" },
                {"K", "" },
    };


    // Map to store the time of each card played as a counter
    map<string, int> counter;

    // Iterate through all prize cards and find the user's card that is used most frequently to bid each correspondingly
    auto it = row.begin();
    while (it != row.end()){
        string pCard = it->first;
        string hCard;

        // Initialize the counter
        counter = {
                {"A", 0},
                {"2", 0 },
                {"3", 0 },
                {"4", 0 },
                {"5", 0 },
                {"6", 0 },
                {"7", 0 },
                {"8", 0 },
                {"9", 0 },
                {"10", 0 },
                {"J", 0 },
                {"Q", 0 },
                {"K", 0 },
        };

        // Interate through all rounds and count different cards used to bid the current prize card
        for(int i = 0; i < recordMatrix.size(); i++){
            hCard = recordMatrix[i][pCard];
            counter[hCard] += 1;
        }

        // Interate through the counter to find the most frequently used card to bid the current prize card
        int maxCount = 0;
        auto counterIt = counter.begin();
        while (counterIt != counter.end()){
            if(counterIt->second > maxCount){
                maxCount = counterIt->second;
                hCard = counterIt->first;
            }
            counterIt++;
        }

        // Record the result
        row[pCard] = hCard;

        it++;
    }

    return row; 
}

// Function to calculate the Row whose key is the user's card and value is the prize card that is most frequently being bid by this card
Row Observer::calcPCard4HCard(){
    Row row = { 
                {"A", ""},
                {"2", "" },
                {"3", "" },
                {"4", "" },
                {"5", "" },
                {"6", "" },
                {"7", "" },
                {"8", "" },
                {"9", "" },
                {"10", "" },
                {"J", "" },
                {"Q", "" },
                {"K", "" },
    };


    // Map to store the time of each prize card being bid as a counter
    map<string, int> counter;

    // Iterate through all user's cards and find the prize card that is bid most frequently with the corresponding user's card
    auto it = row.begin();
    while (it != row.end()){
        string hCard = it->first;
        string pCard;

        // Initialize the counter
        counter = {
                {"A", 0},
                {"2", 0 },
                {"3", 0 },
                {"4", 0 },
                {"5", 0 },
                {"6", 0 },
                {"7", 0 },
                {"8", 0 },
                {"9", 0 },
                {"10", 0 },
                {"J", 0 },
                {"Q", 0 },
                {"K", 0 },
        };

        // Interate through all rounds and count different prize card being bid with the current user's card
        for(int i = 0; i < recordMatrix.size(); i++){

            Row roundRec = recordMatrix[i];

            // Find the prize card that is bid with the current user's hand in this round
            auto roundIt = roundRec.begin();
            while (roundIt != roundRec.end()){
                if(roundIt->second == hCard){
                    pCard = roundIt->first;
                    break;
                }
                roundIt++;
            }

            counter[pCard] += 1;
        }


        // Interate through the counter to find the most frequently prize card being bid with the current user's card
        int maxCount = 0;
        auto counterIt = counter.begin();
        while (counterIt != counter.end()){
            if(counterIt->second > maxCount){
                maxCount = counterIt->second;
                pCard = counterIt->first;
            }
            counterIt++;
        }

        // Record the result
        row[hCard] = pCard;

        it++;
    }

    return row; 
}


// Function to calculate user's preference play for specific prize card
Row Observer::getPreference(){
    Row row;
    cout << row.size() << endl;
    return row;
}

// Getter for the pCard
string Observer::getPCard(){
    return pCard;
}

// Setter for the pCard
void Observer::setPCard(string PCard){
    pCard = PCard;
    cout << "Update the prize card" << endl;
}

// Getter for the hCards
vector<string> Observer::getHCards(){
    return hCards;
}