#include "puzzle.h"

namespace aoc {
unsigned long most_calories(std::istream &input) {
	unsigned long max = 0;

	unsigned long count = 0;
	for (std::string line; std::getline(input, line);) {
		if (line.size() == 0) {
			if (count > max) {
				max = count;
			}

			count = 0;
			continue;
		}

		count += std::stoul(line);
	}

	return max;
}
} // namespace aoc
