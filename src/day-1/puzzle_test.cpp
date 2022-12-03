#include <filesystem>
#include <fstream>
#include <memory>

#include <gtest/gtest.h>

#include "puzzle.h"

class PuzzleTest : public ::testing::Test {
protected:
	static void SetUpTestSuite() {
		auto fname = std::filesystem::path(TESTDATA_PATH) / "input.txt";
		auto size  = std::filesystem::file_size(fname);
		input      = std::make_unique<std::ifstream>(fname, std::ios::in);
	}

	static std::unique_ptr<std::ifstream> input;
};

std::unique_ptr<std::ifstream> PuzzleTest::input = nullptr;

TEST_F(PuzzleTest, most_calories) {
	auto actual = aoc::most_calories(*PuzzleTest::input);
	EXPECT_EQ(66186, actual);
}
