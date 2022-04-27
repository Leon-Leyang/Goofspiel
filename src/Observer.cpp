#include "Observer.h"
#include <iostream>

using namespace std;

// Function to update the recordMatrix and the preference
void Observer::update(const int& round, const string& pCard, const string& hCard){
    // Update the recordMatrix
    recordMatrix[round - 1][pCard] = hCard;

    if(preference.size() > 0){
        // Delete element in preference with pCard as key 
        preference.erase(pCard);
        cout << "Erase preference with pCard: " << pCard << endl;

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

}

// Function to calculate user's preference from previous play and create a new Row in the recordMatrix for a new round of observation
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
}

// Function to calculate user's preference
void Observer::calc(){
    if(recordMatrix.size() >= 2){
        cout << "calculate preference" << endl;
        // Row hCard4pCard = calcHCard4PCard();
        Row pCard4hCard = calcPCard4HCard();

        auto it = hCard4pCard.begin();
        while(it != hCard4pCard.end()){
            cout << it->first << ": " << it->second << endl;
            it++;
        }

        it = pCard4hCard.begin();
        while(it != pCard4hCard.end()){
            cout << it->first << ": " << it->second << endl;
            it++;
        }




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