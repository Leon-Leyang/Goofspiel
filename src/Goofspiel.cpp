#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Strategy.h"

using namespace std;

int main() {

	// Set the seed
	srand(unsigned(time(NULL)));

	// Initilaize a croupier, a computer and a human in the game
	Croupier croupier;
	Computer computer;
	Human human;

	for (int i = 0; i < 13; i++) {
		string pCard = croupier.play();
		cout << "Prize: " << pCard << endl;
		string cCard = computer.play();
		cout << "Computer: " << cCard << endl;
		string hCard = human.play();
		cout << "Human: " << hCard << endl;
	}


	return 0;
}