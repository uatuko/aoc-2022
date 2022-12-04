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

	void SetUp() override {
		input->clear();
		input->seekg(0, std::ios::beg);
	}

	static std::unique_ptr<std::ifstream> input;
};

std::unique_ptr<std::ifstream> PuzzleTest::input = nullptr;

TEST_F(PuzzleTest, strategy_score_predicted) {
	auto actual = aoc::strategy_score_predicted(*PuzzleTest::input);
	EXPECT_EQ(8890, actual);
}

TEST_F(PuzzleTest, strategy_score) {
	auto actual = aoc::strategy_score(*PuzzleTest::input);
	EXPECT_EQ(10238, actual);
}
