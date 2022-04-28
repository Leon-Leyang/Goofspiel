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

    // Let each character in the game to get a new suit
    croupier.getNewSuit();
    computer.getNewSuit();
    human.getNewSuit();

    // Let the croupier initialize the scoring map
    croupier.initScoringMap();

    // Let the computer learn from user's previous play
    computer.learn();

    // Let the computer start a new round of observation
    computer.startNewObserve();

    // Start the game
    for (int i = 0; i < 13; i++) {
        cout << "\n--------------------------------------------------------------\n" << endl;
		string pCard = croupier.play();
		cout << "The prize for this round is: " << pCard << endl;

        computer.observe(pCard);

		string cCard = computer.play();
		
		string hCard = human.play();

        // Let the croupier evaluate this round
        croupier.evaluate(pCard, cCard, hCard);

        // Let the computer observe user's playing pattern and left hand
        computer.observe(getRound(), pCard, hCard);
	}

    // Let the croupier evalute this game
    croupier.evaluate();

    startAnotherRound();
}

void Goofspiel::startAnotherRound(){
    string choice;
    cout << "\n--------------------------------------------------------------\n" << endl;
    cout << "Do you want to play again(yes/no): ";
    cin >> choice;
    if(choice == "yes"){
        startNewRound();
    }else{
        cout << "\nBye!!" << endl;
    } 
}

int Goofspiel::getRound(){
    return round;
}