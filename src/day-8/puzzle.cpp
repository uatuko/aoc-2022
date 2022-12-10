#include "puzzle.h"

#include <set>
#include <string>
#include <vector>

namespace aoc {
unsigned long part_1(std::istream &input) {
	std::set<std::string>    visible;
	std::vector<std::string> grid;

	int pos;
	for (std::string line; std::getline(input, line);) {
		grid.push_back(line);

		for (auto x = 0; x < line.size(); x++) {
			if (x == 0 || x == line.size() - 1) {
				// Visible (edges)
				visible.insert(std::to_string(x) + "," + std::to_string(grid.size() - 1));
				continue;
			}

			for (pos = x - 1; pos >= 0; pos--) {
				if (line[pos] >= line[x]) {
					// Breaks visibility from left
					break;
				}
			}

			if (pos < 0) {
				// Visible from left
				visible.insert(std::to_string(x) + "," + std::to_string(grid.size() - 1));
				continue;
			}

			for (pos = x + 1; pos < line.size(); pos++) {
				if (line[pos] >= line[x]) {
					// Breaks visibility from right
					break;
				}
			}

			if (pos == line.size()) {
				// Visible from right
				visible.insert(std::to_string(x) + "," + std::to_string(grid.size() - 1));
				continue;
			}

			for (pos = grid.size() - 2; pos >= 0; pos--) {
				if (grid[pos][x] >= line[x]) {
					// Breaks visibility from top
					break;
				}
			}

			if (pos < 0) {
				// Visible from top
				visible.insert(std::to_string(x) + "," + std::to_string(grid.size() - 1));
				continue;
			}
		}
	}

	for (auto y = 0; y < grid.size(); y++) {
		for (auto x = 0; x < grid[y].size(); x++) {
			if (y == 0 || y == grid.size() - 1) {
				// Visible (edges)
				visible.insert(std::to_string(x) + "," + std::to_string(y));
				continue;
			}

			for (pos = y + 1; pos < grid.size(); pos++) {
				if (grid[pos][x] >= grid[y][x]) {
					// Breaks visibility from bottom
					break;
				}
			}

			if (pos == grid.size()) {
				// Visible from bottom
				visible.insert(std::to_string(x) + "," + std::to_string(y));
			}
		}
	}

	// Print
	for (auto y = 0; y < grid.size(); y++) {
		auto line = grid[y];

		for (auto x = 0; x < line.size(); x++) {
			if (visible.count(std::to_string(x) + "," + std::to_string(y)) != 0) {
				std::printf("%c", grid[y][x]);
			} else {
				std::printf("-");
			}
		}

		std::printf("\n");
	}

	return visible.size();
}

unsigned long part_2(std::istream &input) {
	std::set<unsigned long>  scores;
	std::vector<std::string> grid;

	for (std::string line; std::getline(input, line);) {
		grid.push_back(line);
	}

	unsigned long score;
	int           pos;
	for (auto y = 0; y < grid.size(); y++) {
		for (auto x = 0, score = 1; x < grid[y].size(); x++, score = 1) {
			for (pos = x + 1; pos < grid[y].size(); pos++) {
				if (grid[y][pos] >= grid[y][x]) {
					break;
				}
			}

			if (pos == grid[y].size()) {
				pos--;
			}
			score *= (pos - x); // right

			for (pos = y + 1; pos < grid.size(); pos++) {
				if (grid[pos][x] >= grid[y][x]) {
					break;
				}
			}

			if (pos == grid.size()) {
				pos--;
			}
			score *= (pos - y); // bottom

			for (pos = x - 1; pos >= 0; pos--) {
				if (grid[y][pos] >= grid[y][x]) {
					break;
				}
			}

			if (pos < 0) {
				pos = 0;
			}
			score *= (x - pos); // left

			for (pos = y - 1; pos >= 0; pos--) {
				if (grid[pos][x] >= grid[y][x]) {
					break;
				}
			}

			if (pos < 0) {
				pos = 0;
			}
			score *= (y - pos); // top

			scores.insert(score);
		}
	}

	return *scores.rbegin();
}
} // namespace aoc
