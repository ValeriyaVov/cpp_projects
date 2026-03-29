#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

#ifndef GAME_RESULT_H
#define GAME_RESULT_H

#include <string>

int high_scores(int attempts_count, const std::string& user_name);
int game_result(int argc, char** argv);

#endif
#endif