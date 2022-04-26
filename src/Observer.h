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
	void update(const int& round, const std::string& pCard, const std::string& hCard);
	void create();
	std::vector<std::tuple<std::string, std::string>> getPreference();
private:
    Matrix recordMatrix;
};