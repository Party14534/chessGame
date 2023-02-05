#ifndef MINMOVESBOT_HPP
#define MINMOVESBOT_HPP
#include <string>
#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../chessPiece.hpp"

std::string minBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color);

#endif