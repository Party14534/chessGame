#include "generateFen.hpp"

void generateFen(std::vector<std::vector<char>> board, int turn, int halfMove, int roundCount){

    boardFen = "";
    std::string boardState = "";

    int count = 0;
    for(int i = 0; i < 8; i++){
        count = 0;
        for(int j = 0; j < 8; j++){

            if(board[i][j] == '\0') count++;
            else{

                if(count > 0){
                    boardState.append(std::string(1,char(count) + 48));
                    count = 0;
                }
                boardState.append(std::string(1,board[i][j]));

            }
        }
        if(count > 0){
            boardState.append(std::string(1,char(count) + 48));
            count = 0;
        }
        if(i != 7) boardState.append(std::string(1,'/'));
        
    }

    std::string color;
    if(turn == 1){
        color = "b";
    } else color = "w";


    std::string castling = "";
    if(board[7][4] == 'K'){
        if(!(chessPieces[getIdatCoord({4,7})].hasMoved)){
            if(board[7][7] == 'R'){
                if(!(chessPieces[getIdatCoord({7,7})].hasMoved)){
                    castling.append("K");
                }
            }
            if(board[7][0] == 'R'){
                if(!(chessPieces[getIdatCoord({0,7})].hasMoved)){
                    castling.append("Q");
                }
            }
        }
    }
    if(board[0][4] == 'k'){
        if(!(chessPieces[getIdatCoord({4,0})].hasMoved)){
            if(board[0][7] == 'r'){
                if(!(chessPieces[getIdatCoord({7,0})].hasMoved)){
                    castling.append("k");
                }
            }
            if(board[0][0] == 'r'){
                if(!(chessPieces[getIdatCoord({0,0})].hasMoved)){
                    castling.append("q");
                }
            }
        }
    }

    std::string enpassant = "-";
    if(justPassant.x != -1){
        enpassant = "";
        enpassant.append(std::string(1, char(justPassant.x) + 97));
        if(turn == 1) enpassant.append(std::to_string(abs(justPassant.y) - 1));
        else enpassant.append(std::to_string(abs(justPassant.y) + 1));
    }

    boardFen = boardState + " " + color + " " + castling + " " + enpassant + " "
    + std::to_string(halfMove) + " " + std::to_string(roundCount);

}