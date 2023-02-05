#ifndef MINCCCPBOT_HPP
#define MINCCCPBOT_HPP
#include <string>
#include <vector>
#include "../checkInCheck.hpp"
#include "../checkIfMate.hpp"
#include <cstdlib>
#include "minMovesBot.hpp"

std::string minCccpBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color);

#endif