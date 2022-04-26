#include "Character.h"

class Goofspiel{
public:
    // Constructor
    Goofspiel(Croupier& croupier, Computer& computer, Human& human);
    // Function to start a new round of game
    void startNewRound();
private:
    int round;
    Croupier& croupier;
    Computer& computer;
    Human& human;
};