#include "puzzle.h"

#include <string>
#include <utility>

namespace aoc {
unsigned long part_1(std::istream &input) {
	unsigned long result = 0;

	std::string::size_type              n;
	std::pair<std::string, std::string> pair;
	std::pair<int, int>                 left;
	std::pair<int, int>                 right;
	for (std::string line; std::getline(input, line);) {
		n = line.find(",");
		if (n == std::string::npos) {
			continue;
		}

		pair = std::make_pair(line.substr(0, n), line.substr(n + 1));

		n = pair.first.find("-");
		if (n == std::string::npos) {
			continue;
		}

		left =
			std::make_pair(std::stoi(pair.first.substr(0, n)), std::stoi(pair.first.substr(n + 1)));

		n = pair.second.find("-");
		if (n == std::string::npos) {
			continue;
		}

		right = std::make_pair(
			std::stoi(pair.second.substr(0, n)), std::stoi(pair.second.substr(n + 1)));

		if ((left.first <= right.first && left.second >= right.second) ||
			(right.first <= left.first && right.second >= left.second)) {
			result++;
		}
	}

	return result;
}
} // namespace aoc
