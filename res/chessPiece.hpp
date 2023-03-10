#ifndef PIECE_HPP
#define PIECE_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctype.h>
#include "drawChessBoard.hpp"
#include "checkNotCheck.hpp"
#include "mov/pawnMovement.hpp"
#include "mov/knightMovement.hpp"
#include "mov/queenMovement.hpp"
#include "mov/bishopMovement.hpp"
#include "mov/rookMovement.hpp"
#include "mov/kingMovement.hpp"
#include "loadTextures.hpp"
#include "Collision.hpp"

class chessPiece;
inline sf::Vector2i justPassant = {-1,-1};
inline std::vector<chessPiece> chessPieces;
inline sf::Font font;

class chessPiece{

    public: 
        sf::Vector2i coords;
        sf::Sprite sprite;
        std::vector<std::string> validMoves;
        char type;
        bool hovered = false;
        bool clicked = false;
        bool hasMoved = false;
        int id;

        chessPiece(char initType, sf::Vector2i initCoords, bool newHasMoved);
        void getValidMoves(std::vector<std::vector<char>> boardState);
        void getPawnDanger(std::vector<std::vector<char>> boardState, int id);

};


#endif