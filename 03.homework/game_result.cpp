// main.cpp
#include <iostream>
#include <windows.h>
#include <string>

// Объявления функций из других файлов
int random_value();
int argument(int argc, char** argv);
int check_value(int target_value);
int high_scores(int attempts_count, const std::string& user_name);

int main(int argc, char** argv) {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

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

