#include "kingMovement.hpp"

void whiteKingMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    //North Movement
    if(coords.y > 0){
        if(!(isupper(boardState[coords.y-1][coords.x])) || boardState[coords.y-1][coords.x] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x) + '0';
            stringCoords[3] = char(coords.y-1) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //South Movement
    if(coords.y < 7){
        if(!(isupper(boardState[coords.y+1][coords.x])) || boardState[coords.y+1][coords.x] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x) + '0';
            stringCoords[3] = char(coords.y+1) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //East Movement
    if(coords.x < 7){
        if(!(isupper(boardState[coords.y][coords.x+1])) || boardState[coords.y][coords.x+1] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x+1) + '0';
            stringCoords[3] = char(coords.y) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //West Movement
    if(coords.x > 0){
        if(!(isupper(boardState[coords.y][coords.x-1])) || boardState[coords.y][coords.x-1] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x-1) + '0';
            stringCoords[3] = char(coords.y) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //Diagonal Movement
    if(coords.x > 0){
        if(coords.y > 0){
            if(!(isupper(boardState[coords.y-1][coords.x-1])) || boardState[coords.y-1][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y < 7){
            if(!(isupper(boardState[coords.y+1][coords.x-1])) || boardState[coords.y+1][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x < 7){
        if(coords.y > 0){
            if(!(isupper(boardState[coords.y-1][coords.x+1])) || boardState[coords.y-1][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y < 7){
            if(!(isupper(boardState[coords.y+1][coords.x+1])) || boardState[coords.y+1][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    //Castling
    int rookId = getIdatCoord({7,7});
    if(rookId != -1 && (chessPieces[rookId].type == 'R') && coords.x == 4 && coords.y == 7
    && !whiteInCheck){
        if(!(chessPieces[id].hasMoved) && !(chessPieces[rookId].hasMoved) && !whiteInCheck){
            int64_t bit1 = 1;
            bit1 = bit1 << 60;
            int64_t bit2 = 1;
            bit2 = bit2 << 61;
            int64_t bit3 = 1;
            bit3 = bit3 << 62;
            if(!(blackDangerMap & bit1) && !(blackDangerMap & bit2) && !(blackDangerMap & bit3)){
                if((boardState[7][6] == '\0') && (boardState[7][5] == '\0')){
                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x+2) + '0';
                    stringCoords[3] = char(coords.y) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
                }
            }
        }
    }
    rookId = getIdatCoord({0,7});
    if(rookId != -1 && (chessPieces[rookId].type == 'R') && coords.x == 4 && coords.y == 7 &&
    !whiteInCheck){
        if(!(chessPieces[id].hasMoved) && !(chessPieces[rookId].hasMoved) && !whiteInCheck){
            int64_t bit1 = 1;
            bit1 = bit1 << 60;
            int64_t bit2 = 1;
            bit2 = bit2 << 59;
            int64_t bit3 = 1;
            bit3 = bit3 << 58;
            if(!(blackDangerMap & bit1) && !(blackDangerMap & bit2) && !(blackDangerMap & bit3)){
                if((boardState[7][1] == '\0') && (boardState[7][2] == '\0') && (boardState[7][3] == '\0')){
                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x-2) + '0';
                    stringCoords[3] = char(coords.y) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
                }
            }
        }
    }

}



void blackKingMove(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    //North Movement
    if(coords.y > 0){
        if((isupper(boardState[coords.y-1][coords.x])) || boardState[coords.y-1][coords.x] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x) + '0';
            stringCoords[3] = char(coords.y-1) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //South Movement
    if(coords.y < 7){
        if((isupper(boardState[coords.y+1][coords.x])) || boardState[coords.y+1][coords.x] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x) + '0';
            stringCoords[3] = char(coords.y+1) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //East Movement
    if(coords.x < 7){
        if((isupper(boardState[coords.y][coords.x+1])) || boardState[coords.y][coords.x+1] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x+1) + '0';
            stringCoords[3] = char(coords.y) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //West Movement
    if(coords.x > 0){
        if((isupper(boardState[coords.y][coords.x-1])) || boardState[coords.y][coords.x-1] == '\0'){
            std::string stringCoords = "    ";
            stringCoords[0] = char(coords.x) + '0';
            stringCoords[1] = char(coords.y) + '0';
            stringCoords[2] = char(coords.x-1) + '0';
            stringCoords[3] = char(coords.y) + '0';
            chessPieces[id].validMoves.push_back(stringCoords);
        }
    }
    //Diagonal Movement
    if(coords.x > 0){
        if(coords.y > 0){
            if((isupper(boardState[coords.y-1][coords.x-1])) || boardState[coords.y-1][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y < 7){
            if((isupper(boardState[coords.y+1][coords.x-1])) || boardState[coords.y+1][coords.x-1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }
    if(coords.x < 7){
        if(coords.y > 0){
            if((isupper(boardState[coords.y-1][coords.x+1])) || boardState[coords.y-1][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
        if(coords.y < 7){
            if((isupper(boardState[coords.y+1][coords.x+1])) || boardState[coords.y+1][coords.x+1] == '\0'){
                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);
            }
        }
    }

    std::cout << blackInCheck << " check black\n";

    //Castling
    int rookId = getIdatCoord({7,0});
    if(rookId != -1 && (chessPieces[rookId].type == 'r') && coords.x == 4 && coords.y == 0 &&
    !blackInCheck){
        if(!(chessPieces[id].hasMoved) && !(chessPieces[rookId].hasMoved) && !blackInCheck){
            int64_t bit1 = 1;
            bit1 = bit1 << 4;
            int64_t bit2 = 1;
            bit2 = bit2 << 5;
            int64_t bit3 = 1;
            bit3 = bit3 << 6;
            if(!(whiteDangerMap & bit1) && !(whiteDangerMap & bit2) && !(whiteDangerMap & bit3)){
                if((boardState[0][6] == '\0') && (boardState[0][5] == '\0')){
                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x+2) + '0';
                    stringCoords[3] = char(coords.y) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
                }
            }
        }
    }
    rookId = getIdatCoord({0,0});
    if(rookId != -1 && (chessPieces[rookId].type == 'r') && coords.x == 4 && coords.y == 0 &&
    !blackInCheck){
        if(!(chessPieces[id].hasMoved) && !(chessPieces[rookId].hasMoved) && !blackInCheck){
            int64_t bit1 = 1;
            bit1 = bit1 << 4;
            int64_t bit2 = 1;
            bit2 = bit2 << 3;
            int64_t bit3 = 1;
            bit3 = bit3 << 2;
            if(!(whiteDangerMap & bit1) && !(whiteDangerMap & bit2) && !(whiteDangerMap & bit3)){
                if((boardState[0][1] == '\0') && (boardState[0][2] == '\0') && (boardState[0][3] == '\0')){
                    std::string stringCoords = "    ";
                    stringCoords[0] = char(coords.x) + '0';
                    stringCoords[1] = char(coords.y) + '0';
                    stringCoords[2] = char(coords.x-2) + '0';
                    stringCoords[3] = char(coords.y) + '0';
                    chessPieces[id].validMoves.push_back(stringCoords);
                }
            }
        }
    }

}