cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(homework
	main.cpp
	game_result.cpp
	random_value.cpp
	argument.cpp
	check_value.cpp
	high_scores.cpp
)

set_target_properties(homework PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

