#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Strategy.h"

using namespace std;

int main() {

	// Set the seed
	srand(unsigned(time(NULL)));

	// Initilaize a croupier in the game
	Croupier croupier;

	for (int i = 0; i < 13; i++) {
		string card = croupier.play();
		cout << card << endl;
	}


	return 0;
}