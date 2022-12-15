#include "puzzle.h"

#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

struct monkey {
	std::queue<long>          items;
	std::pair<char, int>      op;
	std::tuple<int, int, int> test;
	int                       activity{};

	/*
	 * Input sample:
	 * ```
	 * Monkey 0:
	 *   Starting items: 79, 98
	 *   Operation: new = old * 19
	 *   Test: divisible by 23
	 *     If true: throw to monkey 2
	 *     If false: throw to monkey 3
	 * ```
	 */
	monkey(std::vector<std::string> data) {
		// Items
		{
			std::size_t pos = 17;
			std::size_t n{};

			while (pos < data[1].size()) {
				auto item = std::stol(data[1].substr(pos), &n);
				items.push(item);

				pos += n + 2;
			}
		}

		// Operation
		{
			int n = -1;
			if (data[2].substr(25) != "old") {
				n = std::stoi(data[2].substr(25));
			}

			op = {data[2][23], n};
		}

		// Test
		{
			int n   = std::stoi(data[3].substr(21));
			int yes = std::stoi(data[4].substr(29));
			int no  = std::stoi(data[5].substr(30));

			test = {n, yes, no};
		}
	}
};

namespace aoc {
unsigned long part_1(std::istream &input) {
	std::vector<monkey> monkeys;

	std::vector<std::string> data;
	for (std::string line; std::getline(input, line);) {
		data.push_back(line);

		if (line.size() == 0) {
			monkeys.push_back({data});
			data.clear();
		}
	}

	if (!data.empty()) {
		monkeys.push_back({data});
	}

	long item;
	for (auto i = 0; i < 20; i++) {
		for (auto &m : monkeys) {
			while (!m.items.empty()) {
				m.activity++;
				item = m.items.front();
				m.items.pop();

				switch (m.op.first) {
				case '*':
					item *= m.op.second > 0 ? m.op.second : item;
					break;
				case '+':
					item += m.op.second > 0 ? m.op.second : item;
					break;
				}

				item = std::roundl(item / 3);

				auto [n, yes, no] = m.test;
				if (item % n == 0) {
					monkeys[yes].items.push(item);
				} else {
					monkeys[no].items.push(item);
				}
			}
		}
	}

	// Sort (desc)
	std::sort(monkeys.begin(), monkeys.end(), [](const monkey &left, const monkey &right) -> bool {
		return left.activity > right.activity;
	});

	return (monkeys[0].activity * monkeys[1].activity);
}
} // namespace aoc
