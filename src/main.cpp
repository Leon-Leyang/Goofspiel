#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Strategy.h"
#include "Goofspiel.h"

using namespace std;



int main() {

	// Set the seed
	srand(unsigned(time(NULL)));

	// Initilaize a croupier, a computer and a human in the game
	Croupier croupier;
	Computer computer;
	Human human;



	// Initialize the game
	Goofspiel goofspiel(croupier, computer, human);

	goofspiel.startNewRound();



	return 0;
}