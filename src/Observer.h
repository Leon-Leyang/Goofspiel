#include <tuple>
#include <vector>
#include <string>

// Define Matrix to be a 2d vector of int
typedef std::vector< std::vector<std::string> > Matrix;
// Define Row to be a vector of int
typedef std::vector<std::string> Row;

class Observer {
public:
	void update(const int& round, const std::string& pCard, const std::string& hCard);
	void create();
	std::vector<std::tuple<std::string, std::string>> getPreference();
private:
    Matrix recordMatrix;
};