#include "initializeBoard.hpp"

void initializeBoard(std::vector<std::vector<char>> &board, std::string boardState){

    // starting board rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

    int rowNum = 0;
    int offset = 0;

    for(int i = 0; i < boardState.length(); i++){

        if(rowNum >= 8) break;
        if(boardState[i] != '/' && offset < 8){

            if(isdigit(boardState[i])){

                for(int j = 0; j < (int(boardState[i]) - 48); j++){
                    board[rowNum][offset] = '\0';
                    offset++;
                }

            } else {
                board[rowNum][offset] = boardState[i];
                offset++;
            }

        } else {rowNum++; offset = 0;}

    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::cout << board[i][j] << " ";
            chessPiece newPiece(board[i][j], {j,i}, false);
        }
        std::cout << "\n";
    }

}