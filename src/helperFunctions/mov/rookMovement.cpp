#include "rookMovement.hpp"

void whiteRookMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    //Eastward movement
    for(int i = 1; i < 8; i++){
        if(coords.x + i <= 7){
            if(boardState[coords.y][coords.x + i] == '\0' || !isupper(boardState[coords.y][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y][coords.x + i]) && 
                boardState[coords.y][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }
    //Westward movement
    for(int i = 1; i < 8; i++){
        if(coords.x - i >= 0){
            if(boardState[coords.y][coords.x - i] == '\0' || !isupper(boardState[coords.y][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y][coords.x - i]) && 
                boardState[coords.y][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    //South movement
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7){
            if(boardState[coords.y + i][coords.x] == '\0' || !isupper(boardState[coords.y + i][coords.x])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y + i][coords.x]) && 
                boardState[coords.y + i][coords.x] != '\0') break;
            } else break;
        } else break;
    }
    //North movement
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0){
            if(boardState[coords.y - i][coords.x] == '\0' || !isupper(boardState[coords.y - i][coords.x])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(!isupper(boardState[coords.y - i][coords.x]) && 
                boardState[coords.y - i][coords.x] != '\0') break;
            } else break;
        } else break;
    }

}



void blackRookMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    //Eastward movement
    for(int i = 1; i < 8; i++){
        if(coords.x + i <= 7){
            if(boardState[coords.y][coords.x + i] == '\0' || isupper(boardState[coords.y][coords.x + i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x + i) + '0';
                stringCoords[3] = char(coords.y) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y][coords.x + i]) && 
                boardState[coords.y][coords.x + i] != '\0') break;
            } else break;
        } else break;
    }
    //Westward movement
    for(int i = 1; i < 8; i++){
        if(coords.x - i >= 0){
            if(boardState[coords.y][coords.x - i] == '\0' || isupper(boardState[coords.y][coords.x - i])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x - i) + '0';
                stringCoords[3] = char(coords.y) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y][coords.x - i]) && 
                boardState[coords.y][coords.x - i] != '\0') break;
            } else break;
        } else break;
    }
    //South movement
    for(int i = 1; i < 8; i++){
        if(coords.y + i <= 7){
            if(boardState[coords.y + i][coords.x] == '\0' || isupper(boardState[coords.y + i][coords.x])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y + i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y + i][coords.x]) && 
                boardState[coords.y + i][coords.x] != '\0') break;
            } else break;
        } else break;
    }
    //North movement
    for(int i = 1; i < 8; i++){
        if(coords.y - i >= 0){
            if(boardState[coords.y - i][coords.x] == '\0' || isupper(boardState[coords.y - i][coords.x])){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x) + '0';
                stringCoords[3] = char(coords.y - i) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
                if(isupper(boardState[coords.y - i][coords.x]) && 
                boardState[coords.y - i][coords.x] != '\0') break;
            } else break;
        } else break;
    }

}