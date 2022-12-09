#include "puzzle.h"

#include <regex>
#include <stack>
#include <string>

namespace aoc {
unsigned long part_1(std::istream &input) {
	unsigned long result = 0;

	const std::regex re{R"(^(\d+).*$)"};
	std::smatch      m;

	const auto limit = 100'000lu;

	std::stack<unsigned long> totals;

	for (std::string line; std::getline(input, line);) {
		if (line.starts_with("$ cd ")) {
			if (line.substr(5, 2) == "..") {
				auto t = totals.top();
				totals.pop();

				if (t <= limit) {
					result += t;
				}

				totals.top() += t;
			} else {
				totals.push(0);
			}

			continue;
		}

		if (line == "$ ls") {
			continue;
		}

		if (!std::regex_match(line, m, re)) {
			continue;
		}

		totals.top() += std::stoul(m[1]);
	}

	unsigned long t = 0;
	while (!totals.empty()) {
		t = totals.top();

		if (t <= limit) {
			result += t;
		}

		totals.pop();
		if (!totals.empty()) {
			totals.top() += t;
		}
	}

	return result;
}
} // namespace aoc
