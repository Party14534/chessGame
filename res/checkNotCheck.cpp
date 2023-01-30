#include "checkNotCheck.hpp"

bool checkNotCheck(std::vector<std::vector<char>> board, int id, sf::Vector2i prevCoords, sf::Vector2i newCoords){

    char type = chessPieces[id].type;

    std::vector<chessPiece> tempChessPieces = chessPieces;

    board[prevCoords.y][prevCoords.x] = '\0';
    
    if(board[newCoords.y][newCoords.x] != '\0'){
        int killId = getIdatCoord(newCoords);
        chessPieces.erase(chessPieces.begin()+killId);
        for(int i = killId; i < chessPieces.size(); i++) chessPieces[i].id--;
        board[newCoords.y][newCoords.x] = type;
        if(killId < id) chessPieces[id--].coords = newCoords;
        else chessPieces[id].coords = newCoords;
        /*std::cout << type << " killed " << newCoords.x << newCoords.y << "\n";
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j ++){
                if(board[i][j] == '\0') std::cout << "  ";
                else std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }*/
    }
    else {board[newCoords.y][newCoords.x] = type; chessPieces[id].coords = newCoords;}

    bool prevCheck;

    if(isupper(type)){
        prevCheck = whiteInCheck;
        checkInCheck(board, 1);
        bool newCheck = whiteInCheck;
        whiteInCheck = prevCheck;
        chessPieces = tempChessPieces;
        return newCheck;
    } else {
        prevCheck = blackInCheck;
        checkInCheck(board, 0);
        bool newCheck = blackInCheck;
        blackInCheck = prevCheck;
        chessPieces = tempChessPieces;
        return newCheck;
    }

}