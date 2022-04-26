#include "Observer.h"
#include <iostream>

using namespace std;

// Function to update the recordMatrix
void Observer::update(const int& round, const string& pCard, const string& hCard){
    recordMatrix[round - 1][pCard] = hCard;
}

// Function to create a new Row and push it to the back of the recordMatrix
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

// Function to calculate user's preference play for specific prize card
Row Observer::getPreference(){
    Row row;
    cout << row.size() << endl;
    return row;
}