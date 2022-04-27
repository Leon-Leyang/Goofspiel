#include <tuple>
#include <vector>
#include <string>
#include <map>

// Define Matrix to be a vector of map from string to string
typedef std::vector< std::map<std::string, std::string> > Matrix;

// Define Row to be a map from string to string
typedef std::map<std::string, std::string> Row;

class Observer {
public:
	// Function to update the recordMatrix, the preference and left cards in user's hand
	void update(const int& round, const std::string& pCard, const std::string& hCard);

	// Function to create a new Row, push it to the back of the recordMatrix and renew the left cards in user's hand
	void create();

	// Function to calculate user's preference
	void calc();

	// Function to calculate the Row whose key is the prize card and value is user's card that is used most frequently to bid this prize card
	Row calcHCard4PCard();

	// Function to calculate the Row whose key is the user's card and value is the prize card that is most frequently being bid by this card
	Row calcPCard4HCard();

	// Function to calculate user's preference play for specific prize card
	Row getPreference();

	// Getter and setter for the pCard
	std::string getPCard();
	void setPCard(std::string PCard);

	// Getter for the hCards
	std::vector<std::string> getHCards();

private:
	// The Matrix to record user's plays each round
    Matrix recordMatrix;

	// The Row of user's preference
	Row preference;

	// The prize card this round
	std::string pCard;

	// The vector to record left cards in user's hand
	std::vector<std::string> hCards;
};