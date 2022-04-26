#include "Character.h"

class Goofspiel{
public:
    // Constructor
    Goofspiel(Croupier& croupier, Computer& computer, Human& human);

    // Function to start a new round of game
    void startNewRound();

    // Function to start another round of game if user wants to
    void startAnotherRound();

    // Function to get the round number
    int getRound();
private:
    int round;
    Croupier& croupier;
    Computer& computer;
    Human& human;
};