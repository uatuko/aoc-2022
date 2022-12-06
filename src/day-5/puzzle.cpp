#include "puzzle.h"

#include <array>
#include <regex>
#include <stack>

namespace aoc {
std::string part_1(std::istream &input) {
	std::array<std::stack<char>, 9> stacks;

	// Parse stacks
	for (std::string line; std::getline(input, line);) {
		if (line.size() == 0) {
			break;
		}

		for (std::size_t i = 0; i < stacks.size(); i++) {
			if (line[i] == ' ') {
				continue;
			}

			stacks[i].push(line[i]);
		}
	}

	// Parse instructions
	const std::regex re{R"(^move (\d+) from (\d+) to (\d+)$)"};
	std::smatch      m;
	for (std::string line; std::getline(input, line);) {
		std::regex_match(line, m, re);

		auto from = std::stoi(m[2]) - 1;
		auto to   = std::stoi(m[3]) - 1;
		for (auto count = std::stoi(m[1]); count > 0; count--) {
			stacks[to].push(stacks[from].top());
			stacks[from].pop();
		}
	}

	std::string result;
	for (const auto &stack: stacks) {
		result += stack.top();
	}

	return result;
}
} // namespace aoc
