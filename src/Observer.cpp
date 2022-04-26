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
    }else{
        cout << "Too small for learning" << endl;
    }
}

// Function to calculate user's preference play for specific prize card
Row Observer::getPreference(){
    Row row;
    cout << row.size() << endl;
    return row;
}