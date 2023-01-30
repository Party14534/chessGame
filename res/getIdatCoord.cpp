#include "getIdatCoord.hpp"

int getIdatCoord(sf::Vector2i coords){

    for(int i = 0; i < chessPieces.size(); i++){
        if(coords.x == chessPieces[i].coords.x && coords.y == chessPieces[i].coords.y) return i;
    }
    return -1;

}