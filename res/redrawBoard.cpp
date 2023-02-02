#include "redrawBoard.hpp"

void redrawBoard(std::vector<std::vector<char>> &board){

    std::vector<std::vector<bool>> movedVec(8, std::vector<bool> (8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            int id = getIdatCoord({j,i});
            bool moved = chessPieces[id].hasMoved;
            if(id != -1){
                movedVec[i][j] = moved;
            }
        }
    }

    chessPieces = {};
    chessPieces.clear();
    std::cout << "\n";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == '\0') std::cout << "  ";
            else{
                if(movedVec[i][j]) std::cout << movedVec[i][j] << " ";
                else std::cout << board[i][j] << " ";
                chessPiece newPiece(board[i][j], {j,i}, movedVec[i][j]);
            }
        }
        std::cout << "\n";
    }
    movedVec.clear();
}