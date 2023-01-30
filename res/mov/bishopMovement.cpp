#include "bishopMovement.hpp"

void whiteBishopMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0 && coords.x - i >= 0){
            if(boardState[coords.y - i][coords.x - i] == '\0' || !isupper(boardState[coords.y - i][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y - i][coords.x - i]) && 
                boardState[coords.y - i][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0 && coords.x + i <= 7){
            if(boardState[coords.y - i][coords.x + i] == '\0' || !isupper(boardState[coords.y - i][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y - i][coords.x + i]) && 
                boardState[coords.y - i][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7 && coords.x - i >= 0){
            if(boardState[coords.y + i][coords.x - i] == '\0' || !isupper(boardState[coords.y + i][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y + i][coords.x - i]) && 
                boardState[coords.y + i][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7 && coords.x + i <= 7){
            if(boardState[coords.y + i][coords.x + i] == '\0' || !isupper(boardState[coords.y + i][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y + i][coords.x + i]) && 
                boardState[coords.y + i][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }

}



void blackBishopMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0 && coords.x - i >= 0){
            if(boardState[coords.y - i][coords.x - i] == '\0' || isupper(boardState[coords.y - i][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y - i][coords.x - i]) && 
                boardState[coords.y - i][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0 && coords.x + i <= 7){
            if(boardState[coords.y - i][coords.x + i] == '\0' || isupper(boardState[coords.y - i][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y - i][coords.x + i]) && 
                boardState[coords.y - i][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7 && coords.x - i >= 0){
            if(boardState[coords.y + i][coords.x - i] == '\0' || isupper(boardState[coords.y + i][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y + i][coords.x - i]) && 
                boardState[coords.y + i][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7 && coords.x + i <= 7){
            if(boardState[coords.y + i][coords.x + i] == '\0' || isupper(boardState[coords.y + i][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y + i][coords.x + i]) && 
                boardState[coords.y + i][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }

}