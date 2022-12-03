#include "puzzle.h"

#include <algorithm>

namespace aoc {
std::vector<unsigned long> calories(std::istream &input) {
	std::vector<unsigned long> result;

	unsigned long count = 0;
	for (std::string line; std::getline(input, line);) {
		if (line.size() == 0) {
			result.push_back(count);
			count = 0;
			continue;
		}

		count += std::stoul(line);
	}

	return result;
}

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

unsigned long total_topn(std::istream &input, std::size_t n) {
	auto calories = aoc::calories(input);

	// sort
	std::sort(calories.begin(), calories.end());

	unsigned long total = 0;
	for (; n > 0 && calories.size() > 0; n--, calories.pop_back()) {
		total += calories.back();
	}

	return total;
}
} // namespace aoc
