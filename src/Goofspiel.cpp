#include "Goofspiel.h"
#include <iostream>

using namespace std;

// Constructor for initalizing the croupier, computer, human and the round counter
Goofspiel::Goofspiel(Croupier& croupier, Computer& computer, Human& human) : croupier(croupier), computer(computer), human(human){
    round = 0;
}

// Function to start a new round of game
void Goofspiel::startNewRound(){
    // Increase the round counter
    round++;

    // Ask each one in the game to get a new suit
    croupier.getNewSuit();
    computer.getNewSuit();
    human.getNewSuit();


    // Start the game
    for (int i = 0; i < 13; i++) {

		string pCard = croupier.play();
		cout << "Prize: " << pCard << endl;
		string cCard = computer.play();
		cout << "Computer: " << cCard << endl;
		string hCard = human.play();
		cout << "Human: " << hCard << endl;
	}

    string choice;
    cout << "Do you want to play for another round(yes/no): ";
    cin >> choice;
    if(choice == "yes"){
        startNewRound();
    }else{
        cout << "Bye!!" << endl;
    } 
}