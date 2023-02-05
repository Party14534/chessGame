#ifndef BOTMOV_HPP
#define BOTMOV_HPP
#include <vector>
#include <string>
#include "randomBot.hpp"
#include "cccpBot.hpp"
#include "minMovesBot.hpp"
#include "minCccpBot.hpp"

std::string moveBot(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color, int choice);

#endif