add_library(day-4 OBJECT
	puzzle.cpp
	puzzle.h
)

# tests
add_executable(${PROJECT_NAME}_day-4_tests
	puzzle_test.cpp
)

cmake_path(SET testdata_path ${CMAKE_CURRENT_SOURCE_DIR}/testdata)
target_compile_definitions(${PROJECT_NAME}_day-4_tests
	PRIVATE TESTDATA_PATH="${testdata_path}"
)

target_link_libraries(${PROJECT_NAME}_day-4_tests
	PRIVATE
		day-4
		gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_day-4_tests)

