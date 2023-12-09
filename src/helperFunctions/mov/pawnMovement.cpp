#include "pawnMovement.hpp"

//Chess piece movement
//Pawn Movement
void whitePawnMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    if(coords.y != 0){
        if(boardState[coords.y-1][coords.x] == '\0') {
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x) + '0';
            stringCoords[3] = char(coords.y-1) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);

        }
    
        if(coords.y == 6){
            if (boardState[coords.y-2][coords.x] == '\0' && (boardState[coords.y-1][coords.x] == '\0')){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y-2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

            }
        }
        if(coords.x != 7){
            if(!(isupper(boardState[coords.y-1][coords.x+1])) && boardState[coords.y-1][coords.x+1] != '\0'){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

            }
        }
        if(coords.x != 0){
            if(!(isupper(boardState[coords.y-1][coords.x-1])) && boardState[coords.y-1][coords.x-1] != '\0'){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

            }
        }
    }

    //Passant
    if(coords.x < 7){
        if(boardState[coords.y][coords.x+1] == 'p' && boardState[coords.y - 1][coords.x+1] == '\0'){
            if((coords.x+1 == justPassant.x) && (coords.y == justPassant.y)){
                std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x+1) + '0';
                    stringCoords[3] = char(coords.y-1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x > 0){
        if(boardState[coords.y][coords.x-1] == 'p' && boardState[coords.y - 1][coords.x-1] == '\0'){
            if((coords.x-1 == justPassant.x) && (coords.y == justPassant.y)){
                std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x-1) + '0';
                    stringCoords[3] = char(coords.y-1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }

}

void blackPawnMove(std::vector<std::vector<char>> boardState, int id){

        sf::Vector2i coords = chessPieces[id].coords;
        if(coords.y != 7){
            if(boardState[coords.y+1][coords.x] == '\0') {
                
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

            }
            if(coords.y == 1){
                if (boardState[coords.y+2][coords.x] == '\0' && (boardState[coords.y+1][coords.x] == '\0')){

                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x) + '0';
                    stringCoords[3] = char(coords.y+2) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);

                }
            }
            if(coords.x != 7){
                if((isupper(boardState[coords.y+1][coords.x+1])) && boardState[coords.y+1][coords.x+1] != '\0'){

                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x+1) + '0';
                    stringCoords[3] = char(coords.y+1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);

                }
            }
            if(coords.x != 0){
                if((isupper(boardState[coords.y+1][coords.x-1])) && boardState[coords.y+1][coords.x-1] != '\0'){

                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x-1) + '0';
                    stringCoords[3] = char(coords.y+1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);

                }
            }
        }

        //Passant
    if(coords.x < 7){
        if(boardState[coords.y][coords.x+1] == 'P' && boardState[coords.y + 1][coords.x+1] == '\0'){
            if((coords.x+1 == justPassant.x) && (coords.y == justPassant.y)){
                std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x+1) + '0';
                    stringCoords[3] = char(coords.y+1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x > 0){
        if(boardState[coords.y][coords.x-1] == 'P' && boardState[coords.y + 1][coords.x-1] == '\0'){
            if((coords.x-1 == justPassant.x) && (coords.y == justPassant.y)){
                std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x-1) + '0';
                    stringCoords[3] = char(coords.y+1) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }

}