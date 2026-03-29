// main.cpp
#include <iostream>
#include <string>

// Объявления функций из других файлов
#include "random_check_value.h"
#include "argument.h"
#include "rating.h"


int main(int argc, char** argv) {
   // Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

    int secret_number = random_value();
    
    argument(argc, argv);
    
    int attempts = check_value(secret_number); 

    high_scores(attempts, user_name);
    
    return 0;
}

