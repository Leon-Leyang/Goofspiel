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
	// Function to update the recordMatrix
	void update(const int& round, const std::string& pCard, const std::string& hCard);

	// Function to create a new Row and push it to the back of the recordMatrix
	void create();

	// Function to calculate user's preference play for specific prize card
	Row getPreference();

private:
	// The Matrix to record user's plays each round
    Matrix recordMatrix;
};