// main.cpp
#include <iostream>
#include <fstream>
#include <string>

int high_scores(int attempts_count, const std::string& user_name) {
    const std::string high_scores_filename = "high_scores.txt";

    // Write new high score to the records table
    {
        std::ofstream out_file{high_scores_filename, std::ios_base::app};
        if (!out_file.is_open()) {
            std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
            return -1;
        }

        out_file << user_name << ' ';
        out_file << attempts_count;
        out_file << std::endl;
        
        std::cout << "Результат сохранён! " << user_name << " - " << attempts_count << " попыток" << std::endl;
    }

    // Read the high score file and print all results
    {
        std::ifstream in_file{high_scores_filename};
        if (!in_file.is_open()) {
            std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
            return -1;
        }

        std::cout << "\n=== Таблица рекордов ===" << std::endl;
        std::cout << "Имя\t\tПопытки" << std::endl;
        std::cout << "-------------------" << std::endl;

        std::string username;
        int high_score = 0;
        while (in_file >> username >> high_score) {
            std::cout << username << "\t\t" << high_score << std::endl;
        }
    }

    return 0;
}