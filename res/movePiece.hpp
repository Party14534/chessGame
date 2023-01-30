#ifndef PIECEMOVE_HPP
#define PIECEMOVE_HPP

#include <math.h>
#include "chessPiece.hpp"
#include "drawChessBoard.hpp"
#include "redrawBoard.hpp"
#include "checkInCheck.hpp"
#include "getIdatCoord.hpp"
#include "checkNotCheck.hpp"

void movePiece(std::vector<std::vector<char>> &board, std::vector<std::string>& allValidMoves, int clickedId, int boardId, int prevId, int &roundCheck);


#endif