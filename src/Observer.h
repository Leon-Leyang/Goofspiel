#include <tuple>
#include <vector>

// Define Matrix to be a 2d vector of int
typedef std::vector< std::vector<int> > Matrix;
// Define Row to be a vector of int
typedef std::vector<int> Row;

class Observer {
public:
	void update(const int& round, const std::string& pCard, const std::string& hCard);
	std::vector<std::tuple<std::string, std::string>> getPreference();
private:
    Matrix recordMatrix;
};