#pragma once

#include <istream>
#include <vector>

namespace aoc {
std::vector<unsigned long> calories(std::istream &input);

unsigned long most_calories(std::istream &input);

unsigned long total_topn(std::istream &input, std::size_t n);
} // namespace aoc
