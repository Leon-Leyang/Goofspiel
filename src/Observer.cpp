#include "Observer.h"
#include <iostream>

using namespace std;

void Observer::update(const int& round, const string& pCard, const string& hCard){
    cout << "round" << round << endl;
    cout << "pcard" << pCard << endl;
    cout << "hcard" << hCard << endl;
}

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
    cout << recordMatrix[0]["A"] << endl;
}

vector<tuple<string, string>> Observer::getPreference(){
    vector<tuple<string, string>> test;
    return test;
}