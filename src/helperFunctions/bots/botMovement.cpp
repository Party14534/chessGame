#include "botMovement.hpp"

std::string  moveBot(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color, int choice){

    if(choice == 1){

        return randomBotMove(validMoves);

    }
    else if(choice == 2){

        return cccpBotMove(board, validMoves, color);

    }
    else if(choice == 3){

        return minBotMove(board, validMoves, color);

    }
    else if(choice == 4){

        return minCccpBotMove(board, validMoves, color);

    }

    return validMoves[0];

}