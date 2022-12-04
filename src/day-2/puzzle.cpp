#include "puzzle.h"

namespace aoc {
unsigned long strategy_score(std::istream &input) {
	unsigned long total = 0;

	unsigned short score = 0;
	for (std::string line; std::getline(input, line); score = 0) {
		score += (line[2] - 88) * 3; // score based on the outcome

		switch (line[2]) {
		case 'X':
			// Lose
			switch (line[0]) {
			case 'A':
				score += 3; // response is scissors
				break;
			case 'B':
				score += 1; // response is rock
				break;
			case 'C':
				score += 2; // response is paper
				break;
			}

			break;

		case 'Y':
			// Draw, response is the same as opponent
			score += line[0] - 64;
			break;

		case 'Z':
			// Win
			switch (line[0]) {
			case 'A':
				score += 2; // response is paper
				break;
			case 'B':
				score += 3; // response is scissors
				break;
			case 'C':
				score += 1; // response is rock
				break;
			}

			break;
		}

		total += score;
	}

	return total;
}

unsigned long strategy_score_predicted(std::istream &input) {
	unsigned long total = 0;

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

		total += score;
	}

	return total;
}
} // namespace aoc
