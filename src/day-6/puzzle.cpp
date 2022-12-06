#include "puzzle.h"

#include <set>
#include <string>

namespace aoc {
unsigned long part_1(std::istream &input) {
	std::string data;
	std::getline(input, data);

	unsigned long  result = 0;
	std::set<char> marker;
	for (unsigned long pos = 0; pos < data.size(); pos++) {
		for (char c : data.substr(pos, 4)) {
			marker.insert(c);
		}

		if (marker.size() == 4) {
			// Found start of message marker
			result = pos + 4;
			break;
		}

		marker.clear();
	}

	return result;
}
} // namespace aoc
