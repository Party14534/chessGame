#ifndef CHECK_HPP
#define CHECK_HPP

#include "chessPiece.hpp"
#include "generateDangerMaps.hpp"

inline bool whiteInCheck = false;
inline bool blackInCheck = true;

void checkInCheck(std::vector<std::vector<char>> &board, int which);

#endif