#include "puzzle.h"

#include <map>
#include <regex>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

unsigned long part_2(std::istream &input) {
	const auto total = 70'000'000lu;
	const auto want  = 30'000'000lu;

	const std::regex re{R"(^(\d+).*$)"};
	std::smatch      m;

	std::map<std::string, unsigned long> dirs;
	std::string                          path;

	unsigned long ul = 0;
	for (std::string line; std::getline(input, line);) {
		if (line.starts_with("$ cd ")) {
			if (line.substr(5, 2) == "..") {
				path.erase(path.rfind("/"));
			} else {
				path += "/" + line.substr(5);
			}
		}

		if (!std::regex_match(line, m, re)) {
			continue;
		}

		ul = std::stoul(m[1]);
		for (auto p = path; p.size() > 1; p = p.erase(p.rfind("/"))) {
			dirs[p] += ul;
		}
	}

	const auto min = want - (total - dirs["//"]);

	// Sort dirs by size
	std::vector<std::pair<std::string, unsigned long>> dirz{dirs.begin(), dirs.end()};
	std::sort(dirz.begin(), dirz.end(), [](auto l, auto r) { return l.second < r.second; });

	for (const auto &d : dirz) {
		if (d.second >= min) {
			return d.second;
		}
	}

	return 0;
}
} // namespace aoc
