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
        Row pCard2hCard = calcHCard4PCard();
        Row hCard2pCard = calcPcard4HCard();

        auto it = pCard2hCard.begin();
        while(it != pCard2hCard.end()){
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

        for(int i = 0; i < recordMatrix.size(); i++){
            hCard = recordMatrix[i][pCard];
            counter[hCard] += 1;
        }

        int maxCount = 0;

        auto counterIt = counter.begin();
        while (counterIt != counter.end()){
            if(counterIt->second > maxCount){
                maxCount = counterIt->second;
                hCard = counterIt->first;
            }
            counterIt++;
        }

        row[pCard] = hCard;

        it++;
    }

    return row; 
}

// Function to calculate the Row whose key is the user's card and value is the prize card that is most frequently being bid by this card
Row Observer::calcPcard4HCard(){
    Row row;
    return row;
}


// Function to calculate user's preference play for specific prize card
Row Observer::getPreference(){
    Row row;
    cout << row.size() << endl;
    return row;
}