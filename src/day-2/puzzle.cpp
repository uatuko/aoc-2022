#include "puzzle.h"

#include <numeric>

namespace aoc {
unsigned long strategy_score(std::istream &input) {
	auto scores = strategy_scores(input);
	return std::accumulate(scores.begin(), scores.end(), 0);
}

std::vector<unsigned short> strategy_scores(std::istream &input) {
	std::vector<unsigned short> scores;

	unsigned short score = 0;
	for (std::string line; std::getline(input, line); score = 0) {
		if (line.size() != 3) {
			continue;
		}

		// Optimistically assuming input will only have A, B or C for first char and X, Y or Z for
		// 3rd char
		score += line[2] - 87; // score based on response shape

		auto diff = (line[0] - 65) - (line[2] - 88);
		switch ((line[0] - 65) - (line[2] - 88)) {
		case -1:
		case 2:
			// Win
			score += 6;
			break;
		case 0:
			// Draw
			score += 3;
			break;
		default: // -2, 1, 2
			// Lose
			break;
		}

		scores.push_back(score);
	}

	return scores;
}
} // namespace aoc
