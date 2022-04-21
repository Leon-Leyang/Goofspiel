#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Strategy.h"

using namespace std;

int main() {

	Croupier croupier;
	for (int i = 0; i < 13; i++) {
		croupier.play();
	}


	return 0;
}