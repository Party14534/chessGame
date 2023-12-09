#ifndef CHECKNOT_HPP
#define CHECKNOT_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include "chessPiece.hpp"
#include "generateDangerMaps.hpp"
#include "checkInCheck.hpp"
#include "getIdatCoord.hpp"

bool checkNotCheck(std::vector<std::vector<char>> board, int id, sf::Vector2i prevCoords, sf::Vector2i newCoords);

#endif