#include "puzzle.h"

#include <cctype>
#include <set>
#include <string>

namespace aoc {
unsigned long priority_total(std::istream &input) {
	unsigned long total = 0;

	std::set<char> items;
	for (std::string line; std::getline(input, line); items.clear()) {
		std::string::size_type n, mid = line.size() / 2;
		for (std::string::size_type i = 0; i < mid; i++) {
			n = line.find(line[i], mid);
			if (n != std::string::npos) {
				items.insert(line[i]);
			}
		}

		for (const auto &c : items) {
			if (std::islower(c)) {
				total += c - 96;
				continue;
			}

			total += c - 64 + 26;
		}
	}

	return total;
}
} // namespace aoc
