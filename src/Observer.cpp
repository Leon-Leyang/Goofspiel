#include "Observer.h"
#include <iostream>

using namespace std;

void Observer::update(const int& round, const string& pCard, const string& hCard){
    cout << "round" << round << endl;
    cout << "pcard" << pCard << endl;
    cout << "hcard" << hCard << endl;
}

vector<tuple<string, string>> Observer::getPreference(){
    vector<tuple<string, string>> test;
    return test;
}