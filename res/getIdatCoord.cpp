#include "getIdatCoord.hpp"

int getIdatCoord(sf::Vector2i coords){

    for(int i = 0; i < chessPieces.size(); i++){
        //std::cout << chessPieces[i].coords.x << "," << chessPieces[i].coords.y<< " | " << coords.x << "," << coords.y << "\n";
        if( (coords.x == chessPieces[i].coords.x) && (coords.y == chessPieces[i].coords.y) ) {return i;}
    }
    return -1;

}