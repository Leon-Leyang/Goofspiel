#include "Observer.h"
#include <iostream>

using namespace std;

void Observer::update(const int& round, const string& pCard, const string& hCard){
    cout << "update" << endl;
}

vector<tuple<string, string>> Observer::getPreference(){
    vector<tuple<string, string>> test;
    return test;
}