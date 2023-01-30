#ifndef CCCP_HPP
#define CCCP_HPP
#include <string>
#include <vector>
#include "../checkInCheck.hpp"
#include "../checkIfMate.hpp"
#include <cstdlib>

std::string cccpBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color);

#endif