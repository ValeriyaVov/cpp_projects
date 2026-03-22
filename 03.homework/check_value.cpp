#include <iostream>

int check_value(int target_value) {

	int current_value = 0;
	bool not_win = true;
	int attempts = 0;

	std::cout << "Guess a number from 1 to 100" << std::endl;

	std::cout << "Enter your guess:" << std::endl;

	while (not_win) {
		std::cin >> current_value;
		attempts++;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! You guessed in " << attempts << " attempts" << std::endl;
			not_win = false;
			
		}

	}

	return attempts;
}