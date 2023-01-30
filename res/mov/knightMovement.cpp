#include "knightMovement.hpp"

//White Knight movement
void whiteKnightMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    if(coords.y >= 2){
        if(coords.x < 7){
            if(!(isupper(boardState[coords.y-2][coords.x+1])) || boardState[coords.y-2][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.x > 0){
            if(!(isupper(boardState[coords.y-2][coords.x-1])) || boardState[coords.y-2][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.y <= 5){
        if(coords.x < 7){
            if(!(isupper(boardState[coords.y+2][coords.x+1])) || boardState[coords.y+2][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y+2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.x > 0){
            if(!(isupper(boardState[coords.y+2][coords.x-1])) || boardState[coords.y+2][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y+2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }


    if(coords.x >= 2){
        if(coords.y < 7){
            if(!(isupper(boardState[coords.y+1][coords.x-2])) || boardState[coords.y+1][coords.x-2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-2) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y > 0){
            if(!(isupper(boardState[coords.y-1][coords.x-2])) || boardState[coords.y-1][coords.x-2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-2) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x <= 5){
        if(coords.y < 7){
            if(!(isupper(boardState[coords.y+1][coords.x+2])) || boardState[coords.y+1][coords.x+2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+2) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y > 0){
            if(!(isupper(boardState[coords.y-1][coords.x+2])) || boardState[coords.y-1][coords.x+2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+2) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }

}



//Black knight movement
void blackKnightMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    if(coords.y >= 2){
        if(coords.x < 7){
            if((isupper(boardState[coords.y-2][coords.x+1])) || boardState[coords.y-2][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.x > 0){
            if((isupper(boardState[coords.y-2][coords.x-1])) || boardState[coords.y-2][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.y <= 5){
        if(coords.x < 7){
            if((isupper(boardState[coords.y+2][coords.x+1])) || boardState[coords.y+2][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y+2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.x > 0){
            if((isupper(boardState[coords.y+2][coords.x-1])) || boardState[coords.y+2][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y+2) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }


    if(coords.x >= 2){
        if(coords.y < 7){
            if((isupper(boardState[coords.y+1][coords.x-2])) || boardState[coords.y+1][coords.x-2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-2) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y > 0){
            if((isupper(boardState[coords.y-1][coords.x-2])) || boardState[coords.y-1][coords.x-2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-2) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x <= 5){
        if(coords.y < 7){
            if((isupper(boardState[coords.y+1][coords.x+2])) || boardState[coords.y+1][coords.x+2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+2) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y > 0){
            if((isupper(boardState[coords.y-1][coords.x+2])) || boardState[coords.y-1][coords.x+2] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+2) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }

}