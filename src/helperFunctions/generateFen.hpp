#ifndef FENGEN_HPP
#define FENGEN_HPP
#include <string>
#include <vector>
#include "chessPiece.hpp"
#include "getIdatCoord.hpp"

inline std::string boardFen = "8/8/8/8/8/8/8/8 w KQkq - 0 1";

void generateFen(std::vector<std::vector<char>> board, int turn, int halfMove, int roundCount);

#endif